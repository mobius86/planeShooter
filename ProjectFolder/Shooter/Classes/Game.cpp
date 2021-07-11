#include <SFML/Graphics.hpp>
#include "Game.h"

const float Game::PlayerSpeed = 100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML Application"), mPlayer(), mTexture()
{
   if(!mTexture.loadFromFile("Resources/Textures/plane_fighter.png"))
   {
      //handleLoadingErro
   }

   mPlayer.setTexture(mTexture);
   mPlayer.setPosition(100.f, 100.f);

   mIsMovingUp = false;
   mIsMovingDown = false;
   mIsMovingRight = false;
   mIsMovingLeft = false;
}

void Game::run()
{
   sf::Clock clock;
   sf::Time timeSinceLastUpdate = sf::Time::Zero;

   while(mWindow.isOpen())
   {
      processEvents();
      timeSinceLastUpdate += clock.restart();
      while(timeSinceLastUpdate > TimePerFrame)
      {
         timeSinceLastUpdate -= TimePerFrame;
         processEvents();
         update(TimePerFrame);
      }
      render();
   }
}

void Game::processEvents()
{
   sf::Event event;

   while(mWindow.pollEvent(event))
   {
      switch(event.type)
      {
      case sf::Event::KeyPressed:
         HandlePlayerInput(event.key.code, KeyAction::keyPressed);
         break;
      case sf::Event::KeyReleased:
         HandlePlayerInput(event.key.code, KeyAction::keyReleased);
         break;
      case sf::Event::Closed:
         mWindow.close();
         break;
      }
   }
}

void Game::update(sf::Time deltaTime)
{
   sf::Vector2f movement(0.f, 0.f);

   if(mIsMovingUp)
      movement.y -= PlayerSpeed;
   if(mIsMovingDown)
      movement.y += PlayerSpeed;
   if(mIsMovingLeft)
      movement.x -= PlayerSpeed;
   if(mIsMovingRight)
      movement.x += PlayerSpeed;

   mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render()
{
   mWindow.clear();
   mWindow.draw(mPlayer);
   mWindow.display();
}

void Game::HandlePlayerInput(sf::Keyboard::Key key, KeyAction action)
{
   bool isPressed = (action == KeyAction::keyPressed);

   if(key == sf::Keyboard::Key::W || key == sf::Keyboard::Key::Up)
      mIsMovingUp = isPressed;
   else if(key == sf::Keyboard::Key::S || key == sf::Keyboard::Key::Down)
      mIsMovingDown = isPressed;
   else if(key == sf::Keyboard::Key::A || key == sf::Keyboard::Key::Left)
      mIsMovingLeft = isPressed;
   else if(key == sf::Keyboard::Key::D || key == sf::Keyboard::Key::Right)
      mIsMovingRight = isPressed;
}
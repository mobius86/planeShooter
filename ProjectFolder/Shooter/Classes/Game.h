#pragma once

enum class KeyAction
{
   keyPressed,
   keyReleased
};

class Game
{
public:
   Game();
   void run();

private:
   void processEvents();
   void update(sf::Time deltaTime);
   void render();
   void HandlePlayerInput(sf::Keyboard::Key key, KeyAction action);

   sf::RenderWindow mWindow;
   sf::Sprite mPlayer;
   sf::Texture mTexture;

   static const float   PlayerSpeed;
   static const sf::Time   TimePerFrame;

   bool mIsMovingUp;
   bool mIsMovingDown;
   bool mIsMovingRight;
   bool mIsMovingLeft;
};
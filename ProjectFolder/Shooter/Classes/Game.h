#pragma once

class Game
{
public:
   Game();
   void run();

private:
   void processEvents();
   void update();
   void render();

   sf::RenderWindow mWindow;
   sf::CircleShape mPlayer;
};
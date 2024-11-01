#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Snake.h"
#include <string.h>
#include <iostream>
#include <SDL_mixer.h>

class Game{

    public:
        void initialiseGame();
        void runGame();
        void exitGame();
        void drawGame();
        void endgame();
        void eatFruit();
    private:
       SDL_Window *window = nullptr;
       SDL_Renderer *renderer = nullptr;
       int WIDTH = 600, HEIGHT= 600, actuelTimer =0, afterTimer = 0, timer = 125;
       bool running = true;

       Snake snake;
       SDL_Texture *appleTexture = nullptr;
       SDL_Rect appleRect = {400, 320, 40, 40};

        SDL_Texture *scoreAppleTexture = nullptr;
        SDL_Texture *tropheeTexture = nullptr;
        SDL_Rect scoreAppleRect = {8, 17, 45, 45};
        SDL_Rect tropheeRect = {150, 17, 45, 45};
        int score = 0;
        TTF_Font *font;
        SDL_Surface *textSurface = nullptr;
        SDL_Texture *scoreTexture = nullptr;
        SDL_Rect scorerect;
        std:: string MaxScore ="50";
        SDL_Rect maxScorerect ;
        SDL_Surface *maxScoreSurface = nullptr;
        SDL_Texture *maxScoreTexture = nullptr;

        Mix_Chunk *topSound = nullptr;
        Mix_Chunk *downSound = nullptr;
        Mix_Chunk *rightSound = nullptr;
        Mix_Chunk *leftSound = nullptr;
        Mix_Chunk *eatAppleSound = nullptr;
        Mix_Chunk *deathSound = nullptr;
};

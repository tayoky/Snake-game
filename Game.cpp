#include "Game.h"

void Game:: initialiseGame(){

    SDL_Init(SDL_INIT_VIDEO);
    
    window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    snake.loadTexture(renderer);
    appleTexture = IMG_LoadTexture(renderer, "Graphics/pomme.png");

    TTF_Init();
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    scoreAppleTexture = IMG_LoadTexture(renderer, "Graphics/score_apple.png");
    tropheeTexture = IMG_LoadTexture(renderer, "Graphics/trophee.png");
    font = TTF_OpenFont("Font/PoetsenOne-Regular.ttf", 35);
    textSurface = TTF_RenderText_Blended(font, "tester",{255, 255, 255, 255});

    topSound = Mix_LoadWAV("Sound/Topsound.wav");
    downSound = Mix_LoadWAV("Sound/Downsound.wav");
    rightSound = Mix_LoadWAV("Sound/Rightsound.wav");
    leftSound = Mix_LoadWAV("Sound/Leftsound.wav");
    eatAppleSound = Mix_LoadWAV("Sound/Eatsound.wav");
    deathSound = Mix_LoadWAV("Sound/deadsound.wav");
}
void Game:: eatFruit(){
    if(snake.snake[0].x == appleRect.x && snake.snake[0].y == appleRect.y){
        SDL_Rect newrect = snake.snake[snake.snake.size()-1];
        snake.snake.push_back(newrect);
        appleRect.x = std::rand() %(14 -2)+1;
        appleRect.x *= 40;
        appleRect.y = std::rand() %(14 -4)+3;
        appleRect.y *= 40;
        score += 1;
        Mix_PlayChannelTimed(-1, eatAppleSound,0, 100);
    }
}
void Game:: endgame(){
    
    for(int i = 1; i<snake.snake.size(); i++){
        if(snake.snake[0].x == snake.snake[i].x && snake.snake[0].y == snake.snake[i].y){
            running = false;
            Mix_PlayChannelTimed(-1, deathSound,0, 300);
        
        }
    }
    if(snake.snake[0].x > 520 || snake.snake[0].x < 40 || snake.snake[0].y > 520 || snake.snake[0].y < 120){
        running = false;
        Mix_PlayChannelTimed(-1, deathSound,0, 300);
    }
}

void Game:: drawGame(){
   SDL_SetRenderDrawColor(renderer, 74, 117, 44, SDL_ALPHA_OPAQUE);
   SDL_RenderClear(renderer);

   SDL_SetRenderDrawColor(renderer, 87, 138, 52, SDL_ALPHA_OPAQUE);
   SDL_Rect firstrect = {0, 80, WIDTH, HEIGHT};
   SDL_RenderFillRect(renderer, &firstrect);

   SDL_SetRenderDrawColor(renderer, 175, 215, 70, SDL_ALPHA_OPAQUE);
   SDL_Rect secondtrect = {40, 120, WIDTH-80, HEIGHT-160};
   SDL_RenderFillRect(renderer, &secondtrect);

   for(int i = 3; i<14; i++){
        for(int j = 1; j<14; j++){
            if((j+i)%2 ==0){
                SDL_SetRenderDrawColor(renderer, 167, 209, 61, SDL_ALPHA_OPAQUE);
                SDL_Rect rect = {j*40, i*40, 40, 40};
                SDL_RenderFillRect(renderer, &rect);
            }
        }
   }
    SDL_RenderCopy(renderer, appleTexture, NULL, &appleRect);
    snake.display(renderer);


    SDL_RenderCopy(renderer, scoreAppleTexture, NULL, &scoreAppleRect);
    SDL_RenderCopy(renderer, tropheeTexture, NULL, &tropheeRect);

    std::string t = std::to_string(score);
    SDL_Rect scorerect = { 80, 20, textSurface->w,textSurface->h};
    textSurface = TTF_RenderText_Solid(font, t.c_str(),{255, 255, 255, 255});
    scoreTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_RenderCopy(renderer, scoreTexture,NULL,&scorerect);
    
    SDL_Rect maxScorerect = { 210, 14, 40,50};
    maxScoreSurface = TTF_RenderText_Blended(font, MaxScore.c_str(),{255, 255, 255, 255});
    maxScoreTexture = SDL_CreateTextureFromSurface(renderer, maxScoreSurface);
    SDL_RenderCopy(renderer, maxScoreTexture,NULL,&maxScorerect);
    SDL_RenderPresent(renderer);
}

void Game:: runGame(){
    while(running){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym){
                        case SDLK_UP:
                            snake.direction[0] = 0;
                            snake.direction[1] = -40;
                            Mix_PlayChannelTimed(-1, topSound,0, 100);
                            break;
                        case SDLK_DOWN:
                            snake.direction[0] = 0;
                            snake.direction[1] = 40;
                            Mix_PlayChannelTimed(-1, downSound,0, 100);
                            break;
                        case SDLK_RIGHT:
                            snake.direction[0] = 40;
                            snake.direction[1] = 0;
                            Mix_PlayChannelTimed(-1, rightSound,0, 100);
                            break;
                        case SDLK_LEFT:
                            snake.direction[0] = -40;
                            snake.direction[1] = 0;
                            Mix_PlayChannelTimed(-1, leftSound,0, 100);
                            break;

                    }
                break;
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
        drawGame();
        eatFruit();
        snake.moveSnake();
        endgame();
        actuelTimer = SDL_GetTicks();
        if(actuelTimer - afterTimer < timer){
            SDL_Delay(timer - (actuelTimer - afterTimer));
        }
        afterTimer = SDL_GetTicks();
    }
}

void Game:: exitGame(){
    snake.destructSnake();
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(appleTexture);
    SDL_FreeSurface(textSurface);
    SDL_FreeSurface(maxScoreSurface);
    SDL_DestroyTexture(scoreAppleTexture);
    SDL_DestroyTexture(scoreTexture);
    SDL_DestroyTexture(tropheeTexture);
    SDL_DestroyTexture(maxScoreTexture);
    TTF_CloseFont(font);
    Mix_FreeChunk(eatAppleSound);
    Mix_FreeChunk(deathSound);
    Mix_FreeChunk(topSound);
    Mix_FreeChunk(downSound);
    Mix_FreeChunk(rightSound);
    Mix_FreeChunk(leftSound);
    Mix_CloseAudio();
    SDL_Quit();
}
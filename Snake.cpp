#include "Snake.h"

void Snake::loadTexture(SDL_Renderer *renderer){
    body_bl = IMG_LoadTexture(renderer, "Graphics/body_bl.png");
    body_br = IMG_LoadTexture(renderer, "Graphics/body_br.png");
    body_horizontal = IMG_LoadTexture(renderer, "Graphics/body_horizontal.png");
    body_tl = IMG_LoadTexture(renderer, "Graphics/body_tl.png");
    body_tr = IMG_LoadTexture(renderer, "Graphics/body_tr.png");
    body_vertical = IMG_LoadTexture(renderer, "Graphics/body_vertical.png");
    head_down = IMG_LoadTexture(renderer, "Graphics/head_down.png");
    head_up = IMG_LoadTexture(renderer, "Graphics/head_up.png");
    head_right = IMG_LoadTexture(renderer, "Graphics/head_right.png");
    head_left = IMG_LoadTexture(renderer, "Graphics/head_left.png");
    tail_down = IMG_LoadTexture(renderer, "Graphics/tail_down.png");
    tail_up = IMG_LoadTexture(renderer, "Graphics/tail_up.png");
    tail_right = IMG_LoadTexture(renderer, "Graphics/tail_right.png");
    tail_left = IMG_LoadTexture(renderer, "Graphics/tail_left.png");

}
void Snake:: display(SDL_Renderer *renderer){
    for(int i=0; i<= snake.size()-1; i++){
        if(i == 0){
                if(snake[i].x > snake[i+1].x){
                    SDL_RenderCopy(renderer, head_right, NULL, &snake[i]);
                }
                else if(snake[i].x < snake[i+1].x){
                    SDL_RenderCopy(renderer, head_left, NULL, &snake[i]);
                }
                else if(snake[i].y < snake[i+1].y){
                    SDL_RenderCopy(renderer, head_up, NULL, &snake[i]);
                }
                else{
                    SDL_RenderCopy(renderer, head_down, NULL, &snake[i]);
                }
            }
        else if(i == snake.size()-1){
                if(snake[i].y > snake[i-1].y) {
                    SDL_RenderCopy(renderer, tail_down, NULL, &snake[i]);
                }
                else if(snake[i].y < snake[i-1].y){
                    SDL_RenderCopy(renderer, tail_up, NULL, &snake[i]);
                }
                else if(snake[i].x > snake[i-1].x){
                    SDL_RenderCopy(renderer, tail_right, NULL, &snake[i]);
                }
                else{
                    SDL_RenderCopy(renderer, tail_left, NULL, &snake[i]);
                }
            }

        else{
            
            int x_previous = (snake[i-1].x - snake[i].x);
            int y_previous = (snake[i-1].y - snake[i].y);
            int x_next = (snake[i].x - snake[i+1].x);
            int y_next = (snake[i].y - snake[i+1].y);
            
            if(snake[i+1].x == snake[i-1].x) {
                    SDL_RenderCopy(renderer, body_vertical, NULL, &snake[i]);
            }
            else if(snake[i+1].y == snake[i-1].y){
                    SDL_RenderCopy(renderer, body_horizontal, NULL, &snake[i]);
            }
            else{
                if (x_previous == -40 && y_next == 40 || y_previous == -40 && x_next == 40){
                    SDL_RenderCopy(renderer, body_tl, NULL, &snake[i]);
                }
                else if( x_previous == -40 && y_next == -40 || y_previous == 40 && x_next == 40){
                    SDL_RenderCopy(renderer, body_bl, NULL, &snake[i]);
                }
                else if(x_previous == 40 && y_next == 40 || y_previous == -40 && x_next == -40){
                    SDL_RenderCopy(renderer, body_tr, NULL, &snake[i]);
                }
                else if(x_previous == 40 && y_next == -40 || y_previous == 40 && x_next == -40){
                    SDL_RenderCopy(renderer, body_br, NULL, &snake[i]);
                }
            }
        }
    }
}
void Snake:: moveSnake(){
    for(int i = snake.size()-1; i>0; i--){
        snake[i].x = snake[i-1].x;
        snake[i].y = snake[i-1].y;
    }
    snake[0].x += direction[0];
    snake[0].y += direction[1];
}

void Snake:: destructSnake(){
    SDL_DestroyTexture(head_down);
    SDL_DestroyTexture(head_left);
    SDL_DestroyTexture(head_right);
    SDL_DestroyTexture(head_up);
    SDL_DestroyTexture(body_horizontal);
    SDL_DestroyTexture(body_vertical);
    SDL_DestroyTexture(body_bl);
    SDL_DestroyTexture(body_br);
    SDL_DestroyTexture(body_tl);
    SDL_DestroyTexture(body_tr);
    SDL_DestroyTexture(tail_down);
    SDL_DestroyTexture(tail_left);
    SDL_DestroyTexture(tail_right);
    SDL_DestroyTexture(tail_up);
}

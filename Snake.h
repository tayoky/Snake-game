#include <SDL.h>
#include <SDL_image.h>
#include <vector>

class Snake{
    public:
        void loadTexture(SDL_Renderer *renderer);
        void display(SDL_Renderer *renderer);
        void destructSnake();
        void moveSnake();
        SDL_Texture *body_bl = nullptr;
        SDL_Texture *body_br = nullptr;
        SDL_Texture *body_horizontal = nullptr;
        SDL_Texture *body_tl = nullptr;
        SDL_Texture *body_tr = nullptr;
        SDL_Texture *body_vertical = nullptr;
        SDL_Texture *head_down = nullptr;
        SDL_Texture *head_up = nullptr;
        SDL_Texture *head_right = nullptr;
        SDL_Texture *head_left = nullptr;
        SDL_Texture *tail_down = nullptr;
        SDL_Texture *tail_up = nullptr;
        SDL_Texture *tail_right = nullptr;
        SDL_Texture *tail_left = nullptr;
        std::vector <SDL_Rect> snake = {{120, 320, 40, 40}, {80, 320, 40, 40}, {40, 320, 40, 40}};
        int direction[2] = {40, 0};
};
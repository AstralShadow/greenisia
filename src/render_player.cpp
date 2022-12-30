#include "global.hpp"
#include "player.hpp"
#include "camera.hpp"

#include <SDL2/SDL.h>


void render_player()
{
    SDL_Rect player_area {
        player.pos.x - camera.x,
        player.pos.y - camera.y,
        player.size.x,
        player.size.y
    };

    SDL_SetRenderDrawColor(rnd, 0, 255, 0, 255);
    SDL_RenderFillRect(rnd, &player_area);
}

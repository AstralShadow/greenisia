#include "global.hpp"
#include "player.hpp"
#include "camera.hpp"
#include "textures.hpp"

#include <SDL2/SDL.h>


void render_player()
{
    SDL_Point offset, tex_size;
    auto texture = get_player_sprite(&offset, &tex_size);
    SDL_Rect sprite_area {
        player.pos.x + offset.x - camera.x,
        player.pos.y + offset.y - camera.y,
        tex_size.x,
        tex_size.y
    };

    float delta_x = player.pos.x - player.old_pos.x;
    if(delta_x < 0)
        SDL_RenderCopyEx(rnd, texture,
                         nullptr, &sprite_area,
                         0, nullptr,
                         SDL_FLIP_HORIZONTAL);
    else
        SDL_RenderCopy(rnd, texture,
                       nullptr, &sprite_area);
    

    if(SHOW_DEBUG_GRID) { // Player hitbox
        SDL_Rect player_area {
            player.pos.x - camera.x,
            player.pos.y - camera.y,
            player.size.x,
            player.size.y
        };

        SDL_SetRenderDrawColor(rnd, 0, 255, 0, 255);
        SDL_RenderDrawRect(rnd, &player_area);
    }
}

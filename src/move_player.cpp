#include "global.hpp"
#include <cstdint>
#include <SDL2/SDL_keyboard.h>
#include "player.hpp"
#include "map.hpp"

static float velocity_limit = 1500;

static bool player_foothold();


void move_player(int progress)
{
    const uint8_t* keyboard = SDL_GetKeyboardState(nullptr);

    if(keyboard[SDL_SCANCODE_A] || keyboard[SDL_SCANCODE_LEFT])
        player.pos.x -= player.speed * progress / 1000.0f;

    if(keyboard[SDL_SCANCODE_D] || keyboard[SDL_SCANCODE_RIGHT])
        player.pos.x += player.speed * progress / 1000.0f;


    player.velocity += player.mass * progress / 1000.0f;
    if(player.velocity > velocity_limit)
        player.velocity = velocity_limit;
    player.pos.y += player.velocity * progress / 1000.0f;


    if(player_foothold()) {
        player.velocity = 0;
        int player_bottom = player.pos.y + player.size.y;
        int foothold_block = player_bottom / block_size.y;
        player_bottom = foothold_block * block_size.y;
        player.pos.y = player_bottom - player.size.y;


        if(keyboard[SDL_SCANCODE_W] || keyboard[SDL_SCANCODE_UP])
            player.velocity = -player.jump_power;
    }
}

bool player_foothold()
{
    for(int x = 0; x < map.width; x++)
    for(int y = 0; y < map.height; y++)
    {
        Block block = map.at(x, y);
        if(block == B_AIR)
            continue;

        SDL_Rect p_box {
            player.pos.x,
            player.pos.y,
            player.size.x,
            player.size.y
        };

        SDL_Rect b_box {
            x * block_size.x,
            y * block_size.y,
            block_size.x,
            block_size.y
        };

        if(SDL_HasIntersection(&p_box, &b_box))
            return true;
    }

    return false;
}

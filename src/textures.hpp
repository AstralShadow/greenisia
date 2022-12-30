#ifndef INCLUDE_TEXTURES_HPP
#define INCLUDE_TEXTURES_HPP

#include <vector>
#include <string>

using std::vector;
using std::string;
struct SDL_Texture;


void load_textures(vector<string> const& paths);
void clear_textures();

SDL_Texture* get_texture(string const& path);


#endif // INCLUDE_TEXTURES_HPP

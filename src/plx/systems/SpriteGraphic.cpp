#include "SpriteGraphic.h"

std::map<std::string, SDL_Texture*> SpriteGraphic::dictionary;

void SpriteGraphic::Render(SDL_Renderer* renderer) {
    SDL_Texture* t;

    if (dictionary.count(fileName)) {
        t = dictionary.at(fileName);
    } else {
        SDL_Surface* s = IMG_Load(fileName.c_str());

        if (!s) {
            throw std::invalid_argument("Sprite \"" + fileName + "\" not found...");
        }

        t = SDL_CreateTextureFromSurface(renderer, s);
        SDL_FreeSurface(s);

        dictionary.insert({ fileName,t });
        std::cout << "Cached sprite \"" << fileName << "\"\n";
    }

    SDL_Rect r = { (int)position.x, (int)position.y, (int)width, (int)height };

    SDL_RenderCopy(renderer, t, NULL, &r);
}
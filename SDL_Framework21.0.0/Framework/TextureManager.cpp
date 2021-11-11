#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* fileName, SDL_Renderer* renderer)
{
    SDL_Surface* tempSurface = IMG_Load(fileName);



    if (tempSurface == nullptr) printf("%s\n", SDL_GetError());
    if (tempSurface == nullptr) {
        std::cerr << "Can't open the image" << std::endl;
        return nullptr;
    }
    else {
        
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
        SDL_FreeSurface(tempSurface);

        return texture;

    }
    

}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, texture, &src, &dest);


}

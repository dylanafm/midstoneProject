#include "TextureManager.h"

TextureManager::TextureManager()
{
    mTexture = nullptr;
    ImageH = 0;
    ImageW = 0;
}

TextureManager::~TextureManager()
{
    free();
    delete mTexture;
}
bool TextureManager::loadFromFile(std::string path, SDL_Renderer* r)
{
    //Get rid of preexisting texture
    free();

    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(r, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        else
        {
            //Get image dimensions
            ImageW = loadedSurface->w;
            ImageH = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    //Return success
    mTexture = newTexture;
    return mTexture != NULL;
}
void TextureManager::free()
{
    if (mTexture != NULL)
    {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        ImageH = 0;
        ImageW = 0;
    }
}
SDL_Texture* TextureManager::LoadTexture(const char* fileName, SDL_Renderer* renderer)
{
    SDL_Surface* tempSurface = IMG_Load(fileName);



    if (tempSurface == nullptr) printf("%s\n", SDL_GetError());
    if (tempSurface == nullptr) {
        std::cerr << "Can't open the image" << std::endl;
        return nullptr;
    }
    else {
        
        SDL_Texture* mTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
        SDL_FreeSurface(tempSurface);

        return mTexture;

    }
    

}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, texture, &src, &dest);


}

void TextureManager::render(SDL_Renderer* render, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
    SDL_Rect renderQuad = { x, y, ImageW, ImageH };

    if (clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    SDL_RenderCopyEx(render, mTexture, clip, &renderQuad, angle, center, flip);



}

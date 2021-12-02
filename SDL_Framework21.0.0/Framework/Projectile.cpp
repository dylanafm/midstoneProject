#include "Projectile.h"
#include "TextureManager.h"

Projectile::Projectile(SDL_Rect body_, Vec3 vel_, SDL_Renderer* renderer, const char* path, float radius_) :
	Enemy(body_, vel_, 1.0f, renderer, path, radius_){
}

Projectile::~Projectile()
{
}


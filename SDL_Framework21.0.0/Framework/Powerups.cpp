#include "Powerups.h"
Powerups::Powerups(SDL_Rect box_, float scrollSpeed_, const char* path, SDL_Renderer* renderer)
{	
	box = box_;
	pos = Vec3(box.x, box.y, 0.0f);
	
	scrollSpeed = scrollSpeed_;
	tex = TextureManager::LoadTexture(path, renderer);
	radiusInPixels = box.w / 2;
}

Powerups::~Powerups()
{
	SDL_DestroyTexture(tex);
}

void Powerups::Render(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, tex, nullptr, &box);

}

void Powerups::Scroll()
{
	
	pos.x = pos.x - scrollSpeed;
}

bool Powerups::checkCollide(harpoonHarry* harry)
{
	Vec3 powerupCenter = Vec3(pos.x + box.w / 2.0f, pos.y + box.h / 2.0f, 0.0f);
	Vec3 harryCenter = Vec3(harry->pos.x + harry->harryBox.w / 2.0f, harry->pos.y + harry->harryBox.h / 2.0f, 0.0f);

	if (((powerupCenter.x - harryCenter.x) * (powerupCenter.x - harryCenter.x) +
		(harryCenter.y - powerupCenter.y) * (harryCenter.y - powerupCenter.y)) <=
		((radiusInPixels + harry->radiusInPixels) * (radiusInPixels + harry->radiusInPixels))) {
		return true;
	}

	return false;
}

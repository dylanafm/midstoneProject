#include "MGHarpoon.h"
#include "ShieldPU.h"

MGHarpoon::MGHarpoon(SDL_Rect box_, float scrollSpeed_, const char* path, SDL_Renderer* renderer)
{
	pickup = new Sfx("SFX/MGH.wav", 10);
	box = box_;
	pos = Vec3(box.x, box.y, 0.0f);

	scrollSpeed = scrollSpeed_;
	tex = TextureManager::LoadTexture(path, renderer);
	radiusInPixels = box.w / 2;
}

MGHarpoon::~MGHarpoon()
{
	delete pickup;
	SDL_DestroyTexture(tex);
}

void MGHarpoon::RapidFire(HarpoonHarry* harry)
{
	if (checkCollide(harry)) {

		pickup->playSFX();
		harry->rapidFire = true;
		harry->gunTimeRemain = 5.0f;
	}

}

void MGHarpoon::Render(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, tex, nullptr, &box);

}

void MGHarpoon::Scroll()
{
	box.x = box.x - scrollSpeed;

}

bool MGHarpoon::checkCollide(HarpoonHarry* harry)
{
	Vec3 powerupCenter = Vec3(box.x + box.w / 2.0f, box.y + box.h / 2.0f, 0.0f);
	Vec3 harryCenter = Vec3(harry->pos.x + harry->harryBox.w / 2.0f, harry->pos.y + harry->harryBox.h / 2.0f, 0.0f);

	if (((powerupCenter.x - harryCenter.x) * (powerupCenter.x - harryCenter.x) +
		(harryCenter.y - powerupCenter.y) * (harryCenter.y - powerupCenter.y)) <=
		((radiusInPixels + harry->radiusInPixels) * (radiusInPixels + harry->radiusInPixels))) {
		return true;
	}

	return false;
}

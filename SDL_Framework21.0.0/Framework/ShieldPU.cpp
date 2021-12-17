#include "ShieldPU.h"
#include "Powerups.h"

ShieldPU::ShieldPU(SDL_Rect box_, float scrollSpeed_, const char* path, SDL_Renderer* renderer)
{
	pickup = new sfx("SFX/shield.wav", 10);
	box = box_;
	pos = Vec3(box.x, box.y, 0.0f);

	scrollSpeed = scrollSpeed_;
	tex = TextureManager::LoadTexture(path, renderer);
	radiusInPixels = box.w / 2;
}

ShieldPU::~ShieldPU()
{
}

void ShieldPU::Protect(harpoonHarry* harry)
{
	if (checkCollide(harry)) {

		pickup->playSFX();
		harry->Shielded = true;
		harry->timeRemaining = 5.0f;
	}
	
}

void ShieldPU::Render(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, tex, nullptr, &box);

}

void ShieldPU::Scroll()
{
	box.x = box.x - scrollSpeed;

}

bool ShieldPU::checkCollide(harpoonHarry* harry)
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

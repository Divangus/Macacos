#ifndef __MODULE_ELEMENTS_H__
#define __MODULE_ELEMENTS_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;

class ModuleElements : public Module {
public:
	ModuleElements(bool startEnabled);

	~ModuleElements();

	// Called when the module is activated
	// Loads the necessary textures for the player
	bool Start() override;

	// Called at the middle of the application loop
	// Processes new input and handles player movement
	update_status Update() override;

	// Called at the end of the application loop
	// Performs the render call of the player sprite
	update_status PostUpdate() override;

private:
	SDL_Texture* texture = nullptr;

	SDL_Texture* FireTexture = nullptr;

	iPoint position;

	Animation Fire;

	bool destroyed = false;

	uint destroyedCountdown = 120;

	Animation* currentAnimation = nullptr;

	/*uint laserFx = 0;
	uint explosionFx = 0;*/
};

#endif
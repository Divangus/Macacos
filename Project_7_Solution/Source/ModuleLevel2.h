#ifndef __MODULE_LEVEL2_H__
#define __MODULE_LEVEL2_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;

class ModuleLevel2 :public Module {
public:
	ModuleLevel2(bool startEnabled);

	~ModuleLevel2();

	bool Start()override;

	update_status Update()override;

	update_status PostUpdate()override;

	bool CleanUp() override;

	iPoint position;


private:
	int speed = 1;

	SDL_Texture* BackgroundLevel2Texture = nullptr;

	SDL_Texture* HudTexture = nullptr;

	SDL_Texture* SmokeTexture = nullptr;

	SDL_Texture* AprilTexture = nullptr;

	Animation BackgroundLevel2, hud, Smoke,April;

	uint AprilHelpMeFx = 0;
};
#endif
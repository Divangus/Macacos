#ifndef __MODULE_LEVEL2_H__
#define __MODULE_LEVEL2_H__

#include "Module.h"
#include "Animation.h"
#include "Path.h"

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

	SDL_Texture* BackgroundLevel2 = nullptr;
};
#endif
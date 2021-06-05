#ifndef __MODULE_SCENE_H__
#define __MODULE_SCENE_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class ModuleScene : public Module
{
public:
	//Constructor
	ModuleScene(bool startEnabled);

	//Destructor
	~ModuleScene();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	update_status Update() override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	update_status PostUpdate() override;

	bool CleanUp() override;

public:
	
	// The scene sprite sheet loaded into an SDL_Texture
	SDL_Texture* bgTexture = nullptr;

	SDL_Texture* hudTexture = nullptr;

	//SDL_Texture* Fire_Texture = nullptr;

	SDL_Texture* Elements_Texture = nullptr;

	SDL_Texture* Quotes_Texture = nullptr;

	Animation Fire,
		Door1,
		Door2,
		Door3,
		DoorFire,
		lift,
		liftFire,
		AttackQuote,
		Ball,
		hud;

	uint DoorBrake = 0;
	uint OpenLift = 0;
	uint AprilScreamFx = 0;
};

#endif
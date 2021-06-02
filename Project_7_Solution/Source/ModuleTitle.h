#ifndef __MODULE_TITLE_H__
#define __MODULE_TITLE_H__

#include "Module.h"
#include "Animation.h"
#include "Path.h"

struct SDL_Texture;

class ModuleTitle : public Module
{
public:
	//Constructor
	ModuleTitle(bool startEnabled);

	//Destructor
	~ModuleTitle();

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

	bool screenupdate = false;
	// The scene sprite sheet loaded into an SDL_Texture
	SDL_Texture* bgTexture;
	SDL_Texture* EnterCoinsTitleTexture;
	SDL_Texture* PressEnterTexture;
	SDL_Texture* HudTexture;
	SDL_Texture* TurtleTexture;
	SDL_Texture* TitleTexture;
	SDL_Texture* InsertCoinsTexture = nullptr;
	 
	Path PathTMNTRed, PathTMNTGreen;

	Animation TitleEnterCoin,TitleScreen,PressEnter, InsertCoins,Hud, TurtleSmile, tmntgreen;
	Animation tmntred;
	int coins = 0;

	fPoint positionTMNTred, spawnPosRed;

	uint MusicIntro = 0;
	uint MusicEnterCoinScreen = 0;

};

#endif
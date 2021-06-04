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
	SDL_Texture* bgTexture = nullptr;
	SDL_Texture* EnterCoinsTitleTexture = nullptr;
	SDL_Texture* PressEnterTexture = nullptr;
	SDL_Texture* HudTexture = nullptr;
	SDL_Texture* TurtleTexture = nullptr;
	SDL_Texture* TitleTexture = nullptr;
	SDL_Texture* InsertCoinsTexture = nullptr;
	SDL_Texture* CoinsTexture = nullptr;
	 
	Path PathTMNTRed;

	Animation coin1, coin2, coin3, coin4, coin5, coin6, coin7, coin8, coin9;
	Animation TitleEnterCoin,TitleScreen,PressEnter, InsertCoins,Hud, TurtleSmile, tmntgreen;
	Animation tmntred;
	int coins = 0;
	int Blue = 0;

	Animation AnimTitle;



	fPoint positionTMNTred, spawnPosRed;

	uint MusicIntro = 0;
	uint MusicEnterCoinScreen = 0;

};

#endif
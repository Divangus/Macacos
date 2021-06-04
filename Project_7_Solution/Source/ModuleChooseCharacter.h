#ifndef __MODULE_CHOOSE_CHARACTER_H__
#define __MODULE_CHOOSE_CHARACTER_H__

#include "Module.h"
#include "Animation.h"
#include "Path.h"

struct SDL_Texture;

class ModuleChooseCharacter : public Module {
public:
	ModuleChooseCharacter(bool startEnabled);

	~ModuleChooseCharacter();

	bool Start()override;

	update_status Update()override;

	update_status PostUpdate()override;

	bool CleanUp() override;

public:

	SDL_Texture* EnterCoinsTitleTexture = nullptr;
	SDL_Texture* PressEnterTexture = nullptr;
	SDL_Texture* HudTexture = nullptr;
	SDL_Texture* TurtleTexture = nullptr;
	SDL_Texture* TitleTexture = nullptr;
	SDL_Texture* InsertCoinsTexture = nullptr;
	SDL_Texture* CoinsTexture = nullptr;

	Path PathTMNTRed;

	Animation coin1, coin2, coin3, coin4, coin5, coin6, coin7, coin8, coin9;
	Animation TitleEnterCoin, TitleScreen, PressEnter, InsertCoins, Hud, TurtleSmile, tmntgreen;
	Animation tmntred;
	int coins = 0;
	int Blue = 0;



};
#endif
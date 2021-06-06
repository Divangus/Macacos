#include "ModuleChooseCharacter.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL_Scancode.h"

ModuleChooseCharacter::ModuleChooseCharacter(bool startEnabled):Module(startEnabled) {
	TitleEnterCoin.PushBack({ 0,0,304,222 });
	TitleEnterCoin.loop = false;

	TurtleSmile.PushBack({ 9,10,25,21 });
	TurtleSmile.PushBack({ 40,9,25,21 });
	TurtleSmile.loop = true;
	TurtleSmile.speed = 0.05f;

	Hud.PushBack({ 0,0,304,222 });
	Hud.loop = false;

	TitleScreen.PushBack({ 0,0,304,222 });
	TitleScreen.loop = false;

	PressEnter.PushBack({ 0,0,80,22 });
	PressEnter.PushBack({ 0,0,0,0 });
	PressEnter.loop = true;
	PressEnter.speed = 0.08f;

	InsertCoins.PushBack({ 4,1,67,19 });
	InsertCoins.PushBack({ 82,26,67,19 });
	InsertCoins.PushBack({ 82,1,67,19 });
	InsertCoins.PushBack({ 152,1,67,19 });
	InsertCoins.PushBack({ 3,26,67,19 });
	InsertCoins.loop = true;
	InsertCoins.speed = 0.15f;


	coin1.PushBack({ 6,4,6,13 });
	coin1.loop = false;

	coin2.PushBack({ 11,4,9,13 });
	coin2.loop = false;

	coin3.PushBack({ 20,4,9,13 });
	coin3.loop = false;

	coin4.PushBack({ 28,4,9,13 });
	coin4.loop = false;

	coin5.PushBack({ 36,4,9,13 });
	coin5.loop = false;

	coin6.PushBack({ 44,4,9,13 });
	coin6.loop = false;

	coin7.PushBack({ 52,4,9,13 });
	coin7.loop = false;

	coin8.PushBack({ 60,4,9,13 });
	coin8.loop = false;

	coin9.PushBack({ 70,4,9,13 });
	coin9.loop = false;

	LifeBar10.PushBack({7,10,21,8});

	LifeBar9.PushBack({30,10,19,8});

	LifeBar8.PushBack({51,10,17,8});

	LifeBar7.PushBack({70,10,15,8});

	LifeBar6.PushBack({87,10,13,8});

	LifeBar5.PushBack({102,10,11,8});

	LifeBar4.PushBack({115,10,9,8});

	LifeBar3.PushBack({126,10,7,8});

	LifeBar2.PushBack({135,10,5,8});

	LifeBar1.PushBack({142,10,3,8});

}

ModuleChooseCharacter::~ModuleChooseCharacter() {

}

bool ModuleChooseCharacter::Start() {
	LOG("Loading background assets");

	bool ret = true;
	EnterCoinsTitleTexture = App->textures->Load("Assets/IntroCoin.png");
	PressEnterTexture = App->textures->Load("Assets/PressStart.png");
	InsertCoinsTexture = App->textures->Load("Assets/InsertCoins.png");
	HudTexture = App->textures->Load("Assets/hud.png");
	TitleTexture = App->textures->Load("Assets/IntroScreen.png");
	TurtleTexture = App->textures->Load("Assets/TurtleSmile.png");
	CoinsTexture = App->textures->Load("Assets/coins.png");
	LifeBarTexture = App->textures->Load("Assets/lifeBar.png");
	App->audio->PlayMusic("Assets/Fx/SelectionThemeMusic.ogg", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;


	return ret;
}

update_status ModuleChooseCharacter::Update() {
	// Get gamepad info
	GamePad& pad = App->input->pads[0];
	if (coins > 0) {
		PressEnter.Update();
	}

	InsertCoins.Update();
	TurtleSmile.Update();
	App->render->Blit(EnterCoinsTitleTexture, 0, 0, &(TitleEnterCoin.GetCurrentFrame()), 1);

	if (App->input->keys[SDL_SCANCODE_LSHIFT] == KEY_STATE::KEY_DOWN||pad.y) {
		coins++;
		LifeBar10.Update();
		Blue = 10;

	}
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && coins > 0||pad.a && coins>0)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
	}
	
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleChooseCharacter::PostUpdate() {

	// Draw everything --------------------------------------
	if (coins > 0) {
		App->render->Blit(PressEnterTexture, 5, 35, &(PressEnter.GetCurrentFrame()), 1);
		App->render->Blit(InsertCoinsTexture, 83, 18, &(InsertCoins.GetCurrentFrame()), 0);
		App->render->Blit(InsertCoinsTexture, 151, 18, &(InsertCoins.GetCurrentFrame()), 0);
		App->render->Blit(InsertCoinsTexture, 219, 18, &(InsertCoins.GetCurrentFrame()), 0);
		App->render->Blit(HudTexture, 0, 0, &(Hud.GetCurrentFrame()), 0);
		App->render->Blit(LifeBarTexture, 50, 20, &(LifeBar10.GetCurrentFrame()), 1);
		
	}
	if (coins == 0) {
		App->render->Blit(InsertCoinsTexture, 83, 18, &(InsertCoins.GetCurrentFrame()), 0);
		App->render->Blit(InsertCoinsTexture, 151, 18, &(InsertCoins.GetCurrentFrame()), 0);
		App->render->Blit(InsertCoinsTexture, 219, 18, &(InsertCoins.GetCurrentFrame()), 0);
		App->render->Blit(HudTexture, 0, 0, &(Hud.GetCurrentFrame()), 0);
		App->render->Blit(TurtleTexture, 50, 20, &(TurtleSmile.GetCurrentFrame()), 1);
	}

	if (coins == 1) {
		App->render->Blit(CoinsTexture, 30, 20, &(coin1.GetCurrentFrame()), 0);
	}
	if (coins == 2) {
		App->render->Blit(CoinsTexture, 30, 20, &(coin2.GetCurrentFrame()), 0);
	}
	if (coins == 3) {
		App->render->Blit(CoinsTexture, 30, 20, &(coin3.GetCurrentFrame()), 0);
	}
	if (coins == 4) {
		App->render->Blit(CoinsTexture, 30, 20, &(coin4.GetCurrentFrame()), 0);
	}
	if (coins == 5) {
		App->render->Blit(CoinsTexture, 30, 20, &(coin5.GetCurrentFrame()), 0);
	}
	if (coins == 6) {
		App->render->Blit(CoinsTexture, 30, 20, &(coin6.GetCurrentFrame()), 0);
	}
	if (coins == 7) {
		App->render->Blit(CoinsTexture, 30, 20, &(coin7.GetCurrentFrame()), 0);
	}
	if (coins == 8) {
		App->render->Blit(CoinsTexture, 30, 20, &(coin8.GetCurrentFrame()), 0);
	}
	if (coins == 9) {
		App->render->Blit(CoinsTexture, 30, 20, &(coin9.GetCurrentFrame()), 0);
	}


	return update_status::UPDATE_CONTINUE;

}

bool ModuleChooseCharacter::CleanUp() {

	LOG("Clearing Over");


	App->textures->Unload(EnterCoinsTitleTexture);
	App->textures->Unload(PressEnterTexture);
	App->textures->Unload(InsertCoinsTexture);
	App->textures->Unload(HudTexture);
	App->textures->Unload(TurtleTexture);
	App->textures->Unload(TitleTexture);


	return true;
}
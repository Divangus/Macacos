#include "ModuleTitle.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL_Scancode.h"


ModuleTitle::ModuleTitle(bool startEnabled) : Module(startEnabled)
{
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

	PressEnter.PushBack({0,0,80,22});
	PressEnter.PushBack({0,0,0,0});
	PressEnter.loop = true;
	PressEnter.speed = 0.08f;

	InsertCoins.PushBack({ 4,1,67,19 });
	InsertCoins.PushBack({ 82,26,67,19 });
	InsertCoins.PushBack({ 82,1,67,19 });
	InsertCoins.PushBack({ 152,1,67,19 });
	InsertCoins.PushBack({ 3,26,67,19 });
	InsertCoins.loop = true;
	InsertCoins.speed = 0.15f;
}

ModuleTitle::~ModuleTitle()
{

}

// Load assets
bool ModuleTitle::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Title_Screen.png");
	EnterCoinsTitleTexture = App->textures->Load("Assets/IntroCoin.png");
	PressEnterTexture = App->textures->Load("Assets/PressStart.png");
	InsertCoinsTexture = App->textures->Load("Assets/InsertCoins.png");
	HudTexture = App->textures->Load("Assets/hud.png");
	TurtleTexture = App->textures->Load("Assets/TurtleSmile.png");
	/*App->audio->PlayMusic("Assets/titleMusic.ogg", 1.0f);*/
	MusicIntro = App->audio->LoadFx("Assets/titleMusic.ogg");

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	/*BackgroundPath.Reset();*/
	return ret;
}

update_status ModuleTitle::Update()
{
	if (coins > 0) {
		PressEnter.Update();
	}
	
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) {
		screenupdate = true;
	}
	/*App->render->Blit(bgTexture, 0, 0, &(TitleScreen.GetCurrentFrame()), 1);*/
	if (screenupdate==true) {
		InsertCoins.Update();
		TurtleSmile.Update();
		App->render->Blit(EnterCoinsTitleTexture, 0, 0, &(TitleEnterCoin.GetCurrentFrame()), 1);

		//App->audio->PlayMusic("Assets/titleMusic.ogg", 1.0f);
		if (App->input->keys[SDL_SCANCODE_LSHIFT] == KEY_STATE::KEY_DOWN) {
				coins++;
		}
		if (App->input->keys[SDL_SCANCODE_O] == KEY_STATE::KEY_DOWN && coins>0)
		{
			App->fade->FadeToBlack(this, (Module*)App->scene, 90);
		}
	}
	else {
		
		App->render->Blit(bgTexture, 0, 0, &(TitleScreen.GetCurrentFrame()), 1);
		/*App->audio->PlayMusic(MusicIntro);*/
	}
	
	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleTitle::PostUpdate()
{
	// Draw everything --------------------------------------
	if (screenupdate == true && coins > 0) {
		App->render->Blit(PressEnterTexture, 5, 35, &(PressEnter.GetCurrentFrame()), 1);
	}
	if (screenupdate == true) {
		App->render->Blit(InsertCoinsTexture, 83, 18, &(InsertCoins.GetCurrentFrame()), 0);
		App->render->Blit(InsertCoinsTexture, 151, 18, &(InsertCoins.GetCurrentFrame()), 0);
		App->render->Blit(InsertCoinsTexture, 219, 18, &(InsertCoins.GetCurrentFrame()), 0);
		App->render->Blit(HudTexture, 0, 0, &(Hud.GetCurrentFrame()), 0);
		App->render->Blit(TurtleTexture, 50, 20, &(TurtleSmile.GetCurrentFrame()), 1);
	}
	
	return update_status::UPDATE_CONTINUE;
}

bool ModuleTitle::CleanUp() {
	LOG("Clearing Over");

	App->textures->Unload(bgTexture);
	App->textures->Unload(EnterCoinsTitleTexture);
	App->textures->Unload(PressEnterTexture);
	App->textures->Unload(InsertCoinsTexture);
	App->textures->Unload(HudTexture);
	App->textures->Unload(TurtleTexture);


	return true;
}
#include "ModuleWin.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleTitle.h"
#include "ModuleChooseCharacter.h"
#include "ModuleAudio.h"
#include "ModuleScene.h"
#include "ModuleInput.h"
#include "ModuleEnemies.h"
#include "ModuleLevel2.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollisions.h"

#include "SDL_mixer/include/SDL_mixer.h"
#include "SDL/include/SDL_Scancode.h"


ModuleWin::ModuleWin(bool startEnabled) : Module(startEnabled)
{

}

ModuleWin::~ModuleWin()
{

}

// Load assets
bool ModuleWin::Start()
{

	LOG("Loading background assets");

	App->player->Disable();
	App->level2->Disable();
	App->enemies->Disable();
	App->collisions->Disable();
	bool ret = true;
	Mix_FadeOutMusic(0.0);
	WinTexture = App->textures->Load("Assets/WinScreen.png");
	App->audio->PlayMusic("Assets/Fx/WinScreenMusic.ogg", 1.0f);

	App->character->coins = 0;

	

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	

	return ret;
}

update_status ModuleWin::Update()
{
	// Get gamepad info
	GamePad& pad = App->input->pads[0];

	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || pad.a)
	{
		CleanUp();
		App->fade->FadeToBlack(this, (Module*)App->title, 90);
		App->scene->active = true;

	}



	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleWin::PostUpdate()
{

	App->render->Blit(WinTexture, 0, 0, NULL);
	return update_status::UPDATE_CONTINUE;
}

bool ModuleWin::CleanUp() {
	LOG("Clearing Intro");

	App->textures->Unload(WinTexture);
	App->player->CleanUp();
	App->player->Disable();
	App->enemies->CleanUp();
	App->enemies->Disable();
	App->level2->CleanUp();
	App->scene->active = true;
	

	return true;
}
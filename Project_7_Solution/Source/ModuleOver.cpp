#include "ModuleOver.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleTitle.h"
#include"ModuleChooseCharacter.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollisions.h"

#include "SDL_mixer/include/SDL_mixer.h"
#include "SDL/include/SDL_Scancode.h"


ModuleOver::ModuleOver(bool startEnabled) : Module(startEnabled)
{

}

ModuleOver::~ModuleOver()
{

}

// Load assets
bool ModuleOver::Start()
{
	LOG("Loading background assets");

	bool ret = true;
	
	App->character->coins = 0;

	/*App->enemies->Disable();
	App->player->Disable();*/
	
	bgTexture = App->textures->Load("Assets/Game_Over.png");
	Mix_FadeOutMusic(0.0);
	App->collisions->CleanUp();

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

update_status ModuleOver::Update()
{
	//El següent if serveix per a reiniciar el joc des del game over però falta fer un reset a tots els elements del joc
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->title, 90);

	}
	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleOver::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);
	return update_status::UPDATE_CONTINUE;
}

bool ModuleOver::CleanUp() {
	LOG("Clearing Over");

	App->textures->Unload(bgTexture);

	return true;
}
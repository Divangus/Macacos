#include "ModuleOver.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
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

	bgTexture = App->textures->Load("Assets/Game_Over.png");

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

update_status ModuleOver::Update()
{


	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
	}

	return update_status::UPDATE_STOP;
}

// Update: draw background
update_status ModuleOver::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);

	return update_status::UPDATE_CONTINUE;
}
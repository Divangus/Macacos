#include "ModuleOver.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"


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

	App->enemies->Disable();
	App->player->Disable();

	return ret;
}

update_status ModuleOver::Update()
{
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
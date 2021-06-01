#include "ModuleTitle.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL_Scancode.h"


ModuleTitle::ModuleTitle(bool startEnabled) : Module(startEnabled)
{
	//BackgroundCity.PushBack({ 0,0,320,384 });
	//BackgroundCity.speed = 0.1f;

	//BackgroundPath.PushBack({ 0.0f, -0.1f }, 200, &BackgroundCity);
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
	/*BackgroundTexture = App->textures->Load("Assets/Intro/NightCity.png");*/
	App->audio->PlayMusic("Assets/titleMusic.ogg", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	/*BackgroundPath.Reset();*/
	return ret;
}

update_status ModuleTitle::Update()
{
	
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->scene, 90);
	}
	
	/*BackgroundCity.Update();
	BackgroundPath.Update();*/

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleTitle::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);
	/*App->render->Blit(BackgroundTexture, 0, 0, &(BackgroundCity.GetCurrentFrame()), 1);*/

	return update_status::UPDATE_CONTINUE;
}

bool ModuleTitle::CleanUp() {
	LOG("Clearing Over");

	App->textures->Unload(bgTexture);
	//App->textures->Unload(BackgroundTexture);

	return true;
}
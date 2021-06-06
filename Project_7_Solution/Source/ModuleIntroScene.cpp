#include "ModuleIntroScene.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL_Scancode.h"


ModuleIntroScene::ModuleIntroScene(bool startEnabled) : Module(startEnabled)
{
	
}

ModuleIntroScene::~ModuleIntroScene()
{

}

// Load assets
bool ModuleIntroScene::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Intro_Screen.png");
	

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	/*NightcityP.Reset()*/;

	return ret;
}

update_status ModuleIntroScene::Update()
{
	// Get gamepad info
	GamePad& pad = App->input->pads[0];
	/*NightCity.Update();
	NightcityP.Update();*/
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN||pad.a)
	{
		App->fade->FadeToBlack(this, (Module*)App->title, 90);
	}

	

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleIntroScene::PostUpdate()
{
	// Draw everything --------------------------------------
	/*
	App->render->Blit(NightCityTexture, 0, 0, NULL);*/

	App->render->Blit(bgTexture, 0, 0, NULL);
	return update_status::UPDATE_CONTINUE;
}

bool ModuleIntroScene::CleanUp(){
	LOG("Clearing Intro");

	App->textures->Unload(bgTexture);
	/*App->textures->Unload(NightCityTexture);*/

	return true;
}
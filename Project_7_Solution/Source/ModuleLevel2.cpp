#include "ModuleLevel2.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL_Scancode.h"

ModuleLevel2::ModuleLevel2(bool startEnabled):Module(startEnabled) {
	BackgroundLevel2.PushBack({ 0,0,448,222 });
	BackgroundLevel2.loop = false;

	hud.PushBack({ 0,0,304,222 });
	hud.loop = false;

	Smoke.PushBack({0,0,128,65});
	Smoke.PushBack({ 0,75,128,65 });
	Smoke.PushBack({ 0,154,128,65 });
	Smoke.loop = true;
	Smoke.speed = 0.18f;

	April.PushBack({ 5,6,31,65 });
	April.PushBack({ 42,6,28,65 });
	April.loop = true;
	April.speed = 0.025f;
}

ModuleLevel2::~ModuleLevel2() {}

bool ModuleLevel2::Start() {
	LOG("Loading background assets");

	bool ret = true;

	active = true;

	App->enemies->Enable();
	App->player->Enable();

	BackgroundLevel2Texture = App->textures->Load("Assets/Level2.png");
	HudTexture = App->textures->Load("Assets/hud.png");
	AprilTexture = App->textures->Load("Assets/AprilONeil.png");
	SmokeTexture = App->textures->Load("Assets/SmokeLevel2.png");
	AprilHelpMeFx = App->audio->LoadFx("Assets/Fx/AprilHelpMeFx.wav");
	App->audio->PlayMusic("Assets/Fx/Level2Music.ogg");

	App->audio->PlayFx(AprilHelpMeFx);

	App->render->camera.x = 0;
		
	App->player->position.x = 20;
	App->player->position.y = 100;

	return ret;
}

update_status ModuleLevel2::Update() {

	// Get gamepad info
	GamePad& pad = App->input->pads[0];

	hud.Update();
	Smoke.Update();

	//if (App->render->camera.x > LIMIT_CAMERA_LEVEL2) {
	//	App->render->camera.x = LIMIT_CAMERA_LEVEL2;
	//}
	if (App->player->position.x < App->render->LimitPL) {
		App->player->position.x = App->render->LimitPL;
	}
	if (App->player->position.x > 300) {
		App->player->position.x = 300;
	}
	if (App->player->position.y > 145) { //bottom
		App->player->position.y = 145;
	}
	if (App->player->position.y < 60) {//top
		App->player->position.y = 55;
	}
	if (App->player->position.x < 0) {
		App->player->position.x = 0;
	}

	April.Update();
	App->player->position.x += 0;

	if (App->input->keys[SDL_SCANCODE_F3] == KEY_DOWN || pad.l1) {
		App->fade->FadeToBlack(this, (Module*)App->over, 90);
	}
	

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleLevel2::PostUpdate() {

	App->render->Blit(BackgroundLevel2Texture, 0, 0, &(BackgroundLevel2.GetCurrentFrame()), 1);
	App->render->Blit(SmokeTexture, 0, 0, &(Smoke.GetCurrentFrame()), 0);
	App->render->Blit(SmokeTexture, 0, 0, &(Smoke.GetCurrentFrame()), 0);
	App->render->Blit(SmokeTexture, 128, 0, &(Smoke.GetCurrentFrame()), 0);
	App->render->Blit(SmokeTexture, 256, 0, &(Smoke.GetCurrentFrame()), 0);
	App->render->Blit(SmokeTexture, 384, 0, &(Smoke.GetCurrentFrame()), 0);
	App->render->Blit(SmokeTexture, 512, 0, &(Smoke.GetCurrentFrame()), 0);
	App->render->Blit(AprilTexture, 176, 85, &(April.GetCurrentFrame()), 1);
	App->render->Blit(HudTexture, 0, 0, &(hud.GetCurrentFrame()), 0);

	return update_status::UPDATE_CONTINUE;
}

bool ModuleLevel2::CleanUp() {

	LOG("Clearing Over");

	App->textures->Unload(BackgroundLevel2Texture);
	App->textures->Unload(HudTexture);
	App->textures->Unload(AprilTexture);

	return true;
}
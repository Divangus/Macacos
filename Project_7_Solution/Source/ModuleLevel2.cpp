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
}

ModuleLevel2::~ModuleLevel2() {}

bool ModuleLevel2::Start() {
	LOG("Loading background assets");

	bool ret = true;

	BackgroundLevel2Texture = App->textures->Load("Assets/Level2.png");

	position.x = 40;
	position.y = 120;

	App->enemies->Enable();
	App->player->Enable();

	return ret;
}

update_status ModuleLevel2::Update() {

	App->player->position.x += 0;

	//if (position.x < App->render->LimitPL) {
	//	position.x = App->render->LimitPL;
	//}
	//if (position.x > 1280) {
	//	position.x = 1280;
	//}
	//if (position.y > 135) { //bottom
	//	position.y = 135;
	//}
	//if (position.y < 50) {//top
	//	position.y = 50;
	//}
	//if (position.x < 0) {
	//	position.x = 0;
	//}

	//if (position.x > (App->render->LimitPR)) {
	//	if (App->render->camera.x < LIMIT_CAMERA_LEVEL1) {
	//		App->render->LimitPR += speed;
	//		App->render->LimitPL += speed;
	//		App->render->camera.x += App->render->cameraSpeed;
	//	}
	/*}*/
	App->render->Blit(BackgroundLevel2Texture, 0, 0, &(BackgroundLevel2.GetCurrentFrame()), 1);

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleLevel2::PostUpdate() {

	App->render->Blit(BackgroundLevel2Texture, 0, 0, &(BackgroundLevel2.GetCurrentFrame()), 1);
	App->render->Blit(HudTexture, 0, 0, &(hud.GetCurrentFrame()), 0);

	return update_status::UPDATE_CONTINUE;
}

bool ModuleLevel2::CleanUp() {

	LOG("Clearing Over");

	App->textures->Unload(BackgroundLevel2Texture);

	return true;
}
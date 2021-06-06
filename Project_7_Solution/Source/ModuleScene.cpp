#include "ModuleScene.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"

#include "SDL/include/SDL_Scancode.h"

ModuleScene::ModuleScene(bool startEnabled) : Module(startEnabled) {
	
	hud.PushBack({ 0,0,304,222 });
	hud.loop = false;
	
	Door2.PushBack({ 268,239,33,79 });
	Door2.PushBack({ 307,239,33,79 });
	Door2.PushBack({ 347,239,49,79 });
	Door2.PushBack({ 400,239,60,79 });
	Door2.PushBack({ 0,0,0,0 });
	Door2.loop = false;
	Door2.speed = 0.1f;

	Door3.PushBack({ 268,239,33,79 });
	Door3.PushBack({ 307,239,33,79 });
	Door3.PushBack({ 347,239,49,79 });
	Door3.PushBack({ 400,239,60,79 });
	Door3.PushBack({ 0,0,0,0 });
	Door3.loop = false;
	Door3.speed = 0.1f;

	Door1.PushBack({ 268,239,33,79 });
	Door1.PushBack({ 307,239,33,79 });
	Door1.PushBack({ 347,239,49,79 });
	Door1.PushBack({ 400,239,60,79 });
	Door1.PushBack({ 0,0,0,0 });
	Door1.loop = false;
	Door1.speed = 0.1f;

	DoorFire.PushBack({ 481,238,35,81 });
	DoorFire.PushBack({ 516,238,35,81 });
	DoorFire.PushBack({ 551,238,35,81 });
	DoorFire.PushBack({ 586,238,35,81 });
	DoorFire.PushBack({ 621,238,35,81 });
	DoorFire.PushBack({ 656,238,35,81 });
	DoorFire.PushBack({ 691,238,35,81 });
	DoorFire.loop = true;
	DoorFire.speed = 0.2f;

	lift.PushBack({268,332,44,77});
	lift.PushBack({ 312,332,44,77 });
	lift.PushBack({ 359,332,44,77 });
	lift.loop = false;
	lift.speed = 0.1f;

	liftFire.PushBack({ 405,331,46,79 });
	liftFire.PushBack({ 451,331,46,79 });
	liftFire.PushBack({ 497,331,46,79 });
	liftFire.PushBack({ 543,331,46,79 });
	liftFire.PushBack({ 589,331,46,79 });
	liftFire.PushBack({ 635,331,46,79 });
	liftFire.PushBack({ 681,331,46,79 });
	liftFire.loop = true;
	liftFire.speed = 0.1f;
}

ModuleScene::~ModuleScene() {}

// Load assets
bool ModuleScene::Start()
{
	LOG("Loading background assets");

	bool ret = true;


	bgTexture = App->textures->Load("Assets/background.png");
	hudTexture = App->textures->Load("Assets/hud.png");
	/*Fire_Texture = App->textures->Load("Assets/frontFire.png");*/
	Elements_Texture = App->textures->Load("Assets/scene.png");
	Quotes_Texture = App->textures->Load("Assets/Quotes.png");
	App->audio->PlayMusic("Assets/stage1.ogg", 1.0f);
	AprilScreamFx = App->audio->LoadFx("Assets/Fx/AprilScreamFx.wav");


	
	//App->enemies->AddEnemy(ENEMY_TYPE::PURPLE, 220, 120);

	App->enemies->AddEnemy(ENEMY_TYPE::PURPLE, 220, 120);
	App->enemies->AddEnemy(ENEMY_TYPE::ORANGE, 335, 110);
	App->enemies->AddEnemy(ENEMY_TYPE::WHITE, 800, 120);
	App->enemies->AddEnemy(ENEMY_TYPE::PURPLE, 689, 125);

	App->enemies->AddEnemy(ENEMY_TYPE::PURPLE, 890, 100);


	App->enemies->Enable();
	App->player->Enable();

	Door2.Reset();
	lift.Reset();

	return ret;
}

update_status ModuleScene::Update()
{
	// Get gamepad info
	GamePad& pad = App->input->pads[0];

	App->render->camera.x += 0;
	
	//Fire.Update();
	if (App->render->camera.x > 850) {
		lift.Update();
	}

	if (App->render->camera.x > 260) {
		Door1.Update();
	}
	if (App->render->camera.x > 545) {
		Door2.Update();
	}
	if (App->render->camera.x > 565) {
		
		Door3.Update();
	}
	
	liftFire.Update();
	AttackQuote.Update();

	//spawn enemies
	/*if (App->render->camera.x > 260) {
		App->enemies->AddEnemy(ENEMY_TYPE::PURPLE, 411, 120);
	}*/

	
	DoorFire.Update();

	if (App->input->keys[SDL_SCANCODE_F3] == KEY_DOWN||pad.l1) {
		App->fade->FadeToBlack(this, (Module*)App->over, 90);
	}

	if(App->input->keys[SDL_SCANCODE_F4] == KEY_DOWN || pad.r2) {
		App->fade->FadeToBlack(this, (Module*)App->level2, 90);
	}


	if (App->player->position.x == 1240) {
		App->audio->PlayFx(AprilScreamFx);
		App->scene->CleanUp();
		active = false;
		App->fade->FadeToBlack(this, (Module*)App->level2, 90);
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleScene::PostUpdate()
{

	if (App->render->camera.x == 920) {
		App->enemies->AddEnemy(ENEMY_TYPE::ORANGE, 960, 100);
	}

	if (App->render->camera.x == 260) {
		App->enemies->AddEnemy(ENEMY_TYPE::ORANGE, 409, 70);
	}
	if (App->render->camera.x == 545) {

		App->enemies->AddEnemy(ENEMY_TYPE::WHITE, 685, 40);
	}
	if (App->render->camera.x == 565) {

		App->enemies->AddEnemy(ENEMY_TYPE::WHITE, 822, 40);
	}
	if (App->render->camera.x == 850) {
		
		App->enemies->AddEnemy(ENEMY_TYPE::WHITE, 942, 40);
		App->enemies->AddEnemy(ENEMY_TYPE::WHITE,1070, 40);
	}
	
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);

	//Door Fire
	App->render->Blit(Elements_Texture, 411, 49, &(DoorFire.GetCurrentFrame()), 1);
	App->render->Blit(Elements_Texture, 699, 49, &(DoorFire.GetCurrentFrame()), 1);
	App->render->Blit(Elements_Texture, 827, 49, &(DoorFire.GetCurrentFrame()), 1);

	//First Door
	App->render->Blit(Elements_Texture, 411, 49, &(Door1.GetCurrentFrame()), 1);

	//Second Door
	App->render->Blit(Elements_Texture, 699, 49, &(Door2.GetCurrentFrame()), 1);

	//Third Door
	App->render->Blit(Elements_Texture, 827, 49, &(Door3.GetCurrentFrame()), 1);

	//Fire Lift
	App->render->Blit(Elements_Texture, 949, 50, &(liftFire.GetCurrentFrame()), 1);
	App->render->Blit(Elements_Texture, 1077, 50, &(liftFire.GetCurrentFrame()), 1);

	//Lift
	App->render->Blit(Elements_Texture, 949, 50, &(lift.GetCurrentFrame()), 1);
	App->render->Blit(Elements_Texture, 1077, 50, &(lift.GetCurrentFrame()), 1);

	
	//Attack Quote
	App->render->Blit(Quotes_Texture, 10, 115, &(AttackQuote.GetCurrentFrame()), 1);

	//hud
	App->render->Blit(hudTexture, 0, 0, &(hud.GetCurrentFrame()), 0);
	return update_status::UPDATE_CONTINUE;
}

bool ModuleScene::CleanUp() {
	LOG("Clearing Over");

	App->textures->Unload(bgTexture);
	App->textures->Unload(hudTexture);
	App->textures->Unload(Elements_Texture);
	App->textures->Unload(Quotes_Texture);
	/*App->player->Disable();*/
	App->enemies->Disable();

	active = false;

	return true;
}
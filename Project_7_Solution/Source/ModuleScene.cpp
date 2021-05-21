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
	

	Fire.PushBack({ 25, 1, 308, 67 });
	Fire.PushBack({ 25,70,308,67 });
	Fire.PushBack({ 28,138,308,67 });
	Fire.PushBack({ 343,4,308,67 });
	Fire.PushBack({ 343,72,308,67 });
	Fire.PushBack({ 343,137,308,67 });
	Fire.PushBack({ 659,1,308,67 });
	Fire.PushBack({ 659,71,308,67 });
	//Fire.loop = true;
	Fire.speed = 0.1f;

	Door.PushBack({ 268,239,33,79 });
	Door.PushBack({ 307,239,33,79 });
	Door.PushBack({ 347,239,49,79 });
	Door.PushBack({ 400,239,60,79 });
	Door.loop = false;
	Door.speed = 0.1f;

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
	Fire_Texture = App->textures->Load("Assets/frontFire.png");
	Elements_Texture = App->textures->Load("Assets/scene.png");
	Quotes_Texture = App->textures->Load("Assets/Quotes.png");
	App->audio->PlayMusic("Assets/stage1.ogg", 1.0f);


	App->enemies->AddEnemy(ENEMY_TYPE::PURPLE, 200, 120);
	App->enemies->AddEnemy(ENEMY_TYPE::ORANGE, 200, 100);
	App->enemies->AddEnemy(ENEMY_TYPE::PURPLE, 300, 120);
	App->enemies->AddEnemy(ENEMY_TYPE::ORANGE, 300, 100);
	App->enemies->AddEnemy(ENEMY_TYPE::PURPLE, 500, 120);
	App->enemies->AddEnemy(ENEMY_TYPE::ORANGE, 400, 100);

	App->enemies->Enable();
	App->player->Enable();

	return ret;
}

update_status ModuleScene::Update()
{
	App->render->camera.x += 0;

	Fire.Update();
	
	lift.Update();
	
	liftFire.Update();
	AttackQuote.Update();

	Door.Update();
	DoorFire.Update();

	if (App->input->keys[SDL_SCANCODE_F3] == KEY_DOWN) {
		App->fade->FadeToBlack(this, (Module*)App->over, 90);
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleScene::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);
	App->render->Blit(hudTexture, 0, 0, NULL);

	//Big Fire
	App->render->Blit(Fire_Texture, -5, 160, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 250, 160, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 504, 160, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 760, 160, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 1018, 160, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 1065, 160, &(Fire.GetCurrentFrame()), 1);
	
	//Doors closed
	App->render->Blit(Elements_Texture, 411, 49, &(Door.GetCurrentFrame()), 1);
	App->render->Blit(Elements_Texture, 699, 49, &(Door.GetCurrentFrame()), 1);
	App->render->Blit(Elements_Texture, 827, 49, &(Door.GetCurrentFrame()), 1);

	//Door Fire
	App->render->Blit(Elements_Texture, 411, 49, &(DoorFire.GetCurrentFrame()), 1);
	App->render->Blit(Elements_Texture, 699, 49, &(DoorFire.GetCurrentFrame()), 1);
	App->render->Blit(Elements_Texture, 827, 49, &(DoorFire.GetCurrentFrame()), 1);

	//Lift
	App->render->Blit(Elements_Texture, 949, 50, &(lift.GetCurrentFrame()), 1);
	App->render->Blit(Elements_Texture, 1077, 50, &(lift.GetCurrentFrame()), 1);

	//Fire Lift
	App->render->Blit(Elements_Texture, 949, 50, &(liftFire.GetCurrentFrame()), 1);
	App->render->Blit(Elements_Texture, 1077, 50, &(liftFire.GetCurrentFrame()), 1);
	//Attack Quote
	App->render->Blit(Quotes_Texture, 10, 115, &(AttackQuote.GetCurrentFrame()), 1);

	return update_status::UPDATE_CONTINUE;
}

bool ModuleScene::CleanUp() {
	LOG("Clearing Over");

	App->textures->Unload(bgTexture);
	App->textures->Unload(hudTexture);
	App->textures->Unload(Fire_Texture);
	App->textures->Unload(Elements_Texture);
	App->textures->Unload(Quotes_Texture);

	return true;
}
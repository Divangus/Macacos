#include "ModuleScene.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"

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
	Door.speed = 0.1f;
}

ModuleScene::~ModuleScene() {}

// Load assets
bool ModuleScene::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/background.png");
	Fire_Texture = App->textures->Load("Assets/frontFire.png");
	Elements_Texture = App->textures->Load("Assets/scene.png");
	App->audio->PlayMusic("Assets/stage1.ogg", 1.0f);


	App->enemies->AddEnemy(ENEMY_TYPE::PURPLE, 200, 120);
	App->enemies->AddEnemy(ENEMY_TYPE::ORANGE, 200, 100);
	App->enemies->AddEnemy(ENEMY_TYPE::PURPLE, 300, 120);
	App->enemies->AddEnemy(ENEMY_TYPE::ORANGE, 300, 100);
	App->enemies->AddEnemy(ENEMY_TYPE::PURPLE, 500, 120);
	App->enemies->AddEnemy(ENEMY_TYPE::ORANGE, 400, 100);


	return ret;
}

update_status ModuleScene::Update()
{
	App->render->camera.x += 0;

	Fire.Update();
	Door.Update();

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleScene::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);

	//Big Fire
	App->render->Blit(Fire_Texture, -5, 160, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 250, 160, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 495, 160, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 740, 160, &(Fire.GetCurrentFrame()), 1);

	//Doors closed
	App->render->Blit(Elements_Texture, 411, 49, &(Door.GetCurrentFrame()), 1);
	App->render->Blit(Elements_Texture, 699, 49, &(Door.GetCurrentFrame()), 1);
	App->render->Blit(Elements_Texture, 827, 49, &(Door.GetCurrentFrame()), 1);
	return update_status::UPDATE_CONTINUE;
}

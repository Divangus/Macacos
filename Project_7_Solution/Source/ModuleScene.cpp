#include "ModuleScene.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"

ModuleScene::ModuleScene(bool startEnabled) : Module(startEnabled) {}

ModuleScene::~ModuleScene() {}

// Load assets
bool ModuleScene::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/background.png");
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

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleScene::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);

	return update_status::UPDATE_CONTINUE;
}

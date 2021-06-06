#include "ModuleEnemies.h"

#include "Application.h"

#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"

#include "Enemy.h"
#include "Enemy_Purple.h"
#include "Enemy_Orange.h"
#include "Enemy_White.h"
#include "Enemy_Boss.h"

#define SPAWN_MARGIN 50


ModuleEnemies::ModuleEnemies(bool startEnabled) : Module(startEnabled)
{
	for(uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;

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

	position.x = 40;
	position.y = 120;

}


ModuleEnemies::~ModuleEnemies()
{

}

bool ModuleEnemies::Start()
{
	texture = App->textures->Load("Assets/Orange_Soldier.png");
	texture2 = App->textures->Load("Assets/enemy_purple.png");
	texture3 = App->textures->Load("Assets/White_Soldier.png");
	texture4 = App->textures->Load("Assets/Rocksteady.png");
	enemyDestroyedFx = App->audio->LoadFx("Assets/Fx/EnemyDying.wav");
	Fire_Texture = App->textures->Load("Assets/frontFire.png");
	EnemyDyingFx = App->audio->LoadFx("Assets/Fx/EnemyDying.wav");

	return true;
}

update_status ModuleEnemies::Update()
{

	if (position.x < App->render->LimitPL) {
		position.x = App->render->LimitPL;
	}
	if (position.x > 1000) {
		position.x = 1000;
	}
	if (position.y > 135) { //bottom
		position.y = 135;
	}
	if (position.y < 50) {//top
		position.y = 50;
	}
	if (position.x < 0) {
		position.x = 0;
	}

	if (position.x > (App->render->LimitPR)) {
		if (App->render->camera.x < LIMIT_CAMERA_LEVEL1) {
			App->render->LimitPR += speed;
			App->render->LimitPL += speed;
			App->render->camera.x += App->render->cameraSpeed;
		}
	}

	Fire.Update();
	HandleEnemiesSpawn();
	
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(enemies[i] != nullptr)
			enemies[i]->Update();
	}
	//bubble_sort(enemies, MAX_ENEMIES);

	HandleEnemiesDespawn();

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
			enemies[i]->Draw();
	}

	/*App->render->Blit(Fire_Texture, -5, 165, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 250, 165, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 504, 165, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 760, 165, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 1018, 165, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 1065, 165, &(Fire.GetCurrentFrame()), 1);*/
	App->render->Blit(Fire_Texture, -5, 165, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 250, 165, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 504, 165, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 760, 165, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 1018, 165, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 1065, 165, &(Fire.GetCurrentFrame()), 1);


	return update_status::UPDATE_CONTINUE;


}

// Called before quitting
bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");

	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(enemies[i] != nullptr)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return true;
}

bool ModuleEnemies::AddEnemy(ENEMY_TYPE type, int x, int y)
{
	bool ret = false;

	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if(spawnQueue[i].type == ENEMY_TYPE::NO_TYPE)
		{
			spawnQueue[i].type = type;
			spawnQueue[i].x = x;
			spawnQueue[i].y = y;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleEnemies::HandleEnemiesSpawn()
{
	// Iterate all the enemies queue
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (spawnQueue[i].type != ENEMY_TYPE::NO_TYPE)
		{
			// Spawn a new enemy if the screen has reached a spawn position
			if (spawnQueue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				LOG("Spawning enemy at %d", spawnQueue[i].x * SCREEN_SIZE);

				SpawnEnemy(spawnQueue[i]);
				spawnQueue[i].type = ENEMY_TYPE::NO_TYPE; // Removing the newly spawned enemy from the queue
			}
		}
	}
	//RelocateEnemies();
}

//void ModuleEnemies::bubble_sort(Enemy* arr[], int size) {
//	
//	for (auto i = 0; i < size - 1; i++) {
//		for (auto j = 0; j < size - 1 - i; j++)
//		{
//			if (arr[j] == nullptr || arr[j + 1] == nullptr) {
//				break;
//			}
//			
//			if (arr[j]->position.y > arr[j + 1]->position.y)
//			{
//				Enemy* t = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = t;
//			}
//			
//		}
//	}
//}

void ModuleEnemies::HandleEnemiesDespawn()
{
	// Iterate existing enemies
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			// Delete the enemy when it has reached the end of the screen
			if (enemies[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
			{
				LOG("DeSpawning enemy at %d", enemies[i]->position.x * SCREEN_SIZE);

				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
	}
}

void ModuleEnemies::SpawnEnemy(const EnemySpawnpoint& info)
{
	// Find an empty slot in the enemies array
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] == nullptr)
		{
			switch (info.type)
			{
				case ENEMY_TYPE::PURPLE:
					enemies[i] = new Enemy_Purple(info.x, info.y);
					enemies[i]->texture = texture2;
					enemies[i]->EnemyType = 1;
					enemies[i]->life = 3;
					break;
				case ENEMY_TYPE::ORANGE:
					enemies[i] = new Enemy_Orange(info.x, info.y);
					enemies[i]->texture = texture;
					enemies[i]->EnemyType = 2;
					break;
				case ENEMY_TYPE::WHITE:
					enemies[i] = new Enemy_White(info.x, info.y);
					enemies[i]->texture = texture3;
					enemies[i]->EnemyType = 3;
					break;
			}
			
			enemies[i]->destroyedFx = enemyDestroyedFx;
			break;
		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for(uint i = 0; i < MAX_ENEMIES; ++i)
	{
		//if(enemies[i].type)
		if(enemies[i] != nullptr && enemies[i]->GetCollider() == c1)
		{
			enemies[i]->OnCollision(c2); //Notify the enemy of a collision
			if (enemies[i]->destroyed == true) {
			delete enemies[i];
		/*	App->audio->LoadFx(EnemyDyingFx);*/
			enemies[i] = nullptr;
			}
			break;
		}
	}
	
	
}
#include "ModuleCollisions.h"

#include "Application.h"

#include "ModuleRender.h"
#include "ModuleInput.h"
#include "SDL/include/SDL_Scancode.h"

ModuleCollisions::ModuleCollisions(bool startEnabled) : Module(startEnabled)
{
	for(uint i = 0; i < MAX_COLLIDERS; ++i)
		colliders[i] = nullptr;

	matrix[Collider::Type::PLAYER][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::PLAYER][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::PLAYER][Collider::Type::PLAYER_ATTACK] = false;
	matrix[Collider::Type::PLAYER][Collider::Type::PURPLE_ATTACK] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::ORANGE_ATTACK] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::WHITE_ATTACK] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::BOSS_ATTACK] = true;
	matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_SHOT] = true;

	matrix[Collider::Type::ENEMY][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::ENEMY][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_ATTACK] = false;
	matrix[Collider::Type::ENEMY][Collider::Type::PURPLE_ATTACK] = false;
	matrix[Collider::Type::ENEMY][Collider::Type::ORANGE_ATTACK] = false;
	matrix[Collider::Type::ENEMY][Collider::Type::WHITE_ATTACK] = false;
	matrix[Collider::Type::ENEMY][Collider::Type::BOSS_ATTACK] = false;
	matrix[Collider::Type::ENEMY][Collider::Type::ENEMY_SHOT] = false;

	matrix[Collider::Type::PLAYER_ATTACK][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::PLAYER_ATTACK][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::PLAYER_ATTACK][Collider::Type::PLAYER_ATTACK] = false;
	matrix[Collider::Type::PLAYER_ATTACK][Collider::Type::PURPLE_ATTACK] = false;
	matrix[Collider::Type::PLAYER_ATTACK][Collider::Type::ORANGE_ATTACK] = false;
	matrix[Collider::Type::PLAYER_ATTACK][Collider::Type::WHITE_ATTACK] = false;
	matrix[Collider::Type::PLAYER_ATTACK][Collider::Type::BOSS_ATTACK] = false;
	matrix[Collider::Type::PLAYER_ATTACK][Collider::Type::ENEMY_SHOT] = false;

	matrix[Collider::Type::PURPLE_ATTACK][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::PURPLE_ATTACK][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::PURPLE_ATTACK][Collider::Type::PLAYER_ATTACK] = false;
	matrix[Collider::Type::PURPLE_ATTACK][Collider::Type::PURPLE_ATTACK] = false;
	matrix[Collider::Type::PURPLE_ATTACK][Collider::Type::ORANGE_ATTACK] = false;
	matrix[Collider::Type::PURPLE_ATTACK][Collider::Type::WHITE_ATTACK] = false;
	matrix[Collider::Type::PURPLE_ATTACK][Collider::Type::BOSS_ATTACK] = false;
	matrix[Collider::Type::PURPLE_ATTACK][Collider::Type::ENEMY_SHOT] = false;

	matrix[Collider::Type::ORANGE_ATTACK][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::ORANGE_ATTACK][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::ORANGE_ATTACK][Collider::Type::PLAYER_ATTACK] = false;
	matrix[Collider::Type::ORANGE_ATTACK][Collider::Type::PURPLE_ATTACK] = false;
	matrix[Collider::Type::ORANGE_ATTACK][Collider::Type::ORANGE_ATTACK] = false;
	matrix[Collider::Type::ORANGE_ATTACK][Collider::Type::WHITE_ATTACK] = false;
	matrix[Collider::Type::ORANGE_ATTACK][Collider::Type::BOSS_ATTACK] = false;
	matrix[Collider::Type::ORANGE_ATTACK][Collider::Type::ENEMY_SHOT] = false;

	matrix[Collider::Type::WHITE_ATTACK][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::WHITE_ATTACK][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::WHITE_ATTACK][Collider::Type::PLAYER_ATTACK] = false;
	matrix[Collider::Type::WHITE_ATTACK][Collider::Type::PURPLE_ATTACK] = false;
	matrix[Collider::Type::WHITE_ATTACK][Collider::Type::ORANGE_ATTACK] = false;
	matrix[Collider::Type::WHITE_ATTACK][Collider::Type::WHITE_ATTACK] = false;
	matrix[Collider::Type::WHITE_ATTACK][Collider::Type::BOSS_ATTACK] = false;
	matrix[Collider::Type::WHITE_ATTACK][Collider::Type::ENEMY_SHOT] = false;

	matrix[Collider::Type::BOSS_ATTACK][Collider::Type::PLAYER] = false;
	matrix[Collider::Type::BOSS_ATTACK][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::BOSS_ATTACK][Collider::Type::PLAYER_ATTACK] = false;
	matrix[Collider::Type::BOSS_ATTACK][Collider::Type::PURPLE_ATTACK] = false;
	matrix[Collider::Type::BOSS_ATTACK][Collider::Type::ORANGE_ATTACK] = false;
	matrix[Collider::Type::BOSS_ATTACK][Collider::Type::WHITE_ATTACK] = false;
	matrix[Collider::Type::BOSS_ATTACK][Collider::Type::BOSS_ATTACK] = false;
	matrix[Collider::Type::BOSS_ATTACK][Collider::Type::ENEMY_SHOT] = false;

	matrix[Collider::Type::ENEMY_SHOT][Collider::Type::PLAYER] = true;
	matrix[Collider::Type::ENEMY_SHOT][Collider::Type::ENEMY] = false;
	matrix[Collider::Type::ENEMY_SHOT][Collider::Type::PLAYER_ATTACK] = false;
	matrix[Collider::Type::ENEMY_SHOT][Collider::Type::PURPLE_ATTACK] = false;
	matrix[Collider::Type::ENEMY_SHOT][Collider::Type::ORANGE_ATTACK] = false;
	matrix[Collider::Type::ENEMY_SHOT][Collider::Type::WHITE_ATTACK] = false;
	matrix[Collider::Type::ENEMY_SHOT][Collider::Type::BOSS_ATTACK] = false;
	matrix[Collider::Type::ENEMY_SHOT][Collider::Type::ENEMY_SHOT] = false;
}

// Destructor
ModuleCollisions::~ModuleCollisions()
{

}

update_status ModuleCollisions::PreUpdate()
{
	// Remove all colliders scheduled for deletion
	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] != nullptr && colliders[i]->pendingToDelete == true)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	Collider* c1;
	Collider* c2;

	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		// skip empty colliders
		if(colliders[i] == nullptr)
			continue;

		c1 = colliders[i];

		// avoid checking collisions already checked
		for(uint k = i+1; k < MAX_COLLIDERS; ++k)
		{
			// skip empty colliders
			if(colliders[k] == nullptr)
				continue;

			c2 = colliders[k];

			if(c1->Intersects(c2->rect))
			{
				if(matrix[c1->type][c2->type] && c1->listener) 
					c1->listener->OnCollision(c1, c2);
				
				if(matrix[c2->type][c1->type] && c2->listener) 
					c2->listener->OnCollision(c2, c1);
			}
		}
	}

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleCollisions::Update()
{
	GamePad& pad = App->input->pads[0];

	if (App->input->keys[SDL_SCANCODE_F1] == KEY_DOWN||pad.x==true) {
		if (debug == true) {
			debug = false;
		}
		else {
			debug = true;
		}
	}

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleCollisions::PostUpdate()
{
	if (debug==true)
		DebugDraw();

	return update_status::UPDATE_CONTINUE;
}

void ModuleCollisions::DebugDraw()
{
	Uint8 alpha = 80;
	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] == nullptr)
			continue;
		
		switch(colliders[i]->type)
		{
			case Collider::Type::NONE: // white
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 255, alpha);
			break;
			case Collider::Type::PLAYER: // green
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 0, alpha);
			break;
			case Collider::Type::ENEMY: // red
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
			case Collider::Type::PLAYER_ATTACK: // yellow
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 0, alpha);
			break;
			case Collider::Type::PURPLE_ATTACK: // magenta
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 255, alpha);
			break;
			case Collider::Type::ORANGE_ATTACK: // magenta
				App->render->DrawQuad(colliders[i]->rect, 0, 255, 255, alpha);
				break;
			case Collider::Type::WHITE_ATTACK: // magenta
				App->render->DrawQuad(colliders[i]->rect, 0, 255, 255, alpha);
				break;
			case Collider::Type::ENEMY_SHOT: // magenta
				App->render->DrawQuad(colliders[i]->rect, 0, 255, 255, alpha);
				break;
		}
	}
}

// Called before quitting
bool ModuleCollisions::CleanUp()
{
	LOG("Freeing all colliders");

	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] != nullptr)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	return true;
}

Collider* ModuleCollisions::AddCollider(SDL_Rect rect, Collider::Type type, Module* listener)
{
	Collider* ret = nullptr;

	for(uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if(colliders[i] == nullptr)
		{
			ret = colliders[i] = new Collider(rect, type, listener);
			break;
		}
	}

	return ret;
}

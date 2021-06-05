#include "Enemy_White.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL.h"
//#include "ModulePlayer.h"

Enemy_White::Enemy_White(int x, int y) : Enemy(x, y)
{
	//Sprite animations
	//Front is left & back is right
	back.PushBack({ 0, 0, 99, 88 });
	back.PushBack({ 99, 0, 99, 88 });
	back.PushBack({ 198, 0, 99, 88 });
	back.PushBack({ 297, 0, 99, 88 });
	back.PushBack({ 396, 0, 99, 88 });
	back.PushBack({ 495, 0, 99, 88 });
	back.PushBack({ 594, 0, 99, 88 });
	back.PushBack({ 693, 0, 99, 88 });
	back.speed = 0.1f;

	front.PushBack({ 792, 1144, 90, 88 });
	front.PushBack({ 693, 1144, 99, 88 });
	front.PushBack({ 594, 1144, 99, 88 });
	front.PushBack({ 495, 1144, 99, 88 });
	front.PushBack({ 396, 1144, 99, 88 });
	front.PushBack({ 297, 1144, 99, 88 });
	front.PushBack({ 198, 1144, 99, 88 });
	front.PushBack({ 99, 1144, 99, 88 });
	front.speed = 0.1f;

	back_shot.PushBack({ 0, 616, 99, 88 });

	back_knife.PushBack({ 0, 616, 99, 88 });
	back_knife.PushBack({ 99, 616, 99, 88 });
	back_knife.PushBack({ 198, 616, 99, 88 });
	back_knife.PushBack({ 297, 616, 99, 88 });
	back_knife.PushBack({ 396, 616, 99, 88 });
	back_knife.PushBack({ 495, 616, 99, 88 });
	back_knife.speed = 0.1f;

	front_shot.PushBack({ 792, 1760, 90, 88 });

	front_knife.PushBack({ 792, 1760, 90, 88 });
	front_knife.PushBack({ 693, 1760, 99, 88 });
	front_knife.PushBack({ 594, 1760, 99, 88 });
	front_knife.PushBack({ 495, 1760, 99, 88 });
	front_knife.PushBack({ 396, 1760, 99, 88 });
	front_knife.PushBack({ 297, 1760, 99, 88 });
	front_knife.speed = 0.1f;

	front_hit.PushBack({ 792, 1760, 90, 88 });

	back_hit.PushBack({ 0, 528, 99, 88 });

	back_melee_knife.PushBack({ 0, 528, 99, 88 });
	back_melee_knife.PushBack({ 99, 528, 99, 88 });
	back_melee_knife.PushBack({ 198, 528, 99, 88 });
	back_melee_knife.PushBack({ 297, 528, 99, 88 });
	back_melee_knife.speed = 0.1f;

	front_melee_knife.PushBack({ 792, 1672, 90, 88 });
	front_melee_knife.PushBack({ 693, 1672, 99, 88 });
	front_melee_knife.PushBack({ 594, 1672, 99, 88 });
	front_melee_knife.PushBack({ 495, 1672, 99, 88 });
	front_melee_knife.speed = 0.1f;

	front_iddle.PushBack({ 792, 1320, 90, 88 });

	back_iddle.PushBack({ 0, 176, 99, 88 });

	path[0].PushBack({ 0.0f, 0.0f }, 0, &front_hit);
	path[0].PushBack({ 0.0f, 0.0f }, 50, &front_melee_knife);
	path[0].PushBack({ 0.0f, 0.0f }, 0, &front_iddle);

	path[1].PushBack({ 0.0f, 0.0f }, 0, &back_hit);
	path[1].PushBack({ 0.0f, 0.0f }, 50, &back_melee_knife);
	path[1].PushBack({ 0.0f, 0.0f }, 0, &back_iddle);

	path[2].PushBack({ 0.0f, 0.0f }, 15, &front_knife);
	path[2].PushBack({ 0.0f, 0.0f }, 0, &front_shot);
	path[2].PushBack({ 0.0f, 0.0f }, 0, &front_iddle);

	path[3].PushBack({ 0.0f, 0.0f }, 15, &back_knife);
	path[3].PushBack({ 0.0f, 0.0f }, 0, &back_shot);
	path[3].PushBack({ 0.0f, 0.0f }, 0, &back_iddle);

	WhiteCollider = App->collisions->AddCollider({ 0,0, 30, 20 }, Collider::Type::ENEMY, (Module*)App->enemies);
	WhiteColliderAttack = App->collisions->AddCollider({ 0, 0, 20, 20 }, Collider::Type::WHITE_ATTACK, (Module*)App->enemies);

}

void Enemy_White::Update()
{
	App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::WHITE_ATTACK] = false;

	if (currentAnim == &back || currentAnim == &back_melee_knife || currentAnim == &back_iddle || currentAnim == &back_knife || currentAnim == &back_hit) {
		White_Position = false;
	}
	else {
		White_Position = true;
	}

	if (currentAnim == &front_hit || currentAnim == &back_hit) {
		App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::WHITE_ATTACK] = true;
	}
	else {
		App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::WHITE_ATTACK] = false;
	}

	if (currentAnim == &front_shot)
	{
		App->particles->knife_front.speed.x = -1;
		App->particles->AddParticle(App->particles->knife_front, position.x - 20, position.y - 20, 2, Collider::Type::ENEMY_SHOT);
		//Orange_Position = true;
	}

	if (currentAnim == &back_shot)
	{
		App->particles->knife.speed.x = 1;
		App->particles->AddParticle(App->particles->knife, position.x + 20, position.y - 20, 2, Collider::Type::ENEMY_SHOT);
		//Orange_Position = false;
	}


	if (num == 0){
		if (follow == true) {
			attack = true;
			if (position.x > App->player->position.x + 5 || position.x < App->player->position.x - 60) {
				if (position.x > App->player->position.x) {
					position.x = position.x - enemy_speed;
					if (currentAnim != &front)
					{
						front.Reset();
						currentAnim = &front;
						Purple_Position = true;
					}
				}

				if (position.x < App->player->position.x) {
					position.x = position.x + enemy_speed;
					if (currentAnim != &back)
					{
						back.Reset();
						currentAnim = &back;
						Purple_Position = false;
					}
				}
				if (position.y != App->player->position.y + 15) {
					if (position.y > App->player->position.y + 15) {
						position.y = position.y - enemy_speed;
					}
					if (position.y < App->player->position.y + 15) {
						position.y = position.y + enemy_speed;
					}
				}

			}
			else {
				follow = false;
			}
		}
		else {
			if (attack == true) {
				if (position.x > App->player->position.x) {
					path[0].Update();
					currentAnim = path[0].GetCurrentAnimation();
					if (currentAnim == &front_iddle) {
						attack = false;
					}
				}
				else {
					path[1].Update();
					currentAnim = path[1].GetCurrentAnimation();
					if (currentAnim == &back_iddle) {
						attack = false;
					}
				}
			}
			else {
				//attack == false;
				if (position.x > App->player->position.x + 100 || position.x < App->player->position.x - 130) {
					num = (rand() % 2);
					follow = true;
				}
				else {
					if (position.x > App->player->position.x) {
						position.x = position.x + enemy_speed;
						currentAnim = &back;
						if (currentAnim != &back)
						{
							back.Reset();
							currentAnim = &back;
							Purple_Position = false;
						}
					}
					else {
						position.x = position.x - enemy_speed;
						currentAnim = &front;
						if (currentAnim != &front)
						{
							front.Reset();
							currentAnim = &front;
							Purple_Position = true;
						}
					}
				}
			}
		}
	}

	if (num == 1) {
		if (follow == true) {
			attack = true;
			if (position.x > App->player->position.x + 120 || position.x < App->player->position.x - 120) {
				if (position.x > App->player->position.x) {
					position.x = position.x - enemy_speed;
					if (currentAnim != &front)
					{
						front.Reset();
						currentAnim = &front;
						Orange_Position = true;
					}
				}

				if (position.x < App->player->position.x) {
					position.x = position.x + enemy_speed;
					if (currentAnim != &back)
					{
						back.Reset();
						currentAnim = &back;
						Orange_Position = false;
					}
				}
				if (position.y != App->player->position.y + 15) {
					if (position.y > App->player->position.y + 15) {
						position.y = position.y - enemy_speed;
					}
					if (position.y < App->player->position.y + 15) {
						position.y = position.y + enemy_speed;
					}
				}

			}
			else {
				follow = false;
			}
		}
		else {
			if (attack == true) {

				if (position.x > App->player->position.x) {
					path[2].Update();
					currentAnim = path[2].GetCurrentAnimation();
					if (currentAnim == &front_iddle) {
						attack = false;
					}
				}
				else {
					path[3].Update();
					currentAnim = path[3].GetCurrentAnimation();
					if (currentAnim == &back_iddle) {
						attack = false;
					}
				}

			}
			else {
				//attack == false;
				if (position.x > App->player->position.x + 180 || position.x < App->player->position.x - 180) {
					num = (rand() % 2);
					follow = true;
				}
				else {
					if (position.x > App->player->position.x) {
						position.x = position.x + enemy_speed;
						currentAnim = &back;
						if (currentAnim != &back)
						{
							back.Reset();
							currentAnim = &back;
							Orange_Position = false;
						}
					}
					else {
						position.x = position.x - enemy_speed;

						currentAnim = &front;
						if (currentAnim != &front)
						{
							front.Reset();
							currentAnim = &front;
							Orange_Position = true;
						}
					}
				}
			}
		}
	}

	/*path.Update();
	position = spawnPos + path.GetRelativePosition();
	currentAnim = path.GetCurrentAnimation();*/

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
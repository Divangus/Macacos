#include "Enemy_Purple.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"


Enemy_Purple::Enemy_Purple(int x, int y) : Enemy(x, y)
{
	//------------------------------------------- Caminar <--
	front.PushBack({ 1032, 1890, 86, 90 });
	front.PushBack({ 946, 1890, 86, 90 });
	front.PushBack({ 860, 1890, 86, 90 });
	front.PushBack({ 774, 1890, 86, 90 });
	front.PushBack({ 688, 1890, 86, 90 });
	front.PushBack({ 602, 1890, 86, 90 });
	front.PushBack({ 516, 1890, 86, 90 });
	front.PushBack({ 430, 1890, 86, 90 });
	front.speed = 0.1f;

	back_iddle.PushBack({ 0, 360, 86, 90 });

	front_iddle.PushBack({ 1032, 1800, 86, 90 });
	
	//------------------------------------------- Caminar -->
	back.PushBack({ 0, 453, 86, 90 });
	back.PushBack({ 86, 453, 86, 90 });
	back.PushBack({ 172, 453, 86, 90 });
	back.PushBack({ 258, 453, 86, 90 });
	back.PushBack({ 344, 453, 86, 90 });
	back.PushBack({ 430, 453, 86, 90 });
	back.PushBack({ 516, 453, 86, 90 });
	back.PushBack({ 602, 453, 86, 90 });
	back.speed = 0.1f;

	//------------------------------------------- Atac <--
	front_punch.PushBack({ 1032, 2790, 86, 90 });
	front_punch.PushBack({ 946, 2790, 86, 90 });
	front_punch.PushBack({ 860, 2790, 86, 90 });
	front_punch.PushBack({ 774, 2790, 86, 90 });
	front_punch.PushBack({ 688, 2790, 86, 90 });
	front_punch.PushBack({ 602, 2790, 86, 90 });
	front_punch.PushBack({ 516, 2790, 86, 90 });
	front_punch.PushBack({ 430, 2790, 86, 90 });
	front_punch.PushBack({ 344, 2790, 86, 90 });
	front_punch.PushBack({ 258, 2790, 86, 90 });
	front_punch.speed = 0.22f;

	front_hit.PushBack({ 1032, 2790, 86, 90 });

	back_hit.PushBack({ 0, 1351, 86, 90 });

	back_punch.PushBack({ 0, 1351, 86, 90 });
	back_punch.PushBack({ 86, 1351, 86, 90 });
	back_punch.PushBack({ 172, 1351, 86, 90 });
	back_punch.PushBack({ 258, 1351, 86, 90 });
	back_punch.PushBack({ 344, 1351, 86, 90 });
	back_punch.PushBack({ 430, 1351, 86, 90 });
	back_punch.PushBack({ 516, 1351, 86, 90 });
	back_punch.PushBack({ 602, 1351, 86, 90 });
	back_punch.PushBack({ 688, 1351, 86, 90 });
	back_punch.PushBack({ 774, 1351, 86, 90 });
	back_punch.speed = 0.22f;

	front_dmg.PushBack({ 1032, 1440, 86, 90 });
	front_dmg.PushBack({ 946, 1440, 86, 90 });
	front_dmg.PushBack({ 860, 1440, 86, 90 });
	front_dmg.PushBack({ 774, 1440, 86, 90 });
	front_dmg.speed = 0.1f;

	front_sdmg.PushBack({ 774, 1440, 86, 90 });

	back_dmg.PushBack({ 0, 0, 86, 90 });
	back_dmg.PushBack({ 86, 0, 86, 90 });
	back_dmg.PushBack({ 172, 0, 86, 90 });
	back_dmg.PushBack({ 258, 0, 86, 90 });
	back_dmg.speed = 0.1f;

	back_sdmg.PushBack({ 258, 0, 86, 90 });
	
	//path.PushBack({ -0.8f, 0.0f }, 150, &front);
	path[0].PushBack({ 0.0f, 0.0f }, 0, &front_hit);
	path[0].PushBack({ 0.0f, 0.0f }, 50, &front_punch);
	path[0].PushBack({ 0.0f, 0.0f }, 0, &front_iddle);
	//path.loop = false;

	path[1].PushBack({ 0.0f, 0.0f }, 0, &back_hit);
	path[1].PushBack({ 0.0f, 0.0f }, 50, &back_punch);
	path[1].PushBack({ 0.0f, 0.0f }, 0, &back_iddle);

	path[2].PushBack({ 0.1f, 0.0f }, 15, &front_dmg);
	path[2].PushBack({ 0.0f, 0.0f }, 0, &front_sdmg);

	path[3].PushBack({ -0.1f, 0.0f }, 15, &back_dmg);
	path[3].PushBack({ 0.0f, 0.0f }, 0, &back_sdmg);
	
	//currentAnim = &front;
	PurpleCollider = App->collisions->AddCollider({0,0, 30, 20}, Collider::Type::ENEMY, (Module*)App->enemies);
	PurpleColliderAttack = App->collisions->AddCollider({ 0, 0, 20, 20 }, Collider::Type::PURPLE_ATTACK, (Module*)App->enemies);
	
}

void Enemy_Purple::Update()
{
	App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::PURPLE_ATTACK] = false;
	if (god == true) {
		if (position.x > App->player->position.x){
			path[2].Update();
			position = position + path[2].GetRelativePosition();
			currentAnim = path[2].GetCurrentAnimation();
			if (currentAnim == &front_sdmg) {
				god = false;
			}
		}
		else {
			path[3].Update();
			position = position + path[3].GetRelativePosition();
			currentAnim = path[3].GetCurrentAnimation();
			if (currentAnim == &back_sdmg) {
				god = false;
			}
		}
	}
	else {
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
				if (position.y != App->player->position.y + 20) {
					if (position.y > App->player->position.y + 20) {
						position.y = position.y - enemy_speed;
					}
					if (position.y < App->player->position.y + 20) {
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
				if (position.x > App->player->position.x + 100 || position.x < App->player->position.x - 120) {
					follow = true;
				}
				else {
					if (position.x > App->player->position.x) {
						position.x = position.x + enemy_speed;
						/*if (position.y < App->player->position.y) {
							position.y = position.y - enemy_speed;
						}
						else {
							position.y = position.y + enemy_speed;
						}*/
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
						/*if (position.y < App->player->position.y) {
							position.y = position.y - enemy_speed;
						}
						else {
							position.y = position.y + enemy_speed;
						}*/

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

	if (currentAnim == &front || currentAnim == &front_punch || currentAnim == &front_hit) {
		Purple_Position = true;
	}

	if (currentAnim == &back || currentAnim == &back_punch || currentAnim == &back_hit) {
		Purple_Position = false;
	}

	if (currentAnim == &front_hit || currentAnim == &back_hit) {
		App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::PURPLE_ATTACK] = true;
	}
	else {
		App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::PURPLE_ATTACK] = false;
	}

	/*path.Update();
	position = spawnPos + path.GetRelativePosition();
	currentAnim = path.GetCurrentAnimation();*/

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}


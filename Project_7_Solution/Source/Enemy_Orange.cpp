#include "Enemy_Orange.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL.h"
//#include "ModulePlayer.h"

Enemy_Orange::Enemy_Orange(int x, int y) : Enemy(x, y)
{
	//Sprite animations
	//Front is left & back is right
	front.PushBack({ 546, 208, 52, 66 });
	front.PushBack({ 458, 208, 52, 66 });
	front.PushBack({ 368, 208, 52, 66 });
	front.PushBack({ 284, 208, 52, 66 });
	front.PushBack({ 194, 208, 52, 66 });
	front.PushBack({ 108, 208, 52, 66 });
	front.PushBack({ 16, 208, 52, 66 });
	front.speed = 0.1f;

	up_front.PushBack({ 552, 276, 42, 66 });
	up_front.PushBack({ 464, 276, 42, 66 });
	up_front.PushBack({ 378, 276, 42, 66 });
	up_front.PushBack({ 292, 276, 42, 66 });
	up_front.PushBack({ 202, 276, 42, 66 });
	up_front.PushBack({ 116, 276, 42, 66 });
	up_front.PushBack({ 28, 276, 42, 66 });
	up_front.speed = 0.1f;

	back.PushBack({ 446, 1015, 52, 66 });
	back.PushBack({ 536, 1015, 52, 66 });
	back.PushBack({ 526, 1015, 52, 66 });
	back.PushBack({ 714, 1015, 52, 66 });
	back.PushBack({ 798, 1015, 52, 66 });
	back.PushBack({ 890, 1015, 52, 66 });
	back.PushBack({ 980, 1015, 52, 66 });
	back.speed = 0.1f;

	up_back.PushBack({ 362, 1084, 42, 66 });
	up_back.PushBack({ 448, 1084, 42, 66 });
	up_back.PushBack({ 538, 1084, 42, 66 });
	up_back.PushBack({ 628, 1084, 42, 66 });
	up_back.PushBack({ 714, 1084, 42, 66 });
	up_back.PushBack({ 804, 1084, 42, 66 });
	up_back.PushBack({ 892, 1084, 42, 66 });
	up_back.PushBack({ 976, 1084, 42, 66 });
	up_back.speed = 0.1f;

	front_iddle.PushBack({ 370, 140, 48, 66 });

	front_shot.PushBack({ 370, 140, 48, 66 });

	back_iddle.PushBack({ 620, 946, 48, 66 });

	back_shot.PushBack({ 620, 946, 48, 66 });

	front_melee_attack.PushBack({ 374, 73, 46, 66 });
	front_melee_attack.PushBack({ 262, 73, 92, 66 });
	front_melee_attack.PushBack({ 194, 73, 54, 66 });
	front_melee_attack.PushBack({ 92, 73, 80, 66 });
	front_melee_attack.PushBack({ 4, 73, 80, 66 });
	front_melee_attack.speed = 0.1f;

	front_gun_attack.PushBack({ 276, 138, 60, 66 });
	front_gun_attack.PushBack({ 188, 138, 58, 66 });
	front_gun_attack.PushBack({ 102, 138, 58, 66 });
	front_gun_attack.PushBack({ 24, 135, 42, 66 });
	front_gun_attack.speed = 0.1f;

	back_melee_attack.PushBack({ 618, 878, 46, 66 });
	back_melee_attack.PushBack({ 686, 878, 92, 66 });
	back_melee_attack.PushBack({ 792, 878, 54, 66 });
	back_melee_attack.PushBack({ 868, 878, 80, 66 });
	back_melee_attack.PushBack({ 954, 878, 80, 66 });
	back_melee_attack.speed = 0.1f;

	back_gun_attack.PushBack({ 704, 944, 60, 66 });
	back_gun_attack.PushBack({ 792, 944, 58, 66 });
	back_gun_attack.PushBack({ 882, 944, 58, 66 });
	back_gun_attack.PushBack({ 976, 946, 42, 66 });
	back_gun_attack.speed = 0.1f;

	front_getting_hit.PushBack({ 188, 12, 58, 66 });
	front_getting_hit.PushBack({ 286, 12, 46, 66 });
	front_getting_hit.PushBack({ 364, 12, 60, 66 });
	front_getting_hit.PushBack({ 456, 12, 48, 66 });
	front_getting_hit.speed = 0.1f;

	back_getting_hit.PushBack({ 792, 818, 58, 66 });
	back_getting_hit.PushBack({ 706, 818, 46, 66 });
	back_getting_hit.PushBack({ 614, 818, 60, 66 });
	back_getting_hit.PushBack({ 534, 818, 48, 66 });
	back_getting_hit.speed = 0.1f;

	//path.PushBack({ 0.0f, -0.0f }, 150, &front_iddle);
	//path.PushBack({ -1.0f, 0.0f }, 150, &front);
	/*path.PushBack({ 0.0f, 0.0f }, 0, &front_iddle);
	path.PushBack({ 0.0f, 0.0f }, 60, &front_gun_attack);*/

	path.PushBack({ 0.0f, 0.0f }, 0, &front_shot);
	path.PushBack({ 0.0f, 0.0f }, 30, &front_gun_attack);
	path.PushBack({ 0.0f, 0.0f }, 0, &front_iddle);

	path1.PushBack({ 0.0f, 0.0f }, 0, &back_shot);
	path1.PushBack({ 0.0f, 0.0f }, 30, &back_gun_attack);
	path1.PushBack({ 0.0f, 0.0f }, 0, &back_iddle);

	//path.PushBack({ 1.0f, 0.0f }, 150, &back);

	OrangeCollider = App->collisions->AddCollider({ 0,0, 30, 20 }, Collider::Type::ENEMY, (Module*)App->enemies);
	OrangeColliderAttack = App->collisions->AddCollider({ 0, 0, 20, 20 }, Collider::Type::ORANGE_ATTACK, (Module*)App->enemies);
	

}

void Enemy_Orange::Update()
{
	App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ORANGE_ATTACK] = false;

	if (currentAnim == &back) {
		Orange_Position = false;
	}
	else {
		Orange_Position = true;
	}

	if (currentAnim == &front_melee_attack) {
		App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ORANGE_ATTACK] = true;
	}
	else {
		App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ORANGE_ATTACK] = false;
	}

		if (currentAnim == &front_shot)
	{
		App->particles->shot.speed.x = -1;
		App->particles->AddParticle(App->particles->shot, position.x - 20, position.y + 20, 1, Collider::Type::ENEMY_SHOT);
		//Orange_Position = true;
	}

	if (currentAnim == &back_shot)
	{
		App->particles->shot.speed.x = 1;
		App->particles->AddParticle(App->particles->shot, position.x + 20, position.y + 20, 1, Collider::Type::ENEMY_SHOT);
		//Orange_Position = false;
	}

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
			if (position.y != App->player->position.y + 46) {
				if (position.y > App->player->position.y + 46) {
					position.y = position.y - enemy_speed;
				}
				if (position.y < App->player->position.y + 46) {
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
			//if (position.x > App->player->position.x) {
			//	path.Update();
			//	currentAnim = path.GetCurrentAnimation();
			//}
			//if (position.x < App->player->position.x){
			//	path1.Update();
			//	currentAnim = path1.GetCurrentAnimation();
			//}
			//
			//if (path.GetCurrentAnimation() == &front_iddle /*|| path1.GetCurrentAnimation() == &back_iddle*/) {
			//	attack = false;
			//}
			//if (path1.GetCurrentAnimation() == &back_iddle) {
			//	attack = false;
			//}
			if (Orange_Position == true) {
				/*App->particles->shot.speed.x = -1;
				App->particles->AddParticle(App->particles->shot, position.x - 20, position.y + 20, 1, Collider::Type::ENEMY_SHOT);*/
				path.Update();
				currentAnim = path.GetCurrentAnimation();
				if (currentAnim == &front_iddle) {
					attack = false;
				}		
			}
			else {
				/*App->particles->shot.speed.x = 1;
				App->particles->AddParticle(App->particles->shot, position.x + 20, position.y + 20, 1, Collider::Type::ENEMY_SHOT);*/
				path1.Update();
				currentAnim = path1.GetCurrentAnimation();
				if (currentAnim == &back_iddle) {
					attack = false;
				}
			}
			
		}
		else {
			//attack == false;
			if (position.x > App->player->position.x + 180 || position.x < App->player->position.x - 180) {
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
						Orange_Position = false;
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
						Orange_Position = true;
					}
				}
			}
		}
	}
	
	
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
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

	path.PushBack({ 0.0f, 0.0f }, 50, &front_iddle);
	path.PushBack({ -0.8f, -0.5f }, 120, &front);
	path.PushBack({ 0.0f, 0.0f }, 50, &front_iddle);
	path.PushBack({ 0.0f, 0.0f }, 50, &front_melee_knife);
	path.PushBack({ 0.0f, 0.0f }, 50, &back_iddle);
	path.PushBack({ 0.0f, 0.0f }, 50, &back_melee_knife);
	path.PushBack({ 0.0f, 0.0f }, 0, &front_shot);
	path.PushBack({ 0.0f, 0.0f }, 50, &front_knife);
	path.PushBack({ 0.0f, 0.0f }, 0, &back_shot);
	path.PushBack({ 0.0f, 0.0f }, 50, &back_knife);
	path.PushBack({ 0.8f, 0.5f }, 120, &back);
	path.PushBack({ 0.0f, 0.0f }, 50, &back_iddle);

	WhiteCollider = App->collisions->AddCollider({ 0,0, 30, 20 }, Collider::Type::ENEMY, (Module*)App->enemies);
	WhiteColliderAttack = App->collisions->AddCollider({ 0, 0, 20, 20 }, Collider::Type::WHITE_ATTACK, (Module*)App->enemies);


}

void Enemy_White::Update()
{
	App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::WHITE_ATTACK] = false;

	if (currentAnim == &back || currentAnim == &back_melee_knife || currentAnim == &back_iddle || currentAnim == &back_knife) {
		White_Position = false;
	}
	else {
		White_Position = true;
	}

	if (currentAnim == &front_melee_knife || currentAnim == &back_melee_knife) {
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

	path.Update();
	position = spawnPos + path.GetRelativePosition();
	currentAnim = path.GetCurrentAnimation();


	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
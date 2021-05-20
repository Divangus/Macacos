#include "Enemy_Purple.h"

#include "Application.h"
#include "ModuleCollisions.h"

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

	
	path.PushBack({ -0.8f, 0.0f }, 150, &front);
	path.PushBack({ 0.0f, 0.0f }, 50, &front_punch);
	path.PushBack({ 0.8f, 0.0f }, 150, &back);
	

	collider = App->collisions->AddCollider({0,0, 30, 20}, Collider::Type::ENEMY, (Module*)App->enemies);
	colliderAttack = App->collisions->AddCollider({ 0, 0, 20, 20 }, Collider::Type::PURPLE_ATTACK, (Module*)App->enemies);
	
}

void Enemy_Purple::Update()
{
	App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::PURPLE_ATTACK] = false;
	
	if (currentAnim == &front_punch) {
		App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::PURPLE_ATTACK] = true;
	}
	else {
		App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::PURPLE_ATTACK] = false;
	}

	path.Update();
	position = spawnPos + path.GetRelativePosition();
	currentAnim = path.GetCurrentAnimation();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
#include "Enemy_Purple.h"

#include "Application.h"
#include "ModuleCollisions.h"

Enemy_Purple::Enemy_Purple(int x, int y) : Enemy(x, y)
{
	front.PushBack({ 0, 26, 70, 75 });
	front.PushBack({ 84, 26, 70, 75 });
	front.PushBack({ 178, 26, 70, 75 });
	front.PushBack({ 257, 26, 70, 75 });
	front.PushBack({ 355, 26, 70, 75 });
	front.PushBack({ 444, 26, 70, 75 });
	front.PushBack({ 535, 26, 70, 75 });
	front.PushBack({ 625, 26, 70, 75 });
	front.speed = 0.1f;
	//front.pingpong = true;

	back.PushBack({ 981, 1050, 43, 75 });
	back.PushBack({ 888, 1050, 70, 75 });
	back.PushBack({ 789, 1050, 70, 75 });
	back.PushBack({ 705, 1050, 70, 75 });
	back.PushBack({ 621, 1050, 70, 75 });
	back.PushBack({ 526, 1050, 70, 75 });
	back.PushBack({ 431, 1050, 70, 75 });
	back.PushBack({ 349, 1050, 70, 75 });
	back.speed = 0.1f;
	//back.pingpong = true;

	path.PushBack({ -0.3f, 0.0f }, 150, &front);
	path.PushBack({ 1.2f, 0.0f }, 150, &back);

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_Purple::Update()
{
	path.Update();
	position = spawnPos + path.GetRelativePosition();
	currentAnim = path.GetCurrentAnimation();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
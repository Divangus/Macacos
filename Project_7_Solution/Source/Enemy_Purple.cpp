#include "Enemy_Purple.h"

#include "Application.h"
#include "ModuleCollisions.h"

Enemy_Purple::Enemy_Purple(int x, int y) : Enemy(x, y)
{
	front.PushBack({ 7, 21, 34, 42 });
	front.PushBack({ 53, 20, 37, 43 });
	front.PushBack({ 99, 19, 45, 48 });
	front.PushBack({ 151, 19, 43, 49 });
	front.PushBack({ 203, 20, 36, 48 });
	front.PushBack({ 6, 69, 35, 44 });
	front.PushBack({ 49, 70, 44, 44 });
	front.PushBack({ 103, 69, 40, 45 });
	front.speed = 0.1f;
	//front.pingpong = true;

	back.PushBack({ 170, 108, 31, 29 });
	back.PushBack({ 170, 141, 31, 29 });
	back.PushBack({ 137, 108, 31, 29 });
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
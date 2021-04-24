#include "Enemy_Purple.h"

#include "Application.h"
#include "ModuleCollisions.h"

Enemy_Purple::Enemy_Purple(int x, int y) : Enemy(x, y)
{
	front.PushBack({ 10, 1, 40, 46 });
	front.PushBack({ 56, 1, 40, 46 });
	front.PushBack({ 108, 1, 40, 46 });
	front.PushBack({ 161, 1, 40, 46 });
	front.PushBack({ 214, 1, 40, 46 });
	front.PushBack({ 12, 50, 40, 46 });
	front.PushBack({ 60, 50, 40, 46 });
	front.PushBack({ 112, 50, 40, 46 });
	front.speed = 0.1f;
	//front.pingpong = true;

	back.PushBack({ 213, 546, 40, 46 });
	back.PushBack({ 163, 546, 40, 46 });
	back.PushBack({ 111, 546, 40, 46 });
	back.PushBack({ 62, 546, 40, 46 });
	back.PushBack({ 18, 546, 40, 46 });
	back.PushBack({ 211, 596, 40, 46 });
	back.PushBack({ 160, 596, 40, 46 });
	back.PushBack({ 112, 596, 40, 46 });
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
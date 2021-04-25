#include "Enemy_Orange.h"

#include "Application.h"
#include "ModuleCollisions.h"

Enemy_Orange::Enemy_Orange(int x, int y) : Enemy(x, y)
{
	front.PushBack({ 266, 592, 40, 60 });
	front.PushBack({ 192, 592, 40, 60 });
	front.PushBack({ 264, 592, 40, 60 });
	front.PushBack({ 264, 592, 40, 60 });
	front.PushBack({ 264, 518, 40, 60 });
	front.PushBack({ 264, 518, 40, 60 });
	front.PushBack({ 264, 518, 40, 60 });
	front.PushBack({ 264, 518, 40, 60 });
	front.PushBack({ 264, 518, 40, 60 });
	front.speed = 0.1f;
	//front.pingpong = true;

	back.PushBack({ 170, 108, 40, 60 });
	back.PushBack({ 170, 141, 40, 60 });
	back.PushBack({ 137, 108, 40, 60 });
	back.speed = 0.1f;
	//back.pingpong = true;

	path.PushBack({ -0.3f, 0.0f }, 150, &front);
	path.PushBack({ 1.2f, 0.0f }, 150, &back);

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_Orange::Update()
{
	path.Update();
	position = spawnPos + path.GetRelativePosition();
	currentAnim = path.GetCurrentAnimation();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}

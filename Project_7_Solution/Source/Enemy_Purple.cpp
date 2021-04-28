#include "Enemy_Purple.h"

#include "Application.h"
#include "ModuleCollisions.h"

Enemy_Purple::Enemy_Purple(int x, int y) : Enemy(x, y)
{
	
	front.PushBack({ 1032, 1890, 86, 90 });
	front.PushBack({ 946, 1890, 86, 90 });
	front.PushBack({ 860, 1890, 86, 90 });
	front.PushBack({ 774, 1890, 86, 90 });
	front.PushBack({ 688, 1890, 86, 90 });
	front.PushBack({ 602, 1890, 86, 90 });
	front.PushBack({ 516, 1890, 86, 90 });
	front.PushBack({ 430, 1890, 86, 90 });
	front.speed = 0.1f;

	/*stop.PushBack({ 1032,2340,86,90 });
	stop.speed = 0.0f;*/
	
	back.PushBack({ 0, 453, 86, 90 });
	back.PushBack({ 86, 453, 86, 90 });
	back.PushBack({ 172, 453, 86, 90 });
	back.PushBack({ 258, 453, 86, 90 });
	back.PushBack({ 344, 453, 86, 90 });
	back.PushBack({ 430, 453, 86, 90 });
	back.PushBack({ 516, 453, 86, 90 });
	back.PushBack({ 602, 453, 86, 90 });
	back.speed = 0.1f;

	/*front_hit.PushBack({ 0, 1583, 75, 75 });
	front_hit.PushBack({ 0, 1583, 75, 75 });
	front_hit.PushBack({ 0, 1583, 75, 75 });
	front_hit.PushBack({ 0, 1583, 75, 75 });
	front_hit.PushBack({ 0, 1583, 75, 75 });
	front_hit.PushBack({ 0, 1583, 75, 75 });
	front_hit.PushBack({ 0, 1583, 75, 75 });
	front_hit.PushBack({ 0, 1583, 75, 75 });
	front_hit.PushBack({ 0, 1583, 75, 75 });
	front_hit.speed = 0.1f;*/

	/*front_hit_ground.PushBack({ 972, 1678, 90, 90 });
	front_hit_ground.PushBack({ 873, 1678, 90, 90 });
	front_hit_ground.PushBack({ 776, 1678, 90, 90 });
	front_hit_ground.PushBack({ 687, 1678, 90, 90 });
	front_hit_ground.PushBack({ 589, 1678, 90, 90 });
	front_hit_ground.speed = 0.07f;

	front_ground.PushBack({ 589, 1678, 90, 90 });
	front_ground.speed = 0.0f;

	front_recovery.PushBack({ 495, 1678, 90, 90 });
	front_recovery.PushBack({ 406, 1678, 90, 90 });
	front_recovery.PushBack({ 326, 1678, 90, 90 });
	front_recovery.PushBack({ 235, 1678, 90, 90 });
	front_recovery.PushBack({ 148, 1678, 90, 90 });
	front_recovery.PushBack({ 68, 1678, 90, 90 });
	front_recovery.speed = 0.09f;

	front_hit_ground_behind.PushBack({ 950, 1766, 90, 90 });
	front_hit_ground_behind.PushBack({ 864, 1766, 90, 90 });
	front_hit_ground_behind.PushBack({ 784, 1766, 90, 90 });
	front_hit_ground_behind.PushBack({ 685, 1766, 90, 90 });
	front_hit_ground_behind.speed = 0.07f;

	front_ground_behind.PushBack({ 574, 1766, 90, 90 });
	front_ground_behind.speed = 0.0f;

	front_recovery_behind.PushBack({ 501, 1766, 90, 90 });
	front_recovery_behind.PushBack({ 411, 1766, 90, 90 });
	front_recovery_behind.PushBack({ 327, 1766, 90, 90 });
	front_recovery_behind.PushBack({ 251, 1766, 90, 90 });
	front_recovery_behind.PushBack({ 164, 1766, 90, 90 });
	front_recovery_behind.speed = 0.08f;*/

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
	/*path.PushBack({ 0.0f, 0.0f }, 150, &stop);*/

	/*path.PushBack({ -0.3f, 0.0f }, 150, &front);
	path.PushBack({ 0.2f, 0.0f }, 30, &front_hit_ground);
	path.PushBack({ 0.0f, 0.0f }, 60, &front_ground);
	path.PushBack({ 0.0f, 0.0f }, 60, &front_recovery);
	path.PushBack({ 0.0f, 0.0f }, 120, &front_punch);
	path.PushBack({ 0.3f, 0.0f }, 150, &back);
	path.PushBack({ -0.3f, 0.0f }, 30, &front);
	path.PushBack({ -0.2f, 0.0f }, 40, &front_hit_ground_behind);
	path.PushBack({ 0.0f, 0.0f }, 60, &front_ground_behind);
	path.PushBack({ 0.0f, 0.0f }, 60, &front_recovery_behind);
	path.PushBack({ 0.3f, 0.0f }, 150, &back);*/
	

	collider = App->collisions->AddCollider({0, 0, 35, 70 }, Collider::Type::ENEMY, (Module*)App->enemies);
	
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
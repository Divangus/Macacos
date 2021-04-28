#include "Enemy_Purple.h"

#include "Application.h"
#include "ModuleCollisions.h"

Enemy_Purple::Enemy_Purple(int x, int y) : Enemy(x, y)
{
	
	front.PushBack({ 630, 20, 41, 70 });
	front.PushBack({ 540, 20, 45, 70 });
	front.PushBack({ 450, 20, 40, 70 });
	front.PushBack({ 360, 20, 27, 70 });
	front.PushBack({ 270, 20, 39, 70 });
	front.PushBack({ 180, 20, 48, 70 });
	front.PushBack({ 90, 20, 38, 70 });
	front.PushBack({ 0, 20, 36, 70 });
	front.speed = 0.1f;

	/*stop.PushBack({ 351, 384, 47, 71 });
	stop.speed = 0.0f;*/

	back.PushBack({ 352, 1044, 42, 70 });
	back.PushBack({ 438, 1044, 46, 70 });
	back.PushBack({ 534, 1044, 40, 70 });
	back.PushBack({ 636, 1044, 28, 70 });
	back.PushBack({ 714, 1044, 40, 70 });
	back.PushBack({ 795, 1044, 49, 70 });
	back.PushBack({ 895, 1044, 39, 70 });
	back.PushBack({ 988, 1044, 36, 70 });
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

	front_hit_ground.PushBack({ 972, 1678, 90, 90 });
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
	front_recovery_behind.speed = 0.08f;

	front_punch.PushBack({ 986, 1880, 38, 70 });
	front_punch.PushBack({ 892, 1880, 42, 70 });
	front_punch.PushBack({ 810, 1880, 34, 70 });
	front_punch.PushBack({ 705, 1880, 49, 70 });
	front_punch.PushBack({ 619, 1880, 45, 70 });
	front_punch.PushBack({ 540, 1880, 34, 70 });
	front_punch.PushBack({ 442, 1880, 42, 70 });
	front_punch.PushBack({ 366, 1880, 31, 70 });
	front_punch.PushBack({ 243, 1880, 61, 70 });
	front_punch.PushBack({ 174, 1880, 40, 70 });
	front_punch.speed = 0.22f;

	
	path.PushBack({ -0.8f, 0.0f }, 150, &front);
	//path.PushBack({ 0.0f, 0.0f }, 50, &front_punch);
	path.PushBack({ 0.8f, 0.0f }, 150, &back);
	//path.PushBack({ 0.0f, 0.0f }, 150, &stop);

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
	

	collider = App->collisions->AddCollider({ 0, 0, 50, 70 }, Collider::Type::ENEMY, (Module*)App->enemies);
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
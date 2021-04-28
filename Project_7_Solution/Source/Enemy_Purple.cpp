#include "Enemy_Purple.h"

#include "Application.h"
#include "ModuleCollisions.h"

Enemy_Purple::Enemy_Purple(int x, int y) : Enemy(x, y)
{
	
	front.PushBack({ 630, 0, 41, 90 });
	front.PushBack({ 540, 0, 45, 90 });
	front.PushBack({ 450, 0, 40, 90 });
	front.PushBack({ 360, 0, 27, 90 });
	front.PushBack({ 270, 0, 39, 90 });
	front.PushBack({ 180, 0, 48, 90 });
	front.PushBack({ 90, 0, 38, 90 });
	front.PushBack({ 0, 0, 36, 90 });
	front.speed = 0.1f;

	/*stop.PushBack({ 351, 384, 47, 71 });
	stop.speed = 0.0f;*/

	back.PushBack({ 352, 1024, 42, 90 });
	back.PushBack({ 438, 1024, 46, 90 });
	back.PushBack({ 534, 1024, 40, 90 });
	back.PushBack({ 636, 1024, 28, 90 });
	back.PushBack({ 714, 1024, 40, 90 });
	back.PushBack({ 795, 1024, 49, 90 });
	back.PushBack({ 895, 1024, 39, 90 });
	back.PushBack({ 988, 1024, 36, 90 });
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

	front_punch.PushBack({ 986, 1860, 38, 90 });
	front_punch.PushBack({ 892, 1860, 42, 90 });
	front_punch.PushBack({ 810, 1860, 34, 90 });
	front_punch.PushBack({ 705, 1860, 49, 90 });
	front_punch.PushBack({ 619, 1860, 45, 90 });
	front_punch.PushBack({ 540, 1860, 34, 90 });
	front_punch.PushBack({ 442, 1860, 42, 90 });
	front_punch.PushBack({ 366, 1860, 31, 90 });
	front_punch.PushBack({ 243, 1860, 61, 90 });
	front_punch.PushBack({ 174, 1860, 40, 90 });
	front_punch.speed = 0.22f;

	
	path.PushBack({ -0.8f, 0.0f }, 150, &front);
	path.PushBack({ 0.0f, 0.0f }, 50, &front_punch);
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
	

	collider = App->collisions->AddCollider({ 0, 0, 50, 63 }, Collider::Type::ENEMY, (Module*)App->enemies);
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
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

	front_hit_ground.PushBack({ 972, 1678, 52, 78});
	front_hit_ground.PushBack({ 873, 1678, 92, 78 });
	front_hit_ground.PushBack({ 776, 1678, 92, 78 });
	front_hit_ground.PushBack({ 687, 1678, 92, 78 });
	front_hit_ground.PushBack({ 589, 1678, 92, 78 });
	front_hit_ground.speed = 0.07f;

	front_ground.PushBack({ 589, 1678, 92, 78 });
	front_ground.speed = 0.0f;

	front_recovery.PushBack({ 495, 1678, 92, 78 });
	front_recovery.PushBack({ 406, 1678, 92, 78 });
	front_recovery.PushBack({ 326, 1678, 92, 78 });
	front_recovery.PushBack({ 235, 1678, 92, 78 });
	front_recovery.PushBack({ 148, 1678, 92, 78 });
	front_recovery.PushBack({ 68, 1678, 92, 78 });
	front_recovery.speed = 0.09f;

	front_hit_ground_behind.PushBack({ 950, 1766, 74, 86 });
	front_hit_ground_behind.PushBack({ 864, 1766, 74, 86 });
	front_hit_ground_behind.PushBack({ 784, 1766, 74, 86 });
	front_hit_ground_behind.PushBack({ 685, 1766, 74, 86 });
	front_hit_ground_behind.speed = 0.07f;

	front_ground_behind.PushBack({ 574, 1766, 94, 86 });
	front_ground_behind.speed = 0.0f;

	front_recovery_behind.PushBack({ 501, 1766, 74, 86 });
	front_recovery_behind.PushBack({ 411, 1766, 74, 86 });
	front_recovery_behind.PushBack({ 327, 1766, 74, 86 });
	front_recovery_behind.PushBack({ 251, 1766, 74, 86 });
	front_recovery_behind.PushBack({ 164, 1766, 74, 86 });
	front_recovery_behind.speed = 0.08f;

	front_punch.PushBack({ 973, 1872, 51, 84 });
	front_punch.PushBack({ 877, 1872, 84, 84 });
	front_punch.PushBack({ 792, 1872, 84, 84 });
	front_punch.PushBack({ 696, 1872, 84, 84 });
	front_punch.PushBack({ 606, 1872, 84, 84 });
	front_punch.PushBack({ 519, 1872, 84, 84 });
	front_punch.PushBack({ 423, 1872, 84, 84 });
	front_punch.PushBack({ 333, 1872, 84, 84 });
	front_punch.PushBack({ 233, 1872, 84, 84 });
	front_punch.PushBack({ 149, 1872, 84, 84 });
	front_punch.speed = 0.2f;

	
	path.PushBack({ -0.3f, 0.0f }, 150, &front);
	path.PushBack({ 0.0f, 0.0f }, 60, &front_punch);
	path.PushBack({ 0.3f, 0.0f }, 150, &back);

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
	

	collider = App->collisions->AddCollider({ 0, 0, 70, 75 }, Collider::Type::ENEMY, (Module*)App->enemies);
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
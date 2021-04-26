#include "Enemy_Orange.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"

Enemy_Orange::Enemy_Orange(int x, int y) : Enemy(x, y)
{
	//Sprite animations
	//Front is left & back is right
	front.PushBack({ 546, 208, 52, 66 });
	front.PushBack({ 458, 208, 52, 66 });
	front.PushBack({ 368, 208, 52, 66 });
	front.PushBack({ 284, 208, 52, 66 });
	front.PushBack({ 194, 208, 52, 66 });
	front.PushBack({ 108, 208, 52, 66 });
	front.PushBack({ 16, 208, 52, 66 });
	front.speed = 0.1f;

	up_front.PushBack({ 552, 276, 42, 66 });
	up_front.PushBack({ 464, 276, 42, 66 });
	up_front.PushBack({ 378, 276, 42, 66 });
	up_front.PushBack({ 292, 276, 42, 66 });
	up_front.PushBack({ 202, 276, 42, 66 });
	up_front.PushBack({ 116, 276, 42, 66 });
	up_front.PushBack({ 28, 276, 42, 66 });
	up_front.speed = 0.1f;

	back.PushBack({ 446, 1015, 52, 66 });
	back.PushBack({ 536, 1015, 52, 66 });
	back.PushBack({ 526, 1015, 52, 66 });
	back.PushBack({ 714, 1015, 52, 66 });
	back.PushBack({ 798, 1015, 52, 66 });
	back.PushBack({ 890, 1015, 52, 66 });
	back.PushBack({ 980, 1015, 52, 66 });
	back.speed = 0.1f;

	up_back.PushBack({ 362, 1084, 42, 66 });
	up_back.PushBack({ 448, 1084, 42, 66 });
	up_back.PushBack({ 538, 1084, 42, 66 });
	up_back.PushBack({ 628, 1084, 42, 66 });
	up_back.PushBack({ 714, 1084, 42, 66 });
	up_back.PushBack({ 804, 1084, 42, 66 });
	up_back.PushBack({ 892, 1084, 42, 66 });
	up_back.PushBack({ 976, 1084, 42, 66 });
	up_back.speed = 0.1f;

	front_iddle.PushBack({ 370, 140, 48, 66 });

	back_iddle.PushBack({ 620, 946, 48, 66 });

	front_melee_attack.PushBack({ 374, 75, 46, 64 });
	front_melee_attack.PushBack({ 262, 75, 92, 64 });
	front_melee_attack.PushBack({ 194, 75, 54, 64 });
	front_melee_attack.PushBack({ 92, 75, 80, 64 });
	front_melee_attack.PushBack({ 4, 75, 80, 64 });
	front_melee_attack.speed = 0.1f;

	front_gun_attack.PushBack({ 276, 140, 60, 64 });
	front_gun_attack.PushBack({ 188, 140, 58, 64 });
	front_gun_attack.PushBack({ 102, 140, 58, 64 });
	front_gun_attack.PushBack({ 24, 135, 42, 66 });
	front_gun_attack.speed = 0.1f;

	back_melee_attack.PushBack({ 618, 880, 46, 64 });
	back_melee_attack.PushBack({ 686, 880, 92, 64 });
	back_melee_attack.PushBack({ 792, 880, 54, 64 });
	back_melee_attack.PushBack({ 868, 880, 80, 64 });
	back_melee_attack.PushBack({ 954, 880, 80, 64 });
	back_melee_attack.speed = 0.1f;

	back_gun_attack.PushBack({ 704, 946, 60, 64 });
	back_gun_attack.PushBack({ 792, 946, 58, 64 });
	back_gun_attack.PushBack({ 882, 946, 58, 64 });
	back_gun_attack.PushBack({ 976, 946, 42, 66 });
	back_gun_attack.speed = 0.1f;

	front_getting_hit.PushBack({ 188, 12, 58, 66 });
	front_getting_hit.PushBack({ 286, 12, 46, 66 });
	front_getting_hit.PushBack({ 364, 12, 60, 66 });
	front_getting_hit.PushBack({ 456, 12, 48, 66 });
	front_getting_hit.speed = 0.1f;

	back_getting_hit.PushBack({ 792, 818, 58, 66 });
	back_getting_hit.PushBack({ 706, 818, 46, 66 });
	back_getting_hit.PushBack({ 614, 818, 60, 66 });
	back_getting_hit.PushBack({ 534, 818, 48, 66 });
	back_getting_hit.speed = 0.1f;

	path.PushBack({ 0.0f, -0.0f }, 150, &front_iddle);

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

int Enemy_Orange::GetPosition_x() {
	return position.x;
}

int Enemy_Orange::GetPosition_y() {
	return position.y;
}
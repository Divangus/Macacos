#include "Enemy_Boss.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "SDL/include/SDL.h"
//#include "ModulePlayer.h"

Enemy_Boss::Enemy_Boss(int x, int y) : Enemy(x, y)
{
	//Sprite animations
	//Front is left & back is right
	back_iddle.PushBack({ 0, 0, 44, 70 });
	back_iddle.PushBack({ 44, 0, 48, 70 });
	back_iddle.PushBack({ 92, 0, 53, 70 });
	back_iddle.PushBack({ 145, 0, 43, 70 });
	back_iddle.PushBack({ 188, 0, 49, 70 });
	back_iddle.PushBack({ 237, 0, 53, 70 });
	back_iddle.speed = 0.1f;

	back.PushBack({ 5, 74, 47, 70 });
	back.PushBack({ 52, 74, 48, 70 });
	back.PushBack({ 100, 74, 46, 70 });
	back.PushBack({ 146, 74, 38, 70 });
	back.PushBack({ 184, 74, 37, 70 });
	back.PushBack({ 221, 74, 33, 70 });
	back.speed = 0.1f;

	front_iddle.PushBack({ 468, 830, 44, 70 });
	front_iddle.PushBack({ 420, 830, 48, 70 });
	front_iddle.PushBack({ 367, 830, 53, 70 });
	front_iddle.PushBack({ 324, 830, 43, 70 });
	front_iddle.PushBack({ 275, 830, 49, 70 });
	front_iddle.PushBack({ 222, 830, 53, 70 });
	front_iddle.speed = 0.1f;

	front.PushBack({ 460, 908, 47, 70 });
	front.PushBack({ 412, 908, 48, 70 });
	front.PushBack({ 366, 908, 46, 70 });
	front.PushBack({ 328, 908, 38, 70 });
	front.PushBack({ 291, 908, 37, 70 });
	front.PushBack({ 258, 908, 33, 70 });
	front.speed = 0.1f;

	//Charge attack


	//Kick


	//Getting hit


	//Spawn gun


	//Gun walk


	//Gun walk and aiming


	//Shooting


	//Kick with gun


	//Getting hit with gun

	OrangeCollider = App->collisions->AddCollider({ 0,0, 30, 20 }, Collider::Type::ENEMY, (Module*)App->enemies);
	OrangeColliderAttack = App->collisions->AddCollider({ 0, 0, 20, 20 }, Collider::Type::BOSS_ATTACK, (Module*)App->enemies);
}

void Enemy_Boss::Update()
{

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
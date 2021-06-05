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
	

	OrangeCollider = App->collisions->AddCollider({ 0,0, 30, 20 }, Collider::Type::ENEMY, (Module*)App->enemies);
	OrangeColliderAttack = App->collisions->AddCollider({ 0, 0, 20, 20 }, Collider::Type::BOSS_ATTACK, (Module*)App->enemies);
}

void Enemy_Boss::Update()
{

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
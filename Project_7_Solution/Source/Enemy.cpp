#include "Enemy.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "Enemy_Purple.h"
#include "Enemy_Orange.h"

Enemy::Enemy(int x, int y) : position(x, y)
{
	spawnPos = position;
}

Enemy::~Enemy()
{
	if (PurpleCollider != nullptr)
		PurpleCollider->pendingToDelete = true;
	if (PurpleColliderAttack != nullptr)
		PurpleColliderAttack->pendingToDelete = true;
	if (OrangeCollider != nullptr)
		OrangeCollider->pendingToDelete = true;
	if (OrangeColliderAttack != nullptr)
		OrangeColliderAttack->pendingToDelete = true;
	if (WhiteCollider != nullptr)
		WhiteCollider->pendingToDelete = true;
	if (WhiteColliderAttack != nullptr)
		WhiteColliderAttack->pendingToDelete = true;
}

const Collider* Enemy::GetCollider() const {
	if (EnemyType == 1) {
		return PurpleCollider;
	}
	if (EnemyType == 2) {
		return OrangeCollider;
	}
	if (EnemyType == 3) {
		return WhiteCollider;
	}
}

void Enemy::Update()
{
	if (currentAnim != nullptr)
		currentAnim->Update();

	if (PurpleCollider != nullptr)
		PurpleCollider->SetPos(position.x+28, position.y+66);
	
	if (OrangeCollider != nullptr)
		OrangeCollider->SetPos(position.x + 8, position.y + 46);

	if (WhiteCollider != nullptr)
		WhiteCollider->SetPos(position.x + 27, position.y + 75);
	
	if (PurpleColliderAttack != nullptr && Purple_Position == true)
		PurpleColliderAttack->SetPos(position.x+20, position.y+66);
	
	else if (PurpleColliderAttack != nullptr && Purple_Position == false)
		PurpleColliderAttack->SetPos(position.x + 50, position.y + 66);

	if (OrangeColliderAttack != nullptr && Orange_Position == true)
		OrangeColliderAttack->SetPos(position.x + 0, position.y + 46);

	else if (OrangeColliderAttack != nullptr && Orange_Position == false)
		OrangeColliderAttack->SetPos(position.x + 30, position.y + 46);

	if (WhiteColliderAttack != nullptr && White_Position == true)
		WhiteColliderAttack->SetPos(position.x + 19, position.y + 75);

	else if (WhiteColliderAttack != nullptr && White_Position == false)
		WhiteColliderAttack->SetPos(position.x + 49, position.y + 75);
}

void Enemy::Draw()
{
	if (currentAnim != nullptr)
		App->render->Blit(texture, position.x, position.y, &(currentAnim->GetCurrentFrame()));
}

void Enemy::OnCollision(Collider* collider)
{
	HP -= 1;
	if (HP == 0) {

		App->audio->PlayFx(destroyedFx);

		destroyed = true;
	}
}
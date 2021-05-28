#include "Enemy.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"

Enemy::Enemy(int x, int y) : position(x, y)
{
	spawnPos = position;
}

Enemy::~Enemy()
{
	if (collider != nullptr)
		collider->pendingToDelete = true;
	if (colliderAttack != nullptr)
		colliderAttack->pendingToDelete = true;
}

const Collider* Enemy::GetCollider() const
{
	return collider;
}

void Enemy::Update()
{
	if (currentAnim != nullptr)
		currentAnim->Update();

	if (collider != nullptr)
		collider->SetPos(position.x+28, position.y+66);
	
	if (colliderAttack != nullptr && Purple_Position == true)
		colliderAttack->SetPos(position.x+20, position.y+66);
	
	else if (colliderAttack != nullptr && Purple_Position == false)
		colliderAttack->SetPos(position.x + 50, position.y + 66);

	if (colliderAttack != nullptr && Orange_Position == true)
		colliderAttack->SetPos(position.x + 20, position.y + 66);

	else if (colliderAttack != nullptr && Orange_Position == false)
		colliderAttack->SetPos(position.x + 50, position.y + 66);
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
		App->particles->AddParticle(App->particles->explosion, position.x, position.y);
		App->audio->PlayFx(destroyedFx);

		destroyed = true;
	}
}
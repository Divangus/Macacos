#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider;

class Enemy
{
public:
	// Constructor
	// Saves the spawn position for later movement calculations
	Enemy(int x, int y);

	// Destructor
	virtual ~Enemy();

	// Returns the enemy's collider
	const Collider* GetCollider() const;

	// Called from inhering enemies' Udpate
	// Updates animation and collider position
	virtual void Update();

	// Called from ModuleEnemies' Update
	virtual void Draw();

	// Collision response
	// Triggers an animation and a sound fx
	virtual void OnCollision(Collider* collider);

public:
	// The current position in the world
	fPoint position;
	float enemy_speed = 0.8;
	int life = 3;
	bool god = false;

	// The enemy's texture
	SDL_Texture* texture = nullptr;

	// Sound fx when destroyed
	int destroyedFx = 0;

	int EnemyType = 0;

	bool destroyed = false;

protected:

	bool Purple_Position = true;
	bool Orange_Position = true;
	bool White_Position = true;
	bool Boss_Position = true;

	// A ptr to the current animation
	Animation* currentAnim = nullptr;

	

	// The enemy's collider
	Collider* PurpleCollider = nullptr;
	Collider* PurpleColliderAttack = nullptr;
	Collider* OrangeCollider = nullptr;
	Collider* OrangeColliderAttack = nullptr;
	Collider* WhiteCollider = nullptr;
	Collider* WhiteColliderAttack = nullptr;
	Collider* BossCollider = nullptr;
	Collider* BossColliderAttack = nullptr;

	// Original spawn position. Stored for movement calculations
	fPoint spawnPos;

	int HP = 3;

	
};

#endif // __ENEMY_H__
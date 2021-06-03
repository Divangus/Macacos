#ifndef __MODULE_ENTITIES_H__
#define __MODULE_ENTITIES_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

class ModuleEntities :public Module {
public:
	// Constructor
	ModuleEntities(bool startEnabled);

	// Destructor
	~ModuleEntities();

	//virtual int HP;

	bool destroyed = false;

	int position;
};

class Player :public ModuleEntities {
public:
	Player(bool startEnabled);

	~Player();

	void GodMode();

private:

	// The speed in which we move the player (pixels per frame)
	int speed = 1;

	bool Player_Position;


	// The player spritesheet loaded into an SDL_Texture
	SDL_Texture* texture = nullptr;

	SDL_Texture* QuoteTexture = nullptr;

	SDL_Texture* FireAnimTexture = nullptr;

	SDL_Texture* InsertCoinsTexture = nullptr;

	// The pointer to the current player animation
	// It will be switched depending on the player's movement direction
	Animation* currentAnimation = nullptr;

	Animation QuoteAttack;

	// A set of animations
	Animation idleAnimR,
		idleAnimL,
		upAnimR,
		downAnimR,
		upAnimL,
		downAnimL,
		rightAnim,
		leftAnim,
		jumpAnimR,
		jumpAnimL,
		FrontSwordAttackR,
		FrontSwordAttackL,
		LegAttackR,
		LegAttackL,
		TwoSwordAttackR,
		TwoSwordAttackL,
		PlayerDeathR,
		PlayerDeathL;

	Animation LittleFire, InsertCoins;

	// The player's collider
	Collider* collider = nullptr;
	Collider* colliderAttack = nullptr;

	// A countdown to when the player gets destroyed. After a while, the game exits
	uint destroyedCountdown = 120;

	// Sound effects indices
	uint PlayerAttackFx = 0;
	uint AttackQuoteFx = 0;

	bool god = false;

	int HP override = 10;
};

class Enemies : public ModuleEntities {
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

	// The enemy's texture
	SDL_Texture* texture = nullptr;

	// Sound fx when destroyed
	int destroyedFx = 0;

protected:

	bool Purple_Position = true;
	bool Orange_Position = true;

	// A ptr to the current animation
	Animation* currentAnim = nullptr;

	// The enemy's collider
	Collider* collider = nullptr;
	Collider* colliderAttack = nullptr;

	// Original spawn position. Stored for movement calculations
	fPoint spawnPos;

	int HP override= 3;
};

bool Orange_Position = true;

#endif
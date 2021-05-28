#ifndef __MODULE_PLAYER_H__
#define __MODULE_PLAYER_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

#define Max_HP 10;

class ModulePlayer : public Module
{
public:
	// Constructor
	ModulePlayer(bool startEnabled);

	// Destructor
	~ModulePlayer();

	// Called when the module is activated
	// Loads the necessary textures for the player
	bool Start() override;

	// Called at the middle of the application loop
	// Processes new input and handles player movement
	update_status Update() override;

	// Called at the end of the application loop
	// Performs the render call of the player sprite
	update_status PostUpdate() override;

	// Collision callback, called when the player intersects with another collider
	void OnCollision(Collider* c1, Collider* c2) override;

	void GodMode();
	// Position of the player in the map
	iPoint position;


private:

	// The speed in which we move the player (pixels per frame)
	int speed = 1;

	bool Player_Position;

	
	// The player spritesheet loaded into an SDL_Texture
	SDL_Texture* texture = nullptr;

	SDL_Texture* QuoteTexture = nullptr;

	//SDL_Texture* Fire_Texture = nullptr;
	
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

	//Animation Fire;

	// The player's collider
	Collider* collider = nullptr;
	Collider* colliderAttack = nullptr;

	// A flag to detect when the player has been destroyed
	bool destroyed = false;

	// A countdown to when the player gets destroyed. After a while, the game exits
	uint destroyedCountdown = 120;

	// Sound effects indices
	uint PlayerAttackFx = 0;
	uint AttackQuoteFx = 0;

	bool god = false;

	int HP = Max_HP;
};

#endif //!__MODULE_PLAYER_H__

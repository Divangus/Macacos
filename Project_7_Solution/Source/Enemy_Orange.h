#ifndef __ENEMY_ORANGE_H__
#define __ENEMY_ORANGE_H__

#include "Enemy.h"
#include "Path.h"
#include "Path2.h"
//#include "p2Point.h"

class Enemy_Orange : public Enemy
{
public:
	// Constructor (x y coordinates in the world)
	// Creates animation and movement data and the collider
	Enemy_Orange(int x, int y);

	// The enemy is going to follow the different steps in the path
	// Position will be updated depending on the speed defined at each step
	void Update() override;

	
private:
	// The path that will define the position in the world
	Path path;
	Path2 path1;

	bool follow = true;
	bool attack = true;

	// Enemy animations
	Animation front,
		up_front,
		back,
		up_back,
		front_melee_attack,
		back_melee_attack,
		front_gun_attack,
		back_gun_attack,
		front_getting_hit,
		back_getting_hit,
		front_iddle,
		back_iddle,
		front_shot,
		back_shot,
		front_shuriken,
		back_shuriken;

	bool melee_attack = false;
};

#endif // __ENEMY_ORANGE_H__
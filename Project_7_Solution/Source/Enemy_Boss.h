#ifndef __ENEMY_BOSS_H__
#define __ENEMY_BOSS_H__

#include "Enemy.h"
#include "Path.h"
//#include "p2Point.h"

class Enemy_Boss : public Enemy
{
public:
	// Constructor (x y coordinates in the world)
	// Creates animation and movement data and the collider
	Enemy_Boss(int x, int y);

	// The enemy is going to follow the different steps in the path
	// Position will be updated depending on the speed defined at each step
	void Update() override;


private:
	// The path that will define the position in the world
	Path path[2];

	bool follow = true;
	bool attack = true;

	// Enemy animations
	Animation front_iddle, back_iddle, front, back, 

	bool melee_attack = false;
};

#endif // __ENEMY_BOSS_H__
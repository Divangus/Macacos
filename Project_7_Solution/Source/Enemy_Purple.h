#ifndef __ENEMY_PURPLE_H__
#define __ENEMY_PURPLE_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Purple : public Enemy
{
public:
	// Constructor (x y coordinates in the world)
	// Creates animation and movement data and the collider
	Enemy_Purple(int x, int y);

	// The enemy is going to follow the different steps in the path
	// Position will be updated depending on the speed defined at each step
	void Update() override;

private:
	// The path that will define the position in the world
	Path path;

	// Enemy animations
	Animation front, back,
		front_hit, back_hit, front_punch, back_punch,
		front_hit_ground, front_hit_ground_behind, front_ground, front_ground_behind,
		front_recovery, front_recovery_behind,
		back_hit_ground, back_hit_ground_behind, back_ground, back_ground_behind,
		back_recovery, back_recovery_behind;
};

#endif // __ENEMY_PURPLE_H__

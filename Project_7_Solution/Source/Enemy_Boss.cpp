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
	back_charge.PushBack({ 0, 145, 62, 55 });
	back_charge.PushBack({ 62, 145, 57, 55 });
	back_charge.PushBack({ 119, 145, 52, 55 });
	back_charge.PushBack({ 171, 145, 64, 55 });
	back_charge.speed = 0.1f;

	front_charge.PushBack({ 450, 975, 62, 55 });
	front_charge.PushBack({ 393, 975, 57, 55 });
	front_charge.PushBack({ 341, 975, 52, 55 });
	front_charge.PushBack({ 277, 975, 64, 55 });
	front.speed = 0.1f;

	//Kick
	back_kick.PushBack({ 0, 200, 64, 68 });
	back_kick.PushBack({ 64, 200, 72, 68 });
	back_kick.speed = 0.1f;

	front_kick.PushBack({ 448, 1030, 64, 68 });
	front_kick.PushBack({ 376, 1030, 72, 68 });
	front_kick.speed = 0.1f;

	//Getting hit
	back_getting_hit.PushBack({ 0, 268, 42, 70 });
	back_getting_hit.PushBack({ 42, 268, 40, 70 });
	back_getting_hit.PushBack({ 82, 268, 60, 70 });
	back_getting_hit.PushBack({ 142, 268, 42, 70 });
	back_getting_hit.PushBack({ 184, 268, 40, 70 });
	back_getting_hit.PushBack({ 224, 268, 38, 70 });
	back_getting_hit.PushBack({ 262, 268, 64, 70 });
	back_getting_hit.speed = 0.1f;

	front_getting_hit.PushBack({ 470, 1100, 42, 70 });
	front_getting_hit.PushBack({ 430, 1100, 40, 70 });
	front_getting_hit.PushBack({ 370, 1100, 60, 70 });
	front_getting_hit.PushBack({ 328, 1100, 42, 70 });
	front_getting_hit.PushBack({ 288, 1100, 40, 70 });
	front_getting_hit.PushBack({ 250, 1100, 38, 70 });
	front_getting_hit.PushBack({ 186, 1100, 64, 70 });
	front_getting_hit.speed = 0.1f;

	//Spawn gun
	back_spawn_gun.PushBack({ 0, 339, 52, 96 });
	back_spawn_gun.PushBack({ 52, 339, 50, 96 });
	back_spawn_gun.PushBack({ 102, 339, 43, 96 });
	back_spawn_gun.PushBack({ 145, 339, 40, 96 });
	back_spawn_gun.speed = 0.1f;

	front_spawn_gun.PushBack({ 460, 1170, 52, 96 });
	front_spawn_gun.PushBack({ 410, 1170, 50, 96 });
	front_spawn_gun.PushBack({ 367, 1170, 43, 96 });
	front_spawn_gun.PushBack({ 327, 1170, 40, 96 });
	front_spawn_gun.speed = 0.1f;

	//Gun walk
	back_gun.PushBack({ 0, 438, 42, 96 });
	back_gun.PushBack({ 42, 438, 42, 96 });
	back_gun.PushBack({ 84, 438, 40, 96 });
	back_gun.PushBack({ 124, 438, 41, 96 });
	back_gun.PushBack({ 165, 438, 43, 96 });
	back_gun.PushBack({ 208, 438, 44, 96 });
	back_gun.speed = 0.1f;

	front_gun.PushBack({ 470, 1268, 42, 96 });
	front_gun.PushBack({ 428, 1268, 42, 96 });
	front_gun.PushBack({ 388, 1268, 40, 96 });
	front_gun.PushBack({ 347, 1268, 41, 96 });
	front_gun.PushBack({ 304, 1268, 43, 96 });
	front_gun.PushBack({ 260, 1268, 44, 96 });
	front_gun.speed = 0.1f;

	//Gun walk and aiming
	back_gun_aim.PushBack({ 8, 534, 62, 60 });
	back_gun_aim.PushBack({ 70, 534, 53, 60 });
	back_gun_aim.PushBack({ 131, 534, 61, 60 });
	back_gun_aim.PushBack({ 192, 534, 61, 60 });
	back_gun_aim.PushBack({ 253, 534, 60, 60 });
	back_gun_aim.PushBack({ 313, 534, 64, 60 });
	back_gun_aim.speed = 0.1f;

	front_gun_aim.PushBack({ 442, 1364, 62, 60 });
	front_gun_aim.PushBack({ 389, 1364, 53, 60 });
	front_gun_aim.PushBack({ 328, 1364, 61, 60 });
	front_gun_aim.PushBack({ 267, 1364, 61, 60 });
	front_gun_aim.PushBack({ 207, 1364, 60, 60 });
	front_gun_aim.PushBack({ 143, 1364, 64, 60 });
	front_gun_aim.speed = 0.1f;

	//Shooting
	back_shoot.PushBack({ 15, 670, 79, 70 });
	back_shoot.PushBack({ 94, 670, 76, 70 });
	back_shoot.PushBack({ 170, 670, 64, 70 });
	back_shoot.PushBack({ 234, 670, 62, 70 });
	back_shoot.speed = 0.1f;

	front_shoot.PushBack({ 418, 1502, 79, 70 });
	front_shoot.PushBack({ 342, 1502, 76, 70 });
	front_shoot.PushBack({ 278, 1502, 64, 70 });
	front_shoot.PushBack({ 216, 1502, 62, 70 });
	front_shoot.speed = 0.1f;

	//Kick with gun
	back_gun_kick.PushBack({ 0, 593, 68, 70 });
	back_gun_kick.PushBack({ 68, 593, 76, 70 });
	back_gun_kick.speed = 0.1f;

	front_gun_kick.PushBack({ 444, 1425, 68, 70 });
	front_gun_kick.PushBack({ 368, 1425, 76, 70 });
	front_gun_kick.speed = 0.1f;

	//Getting hit with gun
	back_gun_getting_hit.PushBack({ 8, 754, 69, 72 });
	back_gun_getting_hit.PushBack({ 77, 754, 58, 72 });
	back_gun_getting_hit.PushBack({ 135, 754, 72, 72 });
	back_gun_getting_hit.PushBack({ 207, 754, 71, 72 });
	back_gun_getting_hit.PushBack({ 278, 754, 55, 72 });
	back_gun_getting_hit.PushBack({ 333, 754, 57, 72 });
	back_gun_getting_hit.PushBack({ 390, 754, 62, 72 });
	back_gun_getting_hit.speed = 0.1f;

	front_gun_getting_hit.PushBack({ 435, 1584, 69, 72 });
	front_gun_getting_hit.PushBack({ 377, 1584, 58, 72 });
	front_gun_getting_hit.PushBack({ 305, 1584, 72, 72 });
	front_gun_getting_hit.PushBack({ 234, 1584, 71, 72 });
	front_gun_getting_hit.PushBack({ 179, 1584, 55, 72 });
	front_gun_getting_hit.PushBack({ 122, 1584, 57, 72 });
	front_gun_getting_hit.PushBack({ 60, 1584, 62, 72 });
	front_gun_getting_hit.speed = 0.1f;

	stop.PushBack({ 435, 1584, 69, 72 });

	//Shot
	/*
		
		Cada vegada que el boss dispara ho fa 4 vegades, es a dir, fa l'animació de disparar 4 vegades i cada cop dispara una bala.
		Comprova el gameplay de youtube per a veure la velocitat a la que dispara.

		Comprova també el video per a veure quan fa els moviments, per exemple, treu l'arma quan li han tret 5 de vida(en teoria en té 20) i fa l'animació de getting hit cada 5 de mal.

		Com no sabia com posar les bales només les he posat en el modul del boss, no estan al mòdul de les particules.

		El png de l'sprite del boss està inicialitzat com a texture4 en el module enemies però no se si s'ha d'assignar al mòdul del boss ni com fer-ho.
	
	*/
	/*back_shot.PushBack({ 317, 119, 10, 4 });

	front_shot.PushBack({ 342, 119, 10, 3 });*/

	path[0].PushBack({ 0.0f, 0.0f }, 30, &front_iddle);

	path[1].PushBack({ 0.0f, 0.0f }, 15, &front_getting_hit);
	path[1].PushBack({ 0.0f, 0.0f }, 0, &stop);


	BossCollider = App->collisions->AddCollider({ 0,0, 45, 20 }, Collider::Type::ENEMY, (Module*)App->enemies);
	BossColliderAttack = App->collisions->AddCollider({ 0, 0, 20, 20 }, Collider::Type::BOSS_ATTACK, (Module*)App->enemies);
}

void Enemy_Boss::Update()
{
	App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::BOSS_ATTACK] = false;

	if (god == true) {
		if (life == 15 || life == 10 || life == 5) {
			if (position.x > App->player->position.x){
				path[1].Update();
				currentAnim = path[1].GetCurrentAnimation();
				if (currentAnim == &stop) {
					path[1].Reset();
					god = false;
				}
			}
		}
		else if (life >= 0 ){
			god = false;
		}

	}
	else {
		path[0].Update();
		position = spawnPos + path[0].GetRelativePosition();
		currentAnim = path[0].GetCurrentAnimation();
	}
	if (currentAnim == &front_iddle || currentAnim == &front || currentAnim == &front_charge || currentAnim == &front_kick || currentAnim == &front_getting_hit || currentAnim == &front_spawn_gun || currentAnim == &front_gun || currentAnim == &front_gun_aim || currentAnim == &front_shoot || currentAnim == &front_gun_kick) {
		Boss_Position = true;
	}
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
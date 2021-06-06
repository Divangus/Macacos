#include "ModulePlayer.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleChooseCharacter.h"
#include "ModuleTitle.h"
#include "ModuleLevel2.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleFadeToBlack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SDL/include/SDL_scancode.h"


ModulePlayer::ModulePlayer(bool startEnabled) : Module(startEnabled)
{
	

	coin1.PushBack({6,4,6,13});
	coin1.loop = false;

	coin2.PushBack({ 11,4,9,13 });
	coin2.loop = false;

	coin3.PushBack({ 20,4,9,13 });
	coin3.loop = false;

	coin4.PushBack({ 28,4,9,13 });
	coin4.loop = false;

	coin5.PushBack({ 36,4,9,13 });
	coin5.loop = false;

	coin6.PushBack({ 44,4,9,13 });
	coin6.loop = false;

	coin7.PushBack({ 52,4,9,13 });
	coin7.loop = false;

	coin8.PushBack({ 60,4,9,13 });
	coin8.loop = false;

	coin9.PushBack({ 70,4,9,13 });
	coin9.loop = false;

	LifeBar10.PushBack({ 7,10,21,8 });

	LifeBar9.PushBack({ 30,10,19,8 });

	LifeBar8.PushBack({ 51,10,17,8 });

	LifeBar7.PushBack({ 70,10,15,8 });

	LifeBar6.PushBack({ 87,10,13,8 });

	LifeBar5.PushBack({ 102,10,11,8 });

	LifeBar4.PushBack({ 115,10,9,8 });

	LifeBar3.PushBack({ 126,10,7,8 });

	LifeBar2.PushBack({ 135,10,5,8 });

	LifeBar1.PushBack({ 142,10,3,8 });

	//Insert Coins Animation
	InsertCoins.PushBack({ 4,1,67,19 });
	InsertCoins.PushBack({ 82,26,67,19 });
	InsertCoins.PushBack({ 82,1,67,19 });
	InsertCoins.PushBack({ 152,1,67,19 });
	InsertCoins.PushBack({ 3,26,67,19 });
	InsertCoins.loop = true;
	InsertCoins.speed = 0.15f;
	//Fire Anim

	LittleFire.PushBack({ 2,3,59,42 });
	LittleFire.PushBack({ 66,0,59,42 });
	LittleFire.PushBack({ 137,2,59,42 });
	LittleFire.PushBack({ 2,50,59,42 });
	LittleFire.PushBack({ 66,46,59,42 });
	LittleFire.PushBack({ 135,46,59,42 });
	LittleFire.speed = 0.2f;
	LittleFire.loop = true;

	srand(time(NULL));

	//Attack Quote
	QuoteAttack.PushBack({ 115,167,66,34 });
	QuoteAttack.PushBack({ 0,0,0,0 });
	QuoteAttack.loop = false;
	QuoteAttack.speed = 0.01f;

	//Player
	//right idle
	idleAnimR.PushBack({ 30, 0, 77, 90 });
	idleAnimR.PushBack({ 30, 0, 77, 90 });
	idleAnimR.PushBack({ 30, 0, 77, 90 });
	idleAnimR.PushBack({122, 0, 77, 90 });
	idleAnimR.PushBack({ 216, 0, 77, 90 });
	idleAnimR.PushBack({ 310, 0, 77, 90 });
	idleAnimR.PushBack({ 404, 0, 77,90 });
	idleAnimR.PushBack({ 498, 0, 77, 90 });
	idleAnimR.PushBack({ 30, 0, 77, 90 });
	idleAnimR.PushBack({ 30, 0, 77, 90 });
	idleAnimR.PushBack({ 30, 0, 77, 90 });
	idleAnimR.PushBack({ 30, 0, 77, 90 });
	idleAnimR.PushBack({ 30, 0, 77, 90 });
	idleAnimR.loop = true;
	idleAnimR.speed = 0.095f;

	//left idle
	idleAnimL.PushBack({ 1708, 2087, 77, 90 });
	idleAnimL.PushBack({ 1708, 2087, 77, 90 });
	idleAnimL.PushBack({ 1708, 2087, 77, 90 });
	idleAnimL.PushBack({ 1708, 2087, 77, 90 });
	idleAnimL.PushBack({ 1616,  2087, 77, 90 });
	idleAnimL.PushBack({ 1522,   2087, 77, 90 });
	idleAnimL.PushBack({ 1428, 2087, 77, 90 });
	idleAnimL.PushBack({ 1334, 2087, 77, 90 });
	idleAnimL.PushBack({ 1240,  2087, 77, 90 });
	idleAnimL.PushBack({ 1708,2087, 77, 90 });
	idleAnimL.PushBack({ 1708, 2087, 77, 90 });
	idleAnimL.PushBack({ 1708, 2087, 77, 90 });
	idleAnimL.PushBack({ 1708, 2087, 77, 90 });
	idleAnimL.loop = true;
	idleAnimL.speed = 0.095f;

	// rigt move upwards
	upAnimR.PushBack({ 39, 1010, 77, 90 });
	upAnimR.PushBack({ 135, 1010, 77, 90 });
	upAnimR.PushBack({ 231, 1010, 77, 90 });
	upAnimR.PushBack({ 325, 1010,77, 90 });
	upAnimR.PushBack({ 415, 1010, 77, 90 });
	upAnimR.PushBack({ 507, 1010, 77, 90 });
	upAnimR.PushBack({ 597, 1010, 77, 90 });
	upAnimR.PushBack({ 690, 1010,77, 90 });
	upAnimR.loop = true;
	upAnimR.speed = 0.2f;

	//left move upwards
	upAnimL.PushBack({ 1707, 3097, 77, 90 });
	upAnimL.PushBack({ 1616, 3097, 77, 90 });
	upAnimL.PushBack({ 1524, 3097, 77, 90 });
	upAnimL.PushBack({ 1430, 3097,77, 90 });
	upAnimL.PushBack({ 1340, 3097, 77, 90 });
	upAnimL.PushBack({ 1244, 3097, 77, 90 });
	upAnimL.PushBack({ 1146, 3097, 77, 90 });
	upAnimL.PushBack({ 1050, 3097,77, 90 });
	upAnimL.loop = true;
	upAnimL.speed = 0.2f;

	//left move down
	downAnimL.PushBack({ 1707, 3020, 77,90 });
	downAnimL.PushBack({ 1613, 3020, 77, 90 });
	downAnimL.PushBack({ 1521, 3020, 77, 90 });
	downAnimL.PushBack({ 1426, 3020, 77, 90 });
	downAnimL.PushBack({ 1333, 3020, 77,90 });
	downAnimL.PushBack({ 1236, 3028, 77, 90 });
	downAnimL.PushBack({ 1144, 3028, 77, 90 });
	downAnimL.PushBack({ 1049, 3028, 77, 90 });
	downAnimL.loop = true;
	downAnimL.speed = 0.2f;

	// right move down
	downAnimR.PushBack({ 38, 927, 77, 90 });
	downAnimR.PushBack({ 134, 927 ,77, 90 });
	downAnimR.PushBack({ 230, 927 ,77 ,90 });
	downAnimR.PushBack({ 316 ,927 ,77 ,90 });
	downAnimR.PushBack({ 412 ,927 ,77 ,90 });
	downAnimR.PushBack({ 508 ,927 ,77 ,90 });
	downAnimR.PushBack({ 604,927 ,77 ,90 });
	downAnimR.PushBack({ 700, 927, 77 ,90 });
	downAnimR.loop = true;
	downAnimR.speed = 0.2f;

	// Move right
	rightAnim.PushBack({ 38, 927, 77, 90 });
	rightAnim.PushBack({ 134, 927 ,77, 90 });
	rightAnim.PushBack({ 230, 927 ,77 ,90 });
	rightAnim.PushBack({ 316 ,927 ,77 ,90 });
	rightAnim.PushBack({ 412 ,927 ,77 ,90 });
	rightAnim.PushBack({ 508 ,927 ,77 ,90 });
	rightAnim.PushBack({ 604,927 ,77 ,90 });
	rightAnim.PushBack({ 700, 927, 77 ,90 });
	rightAnim.loop = true;
	rightAnim.speed = 0.2f;

	//Move left
	leftAnim.PushBack({ 1707, 3013, 77, 90 });
	leftAnim.PushBack({ 1613, 3013, 77, 90 });
	leftAnim.PushBack({ 1521,3013, 77, 90 });
	leftAnim.PushBack({ 1426, 3013, 77, 90 });
	leftAnim.PushBack({ 1333,3013, 77,90 });
	leftAnim.PushBack({ 1236, 3013, 77, 90 });
	leftAnim.PushBack({ 1144, 3013, 77, 90 });
	leftAnim.PushBack({ 1049, 3013, 77, 90 });
	leftAnim.loop = true;
	leftAnim.speed = 0.2f;

	//Jump right
	jumpAnimR.PushBack({ 29,592,77,88 });
	jumpAnimR.PushBack({ 128,601,77,88 });
	jumpAnimR.PushBack({ 213,601,77,88 });
	jumpAnimR.PushBack({ 311,601,77,80 });
	jumpAnimR.PushBack({ 413,601,77,80 });
	jumpAnimR.PushBack({ 505,601,77,80 });
	jumpAnimR.PushBack({ 591,601,77,80 });
	jumpAnimR.PushBack({ 681,601,77,80 });
	jumpAnimR.PushBack({ 785,591,77,80 });
	jumpAnimR.PushBack({ 871,591,77,80 });
	jumpAnimR.PushBack({ 30, 0, 77, 90 });
	jumpAnimR.loop = false;
	jumpAnimR.speed = 0.3f;

	//Jump left
	jumpAnimL.PushBack({1718,2677,77,88 });
	jumpAnimL.PushBack({ 1629,2685,77,88 });
	jumpAnimL.PushBack({ 1524,2685,77,88 });
	jumpAnimL.PushBack({ 1437,2685,77,88 });
	jumpAnimL.PushBack({ 1351,2685,77,88 });
	jumpAnimL.PushBack({ 1258,2685,77,88 });
	jumpAnimL.PushBack({ 1156,2685,77,88 });
	jumpAnimL.PushBack({ 1058,2685,77,88 });
	jumpAnimL.PushBack({ 975,2685,77,88 });
	jumpAnimL.PushBack({ 879,2685,77,80 });
	jumpAnimL.PushBack({ 1708, 2087, 77, 88 });
	jumpAnimL.loop = false;
	jumpAnimL.speed = 0.3f;

	//right attack
	FrontSwordAttackR.PushBack({ 29,170,77,84 });
	FrontSwordAttackR.PushBack({ 120,170,77,88 });
	FrontSwordAttackR.PushBack({ 225,170,77,88 });
	FrontSwordAttackR.PushBack({ 309,170,77,88 });
	FrontSwordAttackR.PushBack({ 403,170,77,88 });
	FrontSwordAttackR.PushBack({ 503,170,77,88 });
	FrontSwordAttackR.PushBack({ 30, 0, 77, 88 });
	FrontSwordAttackR.loop = false;
	FrontSwordAttackR.speed = 0.3f;

	//left attack
	FrontSwordAttackL.PushBack({1706,2259,77,82});
	FrontSwordAttackL.PushBack({ 1609,2259,77,88 });
	FrontSwordAttackL.PushBack({ 1526,2259,77,88 });
	FrontSwordAttackL.PushBack({ 1422,2259,77,88 });
	FrontSwordAttackL.PushBack({ 1329,2259,77,88 });
	FrontSwordAttackL.PushBack({ 1240,2259,77,88 });
	FrontSwordAttackL.PushBack({ 1708, 2087, 77, 90 });
	FrontSwordAttackL.loop = false;
	FrontSwordAttackL.speed = 0.3f;

	/*Right Attack With Leg*/
	LegAttackR.PushBack({ 37,86,77,85});
	LegAttackR.PushBack({ 125,86,72,88 });
	LegAttackR.PushBack({ 224,86,90,88 });
	LegAttackR.PushBack({ 314,86,77,88 });
	LegAttackR.PushBack({ 30, 0, 77, 90 });
	LegAttackR.loop = false;
	LegAttackR.speed = 0.3f;

	/*Left Attack With Leg*/
	LegAttackL.PushBack({1705,2174,77,83});
	LegAttackL.PushBack({ 1618,2174,77,88 });
	LegAttackL.PushBack({ 1504,2174,77,88 });
	LegAttackL.PushBack({ 1427,2174,77,88 });
	LegAttackL.PushBack({ 1049, 3013, 77, 90 });
	LegAttackL.loop = false;
	LegAttackL.speed = 0.3f;

	//Right Sword Attack
	TwoSwordAttackR.PushBack({ 16,338,77,88 });
	TwoSwordAttackR.PushBack({ 113,338,77,88 });
	TwoSwordAttackR.PushBack({ 203,338,88,88 });
	TwoSwordAttackR.PushBack({ 301,338,88,88 });
	TwoSwordAttackR.PushBack({ 409,338,77,88 });
	TwoSwordAttackR.PushBack({ 482,338,77,88 });
	TwoSwordAttackR.PushBack({ 30, 0, 77, 90 });
	TwoSwordAttackR.loop = false;
	TwoSwordAttackR.speed = 0.3f;

	//Left Sword Attack
	TwoSwordAttackL.PushBack({ 1727,2425,77,88 });
	TwoSwordAttackL.PushBack({ 1617,2425,77,88 });
	TwoSwordAttackL.PushBack({ 1503,2425,77,88 });
	TwoSwordAttackL.PushBack({ 1409,2425,77,88 });
	TwoSwordAttackL.PushBack({ 1341,2425,77,88 });
	TwoSwordAttackL.PushBack({ 1230,2425,77,88 });
	TwoSwordAttackL.PushBack({ 1049, 3013, 77, 90 });
	TwoSwordAttackL.loop = false;
	TwoSwordAttackL.speed = 0.3f;

	dmg.PushBack({ 1727,2425,77,88 });

	sdmg.PushBack({ 1727,2425,77,88 });

	//player death
	PlayerDeathR.PushBack({35,1942,77,88});
	PlayerDeathR.PushBack({ 124,1942,77,88 });
	PlayerDeathR.PushBack({ 35,1942,77,88 });
	PlayerDeathR.loop = false;
	PlayerDeathR.speed = 0.2f;

	//FrontSwordAttackR
	/*attack[0].PushBack({ 0.0f, 0.0f }, 0, &dmg);
	attack[0].PushBack({ 0.0f, 0.0f }, 15, &FrontSwordAttackR);
	attack[0].PushBack({ 0.0f, 0.0f }, 0, &sdmg);



	attack->loop = true;*/
}

ModulePlayer::~ModulePlayer()
{

}

bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;
	
	LifeCoins = App->character->coins;
	LifesBlue = App->character->Blue;

	InsertCoinsTexture = App->textures->Load("Assets/InsertCoins.png");
	texture = App->textures->Load("Assets/leonardo.png");
	QuoteTexture = App->textures->Load("Assets/Quotes.png");
	FireAnimTexture = App->textures->Load("Assets/LittleFire.png");
	CoinsTexture = App->textures->Load("Assets/coins.png");
	LifeBarTexture = App->textures->Load("Assets/lifeBar.png");
	currentAnimation = &idleAnimR;

	PlayerAttackFx = App->audio->LoadFx("Assets/Fx/PlayerAttackFx.wav");
	AttackQuoteFx = App->audio->LoadFx("Assets/Fx/AttackQuote.wav");
	

	position.x = 40;
	position.y = 120;

	Player_Position = true;
	destroyed = false;

	collider = App->collisions->AddCollider({position.x, position.y, 35, 20 }, Collider::Type::PLAYER, this);
	colliderAttack = App->collisions->AddCollider({ position.x, position.y, 20, 20 }, Collider::Type::PLAYER_ATTACK, this);
	

	return ret;
}

update_status ModulePlayer::Update()
{


	LittleFire.Update();
	InsertCoins.Update();

	App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_ATTACK] = false;
	//player collider
	if (Player_Position == true) {
		collider->SetPos(position.x-5, position.y + 85);
		colliderAttack->SetPos(position.x + 30, position.y + 85);
	}
	if (Player_Position == false) {
		collider->SetPos(position.x+18, position.y + 85);
		colliderAttack->SetPos(position.x -2, position.y + 85);
	}
	if (currentAnimation == &FrontSwordAttackR || currentAnimation == &FrontSwordAttackL || currentAnimation==&LegAttackR || currentAnimation == &LegAttackL || currentAnimation == &TwoSwordAttackR || currentAnimation == &TwoSwordAttackL) {
		App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_ATTACK] = true;
	}
	else {
		App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_ATTACK] = false;
	}
	/*if (currentAnimation == &dmg) {
		App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_ATTACK] = true;
	}
	else {
		App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_ATTACK] = false;
	}*/


	//Attack Quote
	QuoteAttack.Update();

	// Moving the player with the camera scroll
	App->player->position.x += 0;

	//player limits
	if (position.x < App->render->LimitPL) {
		position.x = App->render->LimitPL;
	}
	if (position.x > 1280){
		position.x = 1280;
	}
	if (position.y > 135) { //bottom
		position.y = 135; 
	}
	if (position.y < 50) {//top
		position.y = 50;
	}
	if (position.x < 0) {
		position.x = 0;
	}
	

	//camera
	if (position.x > (App->render->LimitPR)){
		if (App->render->camera.x < LIMIT_CAMERA_LEVEL1){
			App->render->LimitPR += speed;
			App->render->LimitPL += speed;
			App->render->camera.x += App->render->cameraSpeed;
		}
	}
	if (position.x > (App->render->LimitPR)) {
		if (App->render->camera.x < LIMIT_CAMERA_LEVEL2) {
			App->render->LimitPR += speed;
			App->render->LimitPL += speed;
			App->render->camera.x += App->render->cameraSpeed;
		}
	}


	//left
	if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		position.x -= speed;

		if (currentAnimation != &leftAnim)
		{
			leftAnim.Reset();
			currentAnimation = &leftAnim;
			Player_Position = false;
		}
	}

	//right
	if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		position.x += speed;
		if (currentAnimation != &rightAnim)
		{
			rightAnim.Reset();
			currentAnimation = &rightAnim;
			Player_Position = true;
		}
	}

	//left and up
	else if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		currentAnimation = &upAnimL;
		if (currentAnimation != &upAnimL)
		{
			upAnimL.Reset();
			currentAnimation = &upAnimL;
			Player_Position = false;
		}
	}

	//left and down
	if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		currentAnimation = &downAnimL;
		if (currentAnimation != &downAnimL)
		{
			downAnimL.Reset();
			currentAnimation = &downAnimL;
			Player_Position = false;
		}
	}

	//right and up
	else if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		currentAnimation = &upAnimR;
		if (currentAnimation != &upAnimR)
		{
			upAnimR.Reset();
			currentAnimation = &upAnimR;
			Player_Position = true;
		}
	}

	//right and down
	else if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		currentAnimation = &downAnimR;
		if (currentAnimation != &downAnimR)
		{
			downAnimR.Reset();
			currentAnimation = &downAnimR;
			Player_Position = true;
		}
	}

	//down
	if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		position.y += speed;
		if (currentAnimation != &downAnimR && currentAnimation!= &downAnimL)
		{
			if (Player_Position == true) {
				downAnimR.Reset();
				currentAnimation = &downAnimR;
			}
			else {
				downAnimL.Reset();
				currentAnimation = &downAnimL;
			}
		}
	}

	//up
	if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;
		if (currentAnimation != &upAnimR && currentAnimation != &upAnimL)
		{
			if (Player_Position == true) {
				upAnimR.Reset();
				currentAnimation = &upAnimR;
			}
			else {
				upAnimL.Reset();
				currentAnimation = &upAnimL;
			}
		}
	}

	//Attack + move
	if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_K] == KEY_STATE::KEY_REPEAT)
	{
		currentAnimation = &FrontSwordAttackR;
		if (currentAnimation != &FrontSwordAttackR)
		{
			FrontSwordAttackR.Reset();
			currentAnimation = &FrontSwordAttackR;
			Player_Position = true;
		}
	}
	if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_K] == KEY_STATE::KEY_REPEAT)
	{
		currentAnimation = &FrontSwordAttackL;
		if (currentAnimation != &FrontSwordAttackL)
		{
			FrontSwordAttackL.Reset();
			currentAnimation = &FrontSwordAttackL;
			Player_Position = true;
		}
	}

	//Front attack
	if (App->input->keys[SDL_SCANCODE_K] == KEY_STATE::KEY_DOWN)
	{
		//int num = (rand() % 3);
		int num = 0;
		if (num == 0) {
				if (Player_Position == true) {
					FrontSwordAttackR.Reset();
					currentAnimation = &FrontSwordAttackR;
					/*attack[0].Update();
					currentAnimation = attack[0].GetCurrentAnimation();*/
				}
				if (Player_Position == false) {
					FrontSwordAttackL.Reset();
					currentAnimation = &FrontSwordAttackL;
				}
			
				App->audio->PlayFx(PlayerAttackFx);
		}

		if (num == 1) {
				if (Player_Position == true) {
					LegAttackR.Reset();
					currentAnimation = &LegAttackR;
				}
				if (Player_Position == false) {
					LegAttackL.Reset();
					currentAnimation = &LegAttackL;
				}

			App->audio->PlayFx(PlayerAttackFx);
		}
		if (num == 2) {
			if (Player_Position == true) {
				TwoSwordAttackR.Reset();
				currentAnimation = &TwoSwordAttackR;

			}
			if (Player_Position == false) {
				TwoSwordAttackL.Reset();
				currentAnimation = &TwoSwordAttackL;
			}

			
		}
		App->audio->PlayFx(PlayerAttackFx);
	}

	//jump
	else if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_REPEAT)
	{
		if (currentAnimation != &jumpAnimR && currentAnimation != &jumpAnimL)
		{
			if (Player_Position == true) {
				position.y -= 1;
				jumpAnimR.Reset();
				currentAnimation = &jumpAnimR;
			}
			else {
				position.y -= 1;
				jumpAnimL.Reset();
				currentAnimation = &jumpAnimL;
			}
		}
	}
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		if (currentAnimation != &jumpAnimR && currentAnimation != &jumpAnimL)
		{
			if (Player_Position == true) {
				position.y -= 1;
				jumpAnimR.Reset();
				currentAnimation = &jumpAnimR;
			}
			else {
				position.y -= 1;
				jumpAnimL.Reset();
				currentAnimation = &jumpAnimL;
			}
		}
	}
	if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		if (currentAnimation != &jumpAnimR && currentAnimation != &jumpAnimL)
		{
			if (Player_Position == true) {
				position.y -= 1;
				jumpAnimR.Reset();
				currentAnimation = &jumpAnimR;
			}
			else {
				position.y -= 1;
				jumpAnimL.Reset();
				currentAnimation = &jumpAnimL;
			}
		}
	}

	//left and right pressed
	if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		if (currentAnimation != &rightAnim
			&& currentAnimation != &leftAnim)
		{
			if (Player_Position == true) {
				idleAnimR.Reset();
				currentAnimation = &idleAnimR;
			}
			if (Player_Position == false) {
				idleAnimL.Reset();
				currentAnimation = &idleAnimL;
			}
		}
	}

	//up and down pressed
	if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		if (currentAnimation != &upAnimL
			&& currentAnimation != &downAnimL
			&& currentAnimation != &upAnimR
			&& currentAnimation != &downAnimR)
		{
			if (Player_Position == true) {
				idleAnimR.Reset();
				currentAnimation = &idleAnimR;
			}
			if (Player_Position == false) {
				idleAnimL.Reset();
				currentAnimation = &idleAnimL;
			}
		}
	}

	if (HP == 0) {

	}

	// If no up/down movement detected, set the current animation back to idle
	if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE 
		&& App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE 
		&& App->input->keys[SDL_SCANCODE_K] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_IDLE)
		{
		/*if (App->input->keys[SDL_SCANCODE_K] == KEY_STATE::KEY_IDLE && currentAnimation != &dmg && currentAnimation != &sdmg && currentAnimation != &FrontSwordAttackR)
		{*/
			if (currentAnimation != &idleAnimR
				&& currentAnimation != &idleAnimL
				/*&& currentAnimation != &upAnimR
				&& currentAnimation != &upAnimL
				&& currentAnimation != &downAnimR
				&& currentAnimation != &downAnimL
				&& currentAnimation != &leftAnim
				&& currentAnimation != &rightAnim*/
				&& currentAnimation != &jumpAnimR
				&& currentAnimation != &jumpAnimL
				&& currentAnimation != &FrontSwordAttackR
				&& currentAnimation != &FrontSwordAttackL
				&& currentAnimation != &LegAttackR
				&& currentAnimation != &LegAttackL
				&& currentAnimation != &TwoSwordAttackR
				&& currentAnimation != &TwoSwordAttackL)
			{
				if (Player_Position == true) {
					idleAnimR.Reset();
					currentAnimation = &idleAnimR;
				}
				if (Player_Position == false) {
					idleAnimL.Reset();
					currentAnimation = &idleAnimL;
				}

			}
		//}
	}
		
	currentAnimation->Update();

	if (destroyed)
	{
		destroyedCountdown--;
		if (destroyedCountdown <= 0)
			return update_status::UPDATE_STOP;
	}

	if (App->input->keys[SDL_SCANCODE_F2] == KEY_DOWN) {
		if (god == true) {
			god = false;
		}
		else {
			god = true;
		}
	}

	//lives
	if (App->input->keys[SDL_SCANCODE_LSHIFT] == KEY_STATE::KEY_DOWN) {
		LifeCoins++;
		LifesBlue = 10;
	}

	

	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	


	//if (App->render->camera.x == 0) {
	//	App->audio->PlayFx(AttackQuoteFx);
	//}


	if (!destroyed)
	{	
		if (App->player->position.y > 69) {
			App->render->Blit(FireAnimTexture, 314, 138, &(LittleFire.GetCurrentFrame()), 1);
			SDL_Rect rect = currentAnimation->GetCurrentFrame();
			App->render->Blit(texture, position.x - 10, position.y + 20, &rect);//draw player
		}
		else {
			SDL_Rect rect = currentAnimation->GetCurrentFrame();
			App->render->Blit(texture, position.x - 10, position.y + 20, &rect);//draw player
			App->render->Blit(FireAnimTexture, 314, 138, &(LittleFire.GetCurrentFrame()), 1);
		}
		//SDL_Rect rect = currentAnimation->GetCurrentFrame();
		//App->render->Blit(texture, position.x-10, position.y+20, &rect);//draw player
	}

	if (LifeCoins == 0 && LifesBlue == 0) {
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->over, 60);
	}

	if (god == true) {
		GodMode();
	}

	App->render->Blit(QuoteTexture, 50, 120, &(QuoteAttack.GetCurrentFrame()), 0);
	App->render->Blit(InsertCoinsTexture, 83, 18, &(InsertCoins.GetCurrentFrame()), 0);
	App->render->Blit(InsertCoinsTexture, 151, 18, &(InsertCoins.GetCurrentFrame()), 0);
	App->render->Blit(InsertCoinsTexture, 219, 18, &(InsertCoins.GetCurrentFrame()), 0);

	if (LifeCoins == 1) {
		App->render->Blit(CoinsTexture, 30, 20, &(coin1.GetCurrentFrame()), 0);
	}
	if (LifeCoins == 2) {
		App->render->Blit(CoinsTexture, 30, 20, &(coin2.GetCurrentFrame()), 0);
	}
	if (LifeCoins == 3) {
		App->render->Blit(CoinsTexture, 30, 20, &(coin3.GetCurrentFrame()), 0);
	}
	if (LifeCoins == 4) {
		App->render->Blit(CoinsTexture, 30, 20, &(coin4.GetCurrentFrame()), 0);
	}
	if (LifeCoins == 5) {
		App->render->Blit(CoinsTexture, 30, 20, &(coin5.GetCurrentFrame()), 0);
	}
	if (LifeCoins == 6) {
		App->render->Blit(CoinsTexture, 30, 20, &(coin6.GetCurrentFrame()), 0);
	}
	if (LifeCoins == 7) {
		App->render->Blit(CoinsTexture, 30, 20, &(coin7.GetCurrentFrame()), 0);
	}
	if (LifeCoins == 8) {
		App->render->Blit(CoinsTexture, 30, 20, &(coin8.GetCurrentFrame()), 0);
	}
	if (LifeCoins == 9) {
		App->render->Blit(CoinsTexture, 30, 20, &(coin9.GetCurrentFrame()), 0);
	}

	if (LifesBlue == 10) {
		App->render->Blit(LifeBarTexture, 50, 20, &(LifeBar10.GetCurrentFrame()), 0);
	}
	if (LifesBlue == 9) {
		App->render->Blit(LifeBarTexture, 50, 20, &(LifeBar9.GetCurrentFrame()), 0);
	}
	if (LifesBlue == 8) {
		App->render->Blit(LifeBarTexture, 50, 20, &(LifeBar8.GetCurrentFrame()), 0);
	}
	if (LifesBlue == 7) {
		App->render->Blit(LifeBarTexture, 50, 20, &(LifeBar7.GetCurrentFrame()), 0);
	}
	if (LifesBlue == 6) {
		App->render->Blit(LifeBarTexture, 50, 20, &(LifeBar6.GetCurrentFrame()), 0);
	}
	if (LifesBlue == 5) {
		App->render->Blit(LifeBarTexture, 50, 20, &(LifeBar5.GetCurrentFrame()), 0);
	}
	if (LifesBlue == 4) {
		App->render->Blit(LifeBarTexture, 50, 20, &(LifeBar4.GetCurrentFrame()), 0);
	}
	if (LifesBlue == 3) {
		App->render->Blit(LifeBarTexture, 50, 20, &(LifeBar3.GetCurrentFrame()), 0);
	}
	if (LifesBlue == 2) {
		App->render->Blit(LifeBarTexture, 50, 20, &(LifeBar2.GetCurrentFrame()), 0);
	}
	if (LifesBlue == 1) {
		App->render->Blit(LifeBarTexture, 50, 20, &(LifeBar1.GetCurrentFrame()), 0);
	}

	if (hit == true) {
		LifesBlue--;
		hit = false;
	}
	if (LifesBlue==0) {
		LifeCoins--;
		if (LifeCoins >= 0) {
			LifesBlue = 10;
		}
		else {
			LifesBlue = 0;
		}
	}

	return update_status::UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{

	if (c1 == collider && destroyed == false && god == false) {

		hit=true;
    }

	if (LifeCoins == -1) {
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->over, 60);
	}

	//	/*if (Player_Position == true) {
	//		currentAnimation = &PlayerDeathR;
	//		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->over, 60);
	//	}
	//	else {
	//		currentAnimation = &PlayerDeathL;
	//		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->over, 60);
	//	}*/
	//}
}

void ModulePlayer::GodMode() {
	HP = Max_HP;
	//Quan fagi mal matarà d'un cop
}

bool ModulePlayer::CleanUp() {

	LOG("Clearing Over");


	App->textures->Unload(texture);
	App->textures->Unload(QuoteTexture);
	App->textures->Unload(FireAnimTexture);
	App->textures->Unload(InsertCoinsTexture);
	App->textures->Unload(CoinsTexture);
	App->textures->Unload(LifeBarTexture);
	
	

	return true;
}
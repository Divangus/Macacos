#include "ModulePlayer.h"


#include "Application.h"
#include "ModuleTextures.h"
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

	srand(time(NULL));

	//Attack Quote
	QuoteAttack.PushBack({ 115,167,66,34 });
	QuoteAttack.PushBack({ 0,0,0,0 });
	QuoteAttack.loop = false;
	QuoteAttack.speed = 0.01f;

	//Player
	//right idle
	idleAnimR.PushBack({ 30, 0, 77, 90 });
	idleAnimR.PushBack({122, 0, 77, 90 });
	idleAnimR.PushBack({ 216, 0, 77, 90 });
	idleAnimR.PushBack({ 310, 0, 77, 90 });
	idleAnimR.PushBack({ 404, 0, 77,90 });
	idleAnimR.PushBack({ 498, 0, 77, 90 });
	idleAnimR.PushBack({ 30, 0, 77, 90 });
	idleAnimR.loop = false;
	idleAnimR.speed = 0.095f;

	//left idle
	idleAnimL.PushBack({ 1708, 2087, 77, 90 });
	idleAnimL.PushBack({ 1616,  2087, 77, 90 });
	idleAnimL.PushBack({ 1522,   2087, 77, 90 });
	idleAnimL.PushBack({ 1428, 2087, 77, 90 });
	idleAnimL.PushBack({ 1334, 2087, 77, 90 });
	idleAnimL.PushBack({ 1240,  2087, 77, 90 });
	idleAnimL.PushBack({ 1708,2087, 77, 90 });
	idleAnimL.loop = false;
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
	LegAttackR.loop = false;
	LegAttackR.speed = 0.3f;

	/*Left Attack With Leg*/
	LegAttackL.PushBack({1705,2174,77,83});
	LegAttackL.PushBack({ 1618,2174,77,88 });
	LegAttackL.PushBack({ 1504,2174,77,88 });
	LegAttackL.PushBack({ 1427,2174,77,88 });
	LegAttackL.loop = false;
	LegAttackL.speed = 0.3f;

	//Right Sword Attack
	TwoSwordAttackR.PushBack({ 16,338,77,88 });
	TwoSwordAttackR.PushBack({ 113,338,77,88 });
	TwoSwordAttackR.PushBack({ 203,338,88,88 });
	TwoSwordAttackR.PushBack({ 301,338,88,88 });
	TwoSwordAttackR.PushBack({ 409,338,77,88 });
	TwoSwordAttackR.PushBack({ 482,338,77,88 });
	TwoSwordAttackR.loop = false;
	TwoSwordAttackR.speed = 0.3f;

	//Left Sword Attack
	TwoSwordAttackL.PushBack({ 1727,2425,77,88 });
	TwoSwordAttackL.PushBack({ 1617,2425,77,88 });
	TwoSwordAttackL.PushBack({ 1503,2425,77,88 });
	TwoSwordAttackL.PushBack({ 1409,2425,77,88 });
	TwoSwordAttackL.PushBack({ 1341,2425,77,88 });
	TwoSwordAttackL.PushBack({ 1230,2425,77,88 });
	TwoSwordAttackL.loop = false;
	TwoSwordAttackL.speed = 0.3f;

	//player death
	PlayerDeathR.PushBack({35,1942,77,88});
	PlayerDeathR.PushBack({ 124,1942,77,88 });
	PlayerDeathR.PushBack({ 35,1942,77,88 });
	PlayerDeathR.loop = false;
	PlayerDeathR.speed = 0.3f;

	Fire.PushBack({ 25, 1, 308, 67 });
	Fire.PushBack({ 25,70,308,67 });
	Fire.PushBack({ 28,138,308,67 });
	Fire.PushBack({ 343,4,308,67 });
	Fire.PushBack({ 343,72,308,67 });
	Fire.PushBack({ 343,137,308,67 });
	Fire.PushBack({ 659,1,308,67 });
	Fire.PushBack({ 659,71,308,67 });
	//Fire.loop = true;
	Fire.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{

}

bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load("Assets/leonardo.png");
	QuoteTexture = App->textures->Load("Assets/Quotes.png");
	Fire_Texture = App->textures->Load("Assets/frontFire.png");
	currentAnimation = &idleAnimR;

	PlayerAttackFx = App->audio->LoadFx("Assets/Fx/PlayerAttackFx.wav");
	AttackQuoteFx = App->audio->LoadFx("Assets/Fx/AttackQuoteFx.wav");

	position.x = 40;
	position.y = 120;

	Player_Position = true;
	destroyed = false;

	collider = App->collisions->AddCollider({position.x, position.y, 30, 20 }, Collider::Type::PLAYER, this);
	colliderAttack = App->collisions->AddCollider({ position.x, position.y, 20, 20 }, Collider::Type::PLAYER_ATTACK, this);
	

	return ret;
}

update_status ModulePlayer::Update()
{

	Fire.Update();

	App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_ATTACK] = false;
	//player collider
	if (Player_Position == true) {
		collider->SetPos(position.x+5, position.y + 66);
		colliderAttack->SetPos(position.x + 35, position.y + 66);
	}
	if (Player_Position == false) {
		collider->SetPos(position.x+18, position.y + 66);
		colliderAttack->SetPos(position.x -2, position.y + 66);
	}
	/*if (currentAnimation == &jumpAnimR) {
		collider->SetPos(position.x + 5, position.y + 5);
		colliderAttack->SetPos(position.x + 15, position.y + 60);
	}
	if (currentAnimation == &jumpAnimL) {
		collider->SetPos(position.x + 5, position.y + 5);
		colliderAttack->SetPos(position.x + 15, position.y + 60);
	}*/
	if (currentAnimation == &FrontSwordAttackR || currentAnimation == &FrontSwordAttackL || currentAnimation==&LegAttackR || currentAnimation == &LegAttackL || currentAnimation == &TwoSwordAttackR || currentAnimation == &TwoSwordAttackL) {
		App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_ATTACK] = true;
	}
	else {
		App->collisions->matrix[Collider::Type::ENEMY][Collider::Type::PLAYER_ATTACK] = false;
	}


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
	if (position.y < 55) {//top
		position.y = 55;
	}
	if (position.x < 0) {
		position.x = 0;
	}
	

	//camera
	if (position.x > (App->render->LimitPR)){
		if (App->render->camera.x < LIMIT_CAMERA){
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
		int num = (rand() % 3);
		if (num == 0) {
				if (Player_Position == true) {
						currentAnimation = &FrontSwordAttackR;
						FrontSwordAttackR.Reset();
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

			App->audio->PlayFx(PlayerAttackFx);
		}
	
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
		&& App->input->keys[SDL_SCANCODE_L] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_J] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_IDLE)
		{
		if (currentAnimation != &idleAnimR
			&& currentAnimation != &idleAnimL
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

	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	//Big Fire
	App->render->Blit(Fire_Texture, -5, 160, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 250, 160, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 504, 160, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 760, 160, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 1018, 160, &(Fire.GetCurrentFrame()), 1);
	App->render->Blit(Fire_Texture, 1065, 160, &(Fire.GetCurrentFrame()), 1);

	App->render->Blit(QuoteTexture, 50, 120, &(QuoteAttack.GetCurrentFrame()), 0);

	//if (App->render->camera.x == 0) {
	//	App->audio->PlayFx(AttackQuoteFx);
	//}


	if (!destroyed)
	{
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(texture, position.x-10, position.y+20, &rect);//draw player
	}

	if (god == true) {
		GodMode();
	}
	

	return update_status::UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == collider && destroyed == false && god == false)
	{
		HP -= 1;
	}
	if (c1 == collider && destroyed == false && god == false && HP == 0) {
		if (Player_Position == true) {
			currentAnimation = &PlayerDeathR;
		}
		else {
			currentAnimation = &PlayerDeathL;
		}
		
		destroyed = true;
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->over, 60);
	}
}

void ModulePlayer::GodMode() {
	HP = Max_HP;
	//Quan fagi mal matarà d'un cop
}
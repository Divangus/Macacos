#include "ModulePlayer.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"

#include "SDL/include/SDL_scancode.h"


ModulePlayer::ModulePlayer()
{
	
	//right idle
	idleAnimR.PushBack({ 30, 0, 77, 90 });
	idleAnimR.PushBack({122, 0, 77, 90 });
	idleAnimR.PushBack({ 216, 0, 77, 90 });
	idleAnimR.PushBack({ 310, 0, 77, 90 });
	idleAnimR.PushBack({ 404, 0, 77,90 });
	idleAnimR.PushBack({ 498, 0, 77, 90 });
	idleAnimR.PushBack({ 30, 0, 77, 90 });
	idleAnimR.loop = false;
	idleAnimR.speed = 0.2f;

	//left idle
	idleAnimL.PushBack({ 1708, 2087, 77, 90 });
	idleAnimL.PushBack({ 1616,  2087, 77, 90 });
	idleAnimL.PushBack({ 1522,   2087, 77, 90 });
	idleAnimL.PushBack({ 1428, 2087, 77, 90 });
	idleAnimL.PushBack({ 1334, 2087, 77, 90 });
	idleAnimL.PushBack({ 1240,  2087, 77, 90 });
	idleAnimL.PushBack({ 1708,2087, 77, 90 });
	idleAnimL.loop = false;
	idleAnimL.speed = 0.2f;

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
	downAnimR.PushBack({ 38, 926, 77, 90 });
	downAnimR.PushBack({ 134, 926 ,77, 90 });
	downAnimR.PushBack({ 230, 926 ,77 ,90 });
	downAnimR.PushBack({ 316 ,926 ,77 ,90 });
	downAnimR.PushBack({ 412 ,926 ,77 ,90 });
	downAnimR.PushBack({ 508 ,926 ,77 ,90 });
	downAnimR.PushBack({ 604,926 ,77 ,90 });
	downAnimR.PushBack({ 700, 926, 77 ,90 });
	downAnimR.loop = true;
	downAnimR.speed = 0.2f;

	// Move right
	rightAnim.PushBack({ 38, 926, 77, 90 });
	rightAnim.PushBack({ 134, 926 ,77, 90 });
	rightAnim.PushBack({ 230, 926 ,77 ,90 });
	rightAnim.PushBack({ 316 ,926 ,77 ,90 });
	rightAnim.PushBack({ 412 ,926 ,77 ,90 });
	rightAnim.PushBack({ 508 ,926 ,77 ,90 });
	rightAnim.PushBack({ 604,926 ,77 ,90 });
	rightAnim.PushBack({ 700, 926, 77 ,90 });
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
	jumpAnimR.speed = 0.2f;

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
	jumpAnimL.speed = 0.2f;

	//right attack
	attackAnimR.PushBack({ 29,170,77,84 });
	attackAnimR.PushBack({ 120,170,77,88 });
	attackAnimR.PushBack({ 225,170,77,88 });
	attackAnimR.PushBack({ 309,170,77,88 });
	attackAnimR.PushBack({ 403,170,77,88 });
	attackAnimR.PushBack({ 503,170,77,88 });
	attackAnimR.PushBack({ 30, 0, 77, 88 });
	attackAnimR.loop = false;
	attackAnimR.speed = 0.2f;

	//left attack
	attackAnimL.PushBack({1706,2259,77,82});
	attackAnimL.PushBack({ 1609,2259,77,88 });
	attackAnimL.PushBack({ 1526,2259,77,88 });
	attackAnimL.PushBack({ 1422,2259,77,88 });
	attackAnimL.PushBack({ 1329,2259,77,88 });
	attackAnimL.PushBack({ 1240,2259,77,88 });
	attackAnimL.PushBack({ 1708, 2087, 77, 90 });
	attackAnimL.loop = false;
	attackAnimL.speed = 0.2f;

}

ModulePlayer::~ModulePlayer()
{

}

bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load("Assets/leonardo.png");
	currentAnimation = &idleAnimR;


	position.x = 40;
	position.y = 120;

	Player_Position = true;

	collider = App->collisions->AddCollider({ position.x - 12, position.y +12, 50, 90 }, Collider::Type::PLAYER, this);

	return ret;
}

update_status ModulePlayer::Update()
{
		// Moving the player with the camera scroll
	App->player->position.x += 0;

	//player limits
	if (position.x < App->render->LimitPL) {
		position.x = App->render->LimitPL;
	}
	if (position.x > 1371){
		position.x = 1371;
	}
	if (position.y > 140) { //bottom
		position.y = 140; 
	}
	if (position.y < 80) {//top
		position.y = 80;
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
		position.y -= speed;
		position.x -= speed;
		if (currentAnimation != &upAnimL && currentAnimation != &leftAnim)
		{
			upAnimL.Reset();
			currentAnimation = &upAnimL;
			Player_Position = false;
		}
	}

	//left and down
	if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		position.y += speed;
		position.x -= speed;
		if (currentAnimation != &downAnimR)
		{
			downAnimR.Reset();
			currentAnimation = &downAnimR;
			Player_Position = false;
		}
	}

	//right and up
	else if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;
		position.x += speed;
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
		position.x += speed;
		position.y += speed;
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

	//attack
	if (App->input->keys[SDL_SCANCODE_K] == KEY_STATE::KEY_DOWN)
	{
		if (currentAnimation != &attackAnimR && currentAnimation != &attackAnimL)
		{
			if (Player_Position == true) {
				attackAnimR.Reset();
				currentAnimation = &attackAnimR;
			}
			if (Player_Position == false) {
				attackAnimL.Reset();
				currentAnimation = &attackAnimL;
			}
			

		}
	}
		
	//jump
	else if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= 1;
		if (currentAnimation != &jumpAnimR && currentAnimation != &jumpAnimL)
		{
			if (Player_Position == true) {
				jumpAnimR.Reset();
				currentAnimation = &jumpAnimR;
			}
			else {
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

	// If no up/down movement detected, set the current animation back to idle
	if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE 
		&& App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE 
		&& App->input->keys[SDL_SCANCODE_K] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_IDLE)
		{
		if (currentAnimation != &idleAnimR
			&& currentAnimation != &idleAnimL
			&& currentAnimation != &attackAnimR
			&& currentAnimation != &attackAnimL
			&& currentAnimation != &jumpAnimR
			&& currentAnimation != &jumpAnimL)
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
		

	collider->SetPos(position.x, position.y);

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
	if (!destroyed)
	{
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(texture, position.x, position.y, &rect);
	}

	if (god == true) {
		GodMode();
	}

	if (App->input->keys[SDL_SCANCODE_ESCAPE] == KEY_STATE::KEY_DOWN) {
		return update_status::UPDATE_STOP;
	}

	return update_status::UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == collider && destroyed == false)
	{

	}
}

void ModulePlayer::GodMode() {
	//Quan hi hagi vida la posar� al m�xim
	//Quan fagi mal matar� d'un cop
}
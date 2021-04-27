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
	idleAnimR.PushBack({ 30, 20, 77, 80 });
	idleAnimR.PushBack({122, 19, 77, 80 });
	idleAnimR.PushBack({ 216, 19, 77, 80 });
	idleAnimR.PushBack({ 310, 19, 77, 80 });
	idleAnimR.PushBack({ 404, 21, 77,80 });
	idleAnimR.PushBack({ 498, 21, 77, 80 });
	idleAnimR.PushBack({ 30, 20, 77, 80 });
	idleAnimR.loop = false;
	idleAnimR.speed = 0.02f;

	//left idle
	idleAnimL.PushBack({ 1708, 2113, 77, 80 });
	idleAnimL.PushBack({ 1616, 2111, 77, 80 });
	idleAnimL.PushBack({ 1522, 2111, 77, 80 });
	idleAnimL.PushBack({ 1428, 2111, 77, 80 });
	idleAnimL.PushBack({ 1334, 2113, 77, 80 });
	idleAnimL.PushBack({ 1240, 2113, 77, 80 });
	idleAnimL.PushBack({ 1708, 2113, 77, 80 });
	idleAnimL.loop = false;
	idleAnimL.speed = 0.02f;

	// rigt move upwards
	upAnimR.PushBack({ 39, 1026, 77, 80 });
	upAnimR.PushBack({ 135, 1025, 77, 80 });
	upAnimR.PushBack({ 231, 1025, 77, 80 });
	upAnimR.PushBack({ 325, 1026,77, 80 });
	upAnimR.PushBack({ 415, 1025, 77, 80 });
	upAnimR.PushBack({507, 1026, 77, 80 });
	upAnimR.PushBack({ 597, 1026, 77, 80 });
	upAnimR.PushBack({ 690, 1028,77, 80 });
	upAnimR.loop = true;
	upAnimR.speed = 0.2f;

	//left move upwards
	upAnimL.PushBack({ 1707, 3118, 77, 80 });
	upAnimL.PushBack({ 1616, 3117, 77, 80 });
	upAnimL.PushBack({ 1524, 3117, 77, 80 });
	upAnimL.PushBack({ 1430, 3118,77, 80 });
	upAnimL.PushBack({ 1340, 3117, 77, 80 });
	upAnimL.PushBack({ 1244, 3118, 77, 80 });
	upAnimL.PushBack({ 1146, 3118, 77, 80 });
	upAnimL.PushBack({ 1050, 3120,77, 80 });
	upAnimL.loop = true;
	upAnimL.speed = 0.2f;

	//left move down
	downAnimL.PushBack({ 1707, 3034, 77, 80 });
	downAnimL.PushBack({ 1613, 3033, 77, 80 });
	downAnimL.PushBack({ 1521, 3035, 77, 80 });
	downAnimL.PushBack({ 1426, 3036, 77, 80 });
	downAnimL.PushBack({ 1333, 3036, 77,80 });
	downAnimL.PushBack({ 1236, 3034, 77, 80 });
	downAnimL.PushBack({ 1144, 3034, 77, 80 });
	downAnimL.PushBack({ 1049, 3034, 77, 80 });
	downAnimL.loop = true;
	downAnimL.speed = 0.2f;

	// right move down
	downAnimR.PushBack({ 38, 944, 77, 80 });
	downAnimR.PushBack({ 134, 944 ,77, 80 });
	downAnimR.PushBack({ 230, 944 ,77 ,80 });
	downAnimR.PushBack({ 316 ,944 ,77 ,80 });
	downAnimR.PushBack({ 412 ,944 ,77 ,80 });
	downAnimR.PushBack({ 508 ,944 ,77 ,80 });
	downAnimR.PushBack({ 604,944 ,77 ,80 });
	downAnimR.PushBack({ 700, 944, 77 ,80 });
	downAnimR.loop = true;
	downAnimR.speed = 0.2f;

	// Move right
	rightAnim.PushBack({ 38, 944, 77, 80 });
	rightAnim.PushBack({ 134, 944 ,77, 80 });
	rightAnim.PushBack({ 230, 944 ,77 ,80 });
	rightAnim.PushBack({ 316 ,944 ,77 ,80 });
	rightAnim.PushBack({ 412 ,944 ,77 ,80 });
	rightAnim.PushBack({ 508 ,944 ,77 ,80 });
	rightAnim.PushBack({ 604,944 ,77 ,80 });
	rightAnim.PushBack({ 700, 944, 77 ,80 });
	rightAnim.loop = true;
	rightAnim.speed = 0.2f;

	//Move left
	leftAnim.PushBack({ 1707, 3034, 77, 80 });
	leftAnim.PushBack({ 1613, 3033, 77, 80 });
	leftAnim.PushBack({ 1521, 3035, 77, 80 });
	leftAnim.PushBack({ 1426, 3036, 77, 80 });
	leftAnim.PushBack({ 1333, 3036, 77,80 });
	leftAnim.PushBack({ 1236, 3034, 77, 80 });
	leftAnim.PushBack({ 1144, 3034, 77, 80 });
	leftAnim.PushBack({ 1049, 3034, 77, 80 });
	leftAnim.loop = true;
	leftAnim.speed = 0.2f;

	//Jump right
	jumpAnimR.PushBack({ 29,607,77,80 });
	jumpAnimR.PushBack({ 128,603,77,80 });
	jumpAnimR.PushBack({ 213,608,77,80 });
	jumpAnimR.PushBack({ 311,609,77,80 });
	jumpAnimR.PushBack({413,605,77,80 });
	jumpAnimR.PushBack({ 505,599,77,80 });
	jumpAnimR.PushBack({ 591,612,77,80 });
	jumpAnimR.PushBack({ 681,616,77,80 });
	jumpAnimR.PushBack({ 785,591,77,80 });
	jumpAnimR.loop = false;
	jumpAnimR.speed = 0.2f;

	//Jump left
	jumpAnimL.PushBack({ 29,607,77,80 });
	jumpAnimL.PushBack({ 128,603,77,80 });
	jumpAnimL.PushBack({ 213,608,77,80 });
	jumpAnimL.PushBack({ 311,609,77,80 });
	jumpAnimL.PushBack({ 413,605,77,80 });
	jumpAnimL.PushBack({ 505,599,77,80 });
	jumpAnimL.PushBack({ 591,612,77,80 });
	jumpAnimL.PushBack({ 681,616,77,80 });
	jumpAnimL.PushBack({ 785,591,77,80 });
	jumpAnimL.loop = false;
	jumpAnimL.speed = 0.2f;

	//Attack
	attackAnim.PushBack({ 29,163,60,88 });
	attackAnim.PushBack({ 120,188,66,63 });
	attackAnim.PushBack({ 225,172,44,79 });
	attackAnim.PushBack({ 309,170,64,81 });
	attackAnim.PushBack({ 404,190,62,61 });
	attackAnim.PushBack({ 503,197,53,54 });
	attackAnim.loop = true;
	attackAnim.speed = 0.2f;

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

	laserFx = App->audio->LoadFx("Assets/laser.wav");
	explosionFx = App->audio->LoadFx("Assets/explosion.wav");

	position.x = 40;
	position.y = 120;

	collider = App->collisions->AddCollider({ position.x, position.y, 77, 80 }, Collider::Type::PLAYER, this);

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
	if (position.y > 150) { //bottom
		position.y = 150; 
	}
	if (position.y < 90) {//top
		position.y = 90;
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
		}
	}

	//left and up
	if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;
		position.x -= speed;
		if (currentAnimation != &upAnimL)
		{
			upAnimL.Reset();
			currentAnimation = &upAnimL;
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
		}
	}

	//right and up
	else if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		position.x += speed;
		position.y -= speed;
		if (currentAnimation != &upAnimR)
		{
			upAnimR.Reset();
			currentAnimation = &upAnimR;
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
		}
	}

	//down
	if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		position.y += speed;
		if (currentAnimation != &downAnimR)
		{
			downAnimR.Reset();
			currentAnimation = &downAnimR;
		}
	}

	//up
	if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;
		if (currentAnimation != &upAnimR)
		{
			upAnimR.Reset();
			currentAnimation = &upAnimR;
		}
	}

	//attack
	if (App->input->keys[SDL_SCANCODE_O] == KEY_STATE::KEY_DOWN)
	{
		if (currentAnimation != &attackAnim)
		{
			attackAnim.Reset();
			currentAnimation = &attackAnim;
		}
	}
		
	//jump
	else if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= 2;
		if (currentAnimation != &jumpAnimR)
		{
			jumpAnimR.Reset();
			currentAnimation = &jumpAnimR;
		}
	}

	//down and up pressed
	if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		if (currentAnimation != &idleAnimR)
		{
			idleAnimR.Reset();
			currentAnimation = &idleAnimR;
		}
	}

	// If no up/down movement detected, set the current animation back to idle
	if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE) {
		if (currentAnimation != &idleAnimR)
		{
			idleAnimR.Reset();
			currentAnimation = &idleAnimR;
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

	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	if (!destroyed)
	{
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(texture, position.x, position.y, &rect);
	}

	return update_status::UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c1 == collider && destroyed == false)
	{
		App->particles->AddParticle(App->particles->explosion, position.x, position.y, Collider::Type::NONE, 9);
		App->particles->AddParticle(App->particles->explosion, position.x + 8, position.y + 11, Collider::Type::NONE, 14);
		App->particles->AddParticle(App->particles->explosion, position.x - 7, position.y + 12, Collider::Type::NONE, 40);
		App->particles->AddParticle(App->particles->explosion, position.x + 5, position.y - 5, Collider::Type::NONE, 28);
		App->particles->AddParticle(App->particles->explosion, position.x - 4, position.y - 4, Collider::Type::NONE, 21);

		App->audio->PlayFx(explosionFx);

		destroyed = true;
	}
}

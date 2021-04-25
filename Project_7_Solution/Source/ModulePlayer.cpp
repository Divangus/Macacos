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
	idleAnim.PushBack({ 30, 20, 77, 80 });
	idleAnim.PushBack({122, 19, 77, 80 });
	idleAnim.PushBack({ 216, 19, 77, 80 });
	idleAnim.PushBack({ 310, 19, 77, 80 });
	idleAnim.PushBack({ 404, 21, 77,80 });
	idleAnim.PushBack({ 498, 21, 77, 80 });
	idleAnim.PushBack({ 30, 20, 77, 80 });
	idleAnim.loop = false;
	idleAnim.speed = 0.02f;

	// move upwards
	upAnim.PushBack({ 39, 1026, 77, 80 });
	upAnim.PushBack({ 135, 1025, 77, 80 });
	upAnim.PushBack({ 231, 1025, 77, 80 });
	upAnim.PushBack({ 325, 1026,77, 80 });
	upAnim.PushBack({ 415, 1025, 77, 80 });
	upAnim.PushBack({507, 1026, 77, 80 });
	upAnim.PushBack({ 597, 1026, 77, 80 });
	upAnim.PushBack({ 690, 1028,77, 80 });
	upAnim.loop = true;
	upAnim.speed = 0.1f;

	// Move down
	downAnim.PushBack({ 38, 944, 77, 80 });
	downAnim.PushBack({ 134, 944 ,77, 80 });
	downAnim.PushBack({ 230, 944 ,77 ,80 });
	downAnim.PushBack({ 316 ,944 ,77 ,80 });
	downAnim.PushBack({ 412 ,944 ,77 ,80 });
	downAnim.PushBack({ 508 ,944 ,77 ,80 });
	downAnim.PushBack({ 604,944 ,77 ,80 });
	downAnim.PushBack({ 700, 944, 77 ,80 });
	downAnim.loop = true;
	downAnim.speed = 0.1f;

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
	rightAnim.speed = 0.1f;

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
	leftAnim.speed = 0.1f;

	//Jump
	jumpAnim.PushBack({ 29,607,48,64 });
	jumpAnim.PushBack({ 127,627,41,44 });
	jumpAnim.loop = true;
	jumpAnim.speed = 0.1f;

	//up left
	upleftAnim.PushBack({ 1707, 3118, 49, 65 });
	upleftAnim.PushBack({ 1616, 3117, 44, 66 });
	upleftAnim.PushBack({ 1524, 3117, 40, 66 });
	upleftAnim.PushBack({ 1430, 3118, 40, 65 });
	upleftAnim.PushBack({ 1340, 3117, 40, 66 });
	upleftAnim.PushBack({ 1224, 3118 ,44, 65 });
	upleftAnim.PushBack({ 1146, 3118 ,52, 65 });
	upleftAnim.PushBack({ 1050, 3120 ,55, 63 });
	upleftAnim.loop = true;
	upleftAnim.speed = 0.1f;

	//Attack
	attackAnim.PushBack({ 29,163,60,88 });
	attackAnim.PushBack({ 120,188,66,63 });
	attackAnim.PushBack({ 225,172,44,79 });
	attackAnim.PushBack({ 309,170,64,81 });
	attackAnim.PushBack({ 404,190,62,61 });
	attackAnim.PushBack({ 503,197,53,54 });
	attackAnim.loop = true;
	attackAnim.speed = 0.1f;

}

ModulePlayer::~ModulePlayer()
{

}

bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load("Assets/leonardo.png");
	currentAnimation = &idleAnim;

	laserFx = App->audio->LoadFx("Assets/laser.wav");
	explosionFx = App->audio->LoadFx("Assets/explosion.wav");

	position.x = 40;
	position.y = 120;

	collider = App->collisions->AddCollider({ position.x, position.y, 32, 16 }, Collider::Type::PLAYER, this);

	return ret;
}

update_status ModulePlayer::Update()
{
	// Moving the player with the camera scroll
	App->player->position.x += 0;

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

	//izquierda y arriba
	/*if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		if (currentAnimation == &upleftAnim)
		{
			upleftAnim.Reset();
			currentAnimation = &upleftAnim;
		}
	}*/

	//down
	if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		position.y += speed;
		if (currentAnimation != &downAnim)
		{
			downAnim.Reset();
			currentAnimation = &downAnim;
		}
	}

	//up
	if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;
		if (currentAnimation != &upAnim)
		{
			upAnim.Reset();
			currentAnimation = &upAnim;
		}
	}

	//attack
	if (App->input->keys[SDL_SCANCODE_M] == KEY_STATE::KEY_REPEAT)
	{
		if (currentAnimation != &attackAnim)
		{
			attackAnim.Reset();
			currentAnimation = &attackAnim;
		}
	}
		
	//jump
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_REPEAT)
	{
		if (currentAnimation != &jumpAnim)
		{
			jumpAnim.Reset();
			currentAnimation = &jumpAnim;
		}
	}

	// If no up/down movement detected, set the current animation back to idle
	if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE) {
		if (currentAnimation != &idleAnim)
		{
			idleAnim.Reset();
			currentAnimation = &idleAnim;
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

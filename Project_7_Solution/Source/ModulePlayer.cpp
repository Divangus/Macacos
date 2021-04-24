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
	// idle animation - just one sprite
	idleAnim.PushBack({ 17, 18, 68, 70 });
	/*idleAnim.PushBack({104, 17, 76, 76 });
	idleAnim.PushBack({ 200, 14, 70, 81 });
	idleAnim.PushBack({ 295, 13, 69, 81 });
	idleAnim.PushBack({ 391, 13, 69, 84 });
	idleAnim.PushBack({ 487, 12, 62, 86 });
	upAnim.loop = true;
	upAnim.speed = 2222222;*/

	// move upwards
	upAnim.PushBack({ 23, 1025, 60, 73 });
	upAnim.PushBack({ 112, 1019, 70, 83 });
	upAnim.PushBack({ 211, 1016, 58, 87 });
	upAnim.PushBack({ 298, 1018, 68, 84 });
	upAnim.PushBack({ 386, 1018, 63, 84 });
	upAnim.PushBack({ 490, 1018, 56, 84 });
	upAnim.PushBack({ 586, 1021, 56, 76 });
	upAnim.PushBack({ 676, 1026, 67, 73 });
	upAnim.loop = true;
	upAnim.speed = 0.1f;

	// Move down
	downAnim.PushBack({ 38, 944, 65, 78 });
	downAnim.PushBack({ 134, 944 ,55, 81 });
	downAnim.PushBack({ 230, 944 ,64 ,83 });
	downAnim.PushBack({ 316 ,944 ,70 ,79 });
	downAnim.PushBack({ 412 ,944 ,58 ,73 });
	downAnim.PushBack({ 508 ,944 ,67 ,81 });
	downAnim.PushBack({ 604,944 ,77 ,81 });
	downAnim.PushBack({ 700, 944, 77 ,82 });
	downAnim.loop = true;
	downAnim.speed = 0.1f;

	// Move right
	rightAnim.PushBack({ 38, 944, 65, 78 });
	rightAnim.PushBack({ 134, 944 ,55, 81 });
	rightAnim.PushBack({ 230, 944 ,64 ,83 });
	rightAnim.PushBack({ 316 ,944 ,70 ,79 });
	rightAnim.PushBack({ 412 ,944 ,58 ,73 });
	rightAnim.PushBack({ 508 ,944 ,67 ,81 });
	rightAnim.PushBack({ 604,944 ,77 ,81 });
	rightAnim.PushBack({ 700, 944, 77 ,82 });
	rightAnim.loop = true;
	rightAnim.speed = 0.1f;

	//Move left
	leftAnim.PushBack({ 1697, 3026, 71, 80 });
	leftAnim.PushBack({ 1602, 3023, 80, 85 });
	leftAnim.PushBack({ 1515, 3027, 64, 76 });
	leftAnim.PushBack({ 1411, 3024, 71, 76 });
	leftAnim.PushBack({ 1320, 3021, 74, 83 });
	leftAnim.PushBack({ 1230, 3028, 64, 75 });
	leftAnim.PushBack({ 1135, 3025, 70, 76 });
	leftAnim.PushBack({ 1042, 3024, 71, 77 });
	leftAnim.loop = true;
	leftAnim.speed = 0.1f;

	//Jump
	jumpAnim.PushBack({});
	jumpAnim.loop = true;
	jumpAnim.speed = 0.1f;

	//up left
	upleftAnim.PushBack({ 1701, 3114, 67, 71 });
	upleftAnim.PushBack({ 1645, 3113, 63, 72 });
	upleftAnim.PushBack({ 1420, 3112, 61, 72 });
	upleftAnim.PushBack({ 1329, 3110, 58, 75 });
	upleftAnim.PushBack({ 1139, 3110, 71, 76 });
	upleftAnim.PushBack({ 1045, 3114 ,73, 76 });
	upleftAnim.loop = true;
	upleftAnim.speed = 0.1f;
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

	position.x =20;
	position.y = 120;

	collider = App->collisions->AddCollider({ position.x, position.y, 32, 16 }, Collider::Type::PLAYER, this);

	return ret;
}

update_status ModulePlayer::Update()
{
	// Moving the player with the camera scroll
	App->player->position.x += 0;

	//izquierda
	if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		position.x -= speed;
		if (currentAnimation != &leftAnim)
		{
			leftAnim.Reset();
			currentAnimation = &leftAnim;
		}
	}

	//derecha
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
		position.y -= speed;
		position.x -= speed;
		if (currentAnimation != &upleftAnim)
		{
			upleftAnim.Reset();
			currentAnimation = &upleftAnim;
		}
	}*/

	//abajo
	if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		position.y += speed;
		if (currentAnimation != &downAnim)
		{
			downAnim.Reset();
			currentAnimation = &downAnim;
		}
	}

	//arriba
	if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;
		if (currentAnimation != &upAnim)
		{
			upAnim.Reset();
			currentAnimation = &upAnim;
		}
	}

	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
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
		&& App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE)
		currentAnimation = &idleAnim;

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

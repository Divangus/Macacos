#include "ModuleParticles.h"

#include "Application.h"

#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollisions.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles(bool startEnabled) : Module(startEnabled)
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		particles[i] = nullptr;
}

ModuleParticles::~ModuleParticles()
{

}

bool ModuleParticles::Start()
{
	LOG("Loading particles");
	texture = App->textures->Load("Assets/Orange_Soldier.png");
	texture2 = App->textures->Load("Assets/White_Soldier.png");
	DeathExplosionTexture = App->textures->Load("Assets/EnemiesExplosionDeath.png");

	// Explosion particle
	shuriken_explosion.anim.PushBack({ 739, 52, 16, 18 });
	shuriken_explosion.anim.PushBack({ 651, 52, 16, 18 });
	shuriken_explosion.anim.loop = false;
	shuriken_explosion.anim.speed = 0.2f;
	shuriken_explosion.lifetime = 120;

	knife_explosion.anim.PushBack({ 99, 1056, 99, 88 });
	knife_explosion.anim.PushBack({ 198, 1056, 99, 88 });
	knife_explosion.anim.PushBack({ 297, 1056, 99, 88 });
	knife_explosion.anim.PushBack({ 396, 1056, 99, 88 });
	knife_explosion.anim.PushBack({ 495, 1056, 99, 88 });
	knife_explosion.anim.loop = false;
	knife_explosion.anim.speed = 0.2f;
	knife_explosion.lifetime = 120;

	shuriken.anim.PushBack({ 1006, 52, 11, 18 });
	shuriken.anim.PushBack({ 917, 52, 16, 18 });
	shuriken.anim.PushBack({ 830, 52, 16, 18 });
	shuriken.speed.x = 1;
	shuriken.lifetime = 120;
	shuriken.anim.speed = 0.2f;

	knife.anim.PushBack({ 0, 1056, 99, 88 });
	knife.speed.x = 1;
	knife.lifetime = 120;
	knife.anim.speed = 0.2f;

	knife_front.anim.PushBack({ 792, 2200, 90, 88 });
	knife_front.speed.x = 1;
	knife_front.lifetime = 120;
	knife_front.anim.speed = 0.2f;

	DeathExplosion.anim.PushBack({ 308,9,46,49 });
	DeathExplosion.anim.PushBack({ 261,8,46,49 });
	DeathExplosion.anim.PushBack({ 214,9,46,49 });
	DeathExplosion.anim.PushBack({ 159,9,46,49 });
	DeathExplosion.anim.PushBack({ 107,10,46,49 });
	DeathExplosion.anim.PushBack({ 60,9,46,49 });
	DeathExplosion.anim.PushBack({ 4,8,46,49 });
	DeathExplosion.lifetime = 30;
	DeathExplosion.anim.speed = 0.2f;

	return true;
}

bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");

	// Delete all remaining active particles on application exit 
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(particles[i] != nullptr)
		{
			delete particles[i];
			particles[i] = nullptr;
		}
	}

	return true;
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if (particles[i] != nullptr && particles[i]->collider == c1)
		{
			/*if (particles[i]->type == 1) {
				AddParticle(shuriken_explosion, particles[i]->position.x, particles[i]->position.y, particles[i]->type);
				particles[i]->type == 0;
			}

			if (particles[i]->type == 2) {
				AddParticle(knife_explosion, particles[i]->position.x, particles[i]->position.y, particles[i]->type);
				particles[i]->type == 0;
			}*/
			

			delete particles[i];
			particles[i] = nullptr;
			break;
		}
	}
}

update_status ModuleParticles::Update()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* particle = particles[i];

		if(particle == nullptr)	continue;

		// Call particle Update. If it has reached its lifetime, destroy it
		if(particle->Update() == false)
		{
			/*if (particles[i]->type == 1) {
				AddParticle(shuriken_explosion, particles[i]->position.x, particles[i]->position.y, 1);
			}

			if (particles[i]->type == 2) {
				AddParticle(knife_explosion, particles[i]->position.x, particles[i]->position.y, 2);
			}*/
			delete particle;
			particles[i] = nullptr;
		}
	}

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleParticles::PostUpdate()
{
	//Iterating all particle array and drawing any active particles
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* particle = particles[i];

		if (particle != nullptr && particle->isAlive)
		{
			if(particle->type == 1){
			App->render->Blit(texture, particle->position.x, particle->position.y, &(particle->anim.GetCurrentFrame()));
			}
			if (particle->type == 2) {
				App->render->Blit(texture2, particle->position.x, particle->position.y, &(particle->anim.GetCurrentFrame()));
			}

			if (particle->type == 3) {
				App->render->Blit(DeathExplosionTexture, particle->position.x, particle->position.y, &(particle->anim.GetCurrentFrame()));
			}
		}
	}

	return update_status::UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, int type, Collider::Type colliderType, uint delay)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		//Finding an empty slot for a new particle
		if (particles[i] == nullptr)
		{
			Particle* p = new Particle(particle);

			p->type = type;
			p->frameCount = -(int)delay;			// We start the frameCount as the negative delay
			p->position.x = x;						// so when frameCount reaches 0 the particle will be activated
			p->position.y = y;

			//Adding the particle's collider
			if (colliderType != Collider::Type::NONE && p->type == 2)
				p->collider = App->collisions->AddCollider({ 0, 0, 30, 10 }, colliderType, this);
			
			else {
				p->collider = App->collisions->AddCollider(p->anim.GetCurrentFrame(), colliderType, this);
			}

			particles[i] = p;
			break;
		}
	}
}
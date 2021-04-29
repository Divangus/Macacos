#include "ModuleElements.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"

#include "SDL/include/SDL_scancode.h"

ModuleElements::ModuleElements(bool enabled) : Module(enabled){

	Fire.PushBack({ 25, 1, 308, 67 });
	Fire.loop = true;
	Fire.speed = 0.2f;

}

ModuleElements::~ModuleElements()
{

}

bool ModuleElements::Start() {
	LOG("Loading elements textures");

	bool ret = true;

	FireTexture = App->textures->Load("Assets/fire.png");

	
	position.x = 0;
	position.y = 0;
		

	return ret;
}

update_status ModuleElements::Update() {
	Fire.Update();
	App->render->Blit(FireTexture, 0, 150, &(Fire.GetCurrentFrame())); 
	

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleElements::PostUpdate()
{
	if (!destroyed)
	{
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(FireTexture, position.x + 5, position.y + 5, &rect);
	}



	return update_status::UPDATE_CONTINUE;
}
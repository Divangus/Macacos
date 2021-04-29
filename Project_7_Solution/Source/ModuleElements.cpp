#include "ModuleElements.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"

#include "SDL/include/SDL_render.h"
#include "SDL/include/SDL_scancode.h"

ModuleElements::ModuleElements(bool enabled) : Module(enabled){

	Fire.PushBack({ 25, 1, 308, 67 });
	Fire.PushBack({ 25,70,308,67 });
	Fire.PushBack({ 28,138,308,67 });
	Fire.PushBack({ 343,4,308,67 });
	Fire.PushBack({ 343,72,308,67 });
	Fire.PushBack({ 343,137,308,67 });
	Fire.PushBack({ 659,1,308,67 });
	Fire.PushBack({ 659,71,308,67 });
	//Fire.loop = true;
	Fire.speed = 0.2f;

}

ModuleElements::~ModuleElements()
{

}

bool ModuleElements::Start() {
	LOG("Loading elements textures");

	bool ret = true;

	Texture_Fire = App->textures->Load("Assets/frontFire.png");
	//Texture_Quote = App->textures->Load("Assets/Quotes.png");

	
	position.x = 0;
	position.y = 0;
		

	return ret;
}

update_status ModuleElements::Update() {
	Fire.Update();
	
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleElements::PostUpdate()
{
	App->render->Blit(Texture_Fire, 50, 104, &(Fire.GetCurrentFrame()),0.2f);


	return update_status::UPDATE_CONTINUE;
}
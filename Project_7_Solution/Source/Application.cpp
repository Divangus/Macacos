#include "Application.h"

#include "Module.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleWin.h"
#include "ModulePlayer.h"
#include "ModuleScene.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "ModuleCollisions.h"
#include "ModuleRender.h"
#include "ModuleIntroScene.h"
#include "ModuleFadeToBlack.h"
#include "ModuleOver.h"
#include "ModuleChooseCharacter.h"
#include "ModuleLevel2.h"
#include "ModuleTitle.h"


Application::Application()
{
	// The order in which the modules are added is very important.
	// It will define the order in which Pre/Update/Post will be called
	// Render should always be last, as our last action should be updating the screen
	modules[0] = window = new ModuleWindow(true);
	modules[1] = input = new ModuleInput(true);
	modules[2] = textures = new ModuleTextures(true);
	modules[3] = audio = new ModuleAudio(true);
	modules[4] = sceneIntro = new ModuleIntroScene(true);
	modules[5] = winScreen = new ModuleWin(false);
	modules[6] = scene = new ModuleScene(false);
	modules[7] = level2 = new ModuleLevel2(false);
	modules[8] = character = new ModuleChooseCharacter(false);
	modules[9] = title = new ModuleTitle(false);
	modules[10] = player = new ModulePlayer(false);
	modules[11] = particles = new ModuleParticles(true);
	modules[12] = enemies = new ModuleEnemies(false);
	modules[13] = collisions = new ModuleCollisions(true);
	modules[14] = fade = new ModuleFadeToBlack(true);
	modules[15] = over = new ModuleOver(false);
	modules[16] = render = new ModuleRender(true);
	
}

Application::~Application()
{
	for (int i = 0; i < NUM_MODULES; ++i)
	{
		//Important: when deleting a pointer, set it to nullptr afterwards
		//It allows us for null check in other parts of the code
		delete modules[i];
		modules[i] = nullptr;
	}
}

bool Application::Init()
{
	bool ret = true;

	for (int i = 0; i < NUM_MODULES && ret; ++i)
		ret = modules[i]->Init();

	//By now we will consider that all modules are always active
	for (int i = 0; i < NUM_MODULES && ret; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;
	
	return ret;
}

update_status Application::Update()
{
	update_status ret = update_status::UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == update_status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : update_status::UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == update_status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : update_status::UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == update_status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : update_status::UPDATE_CONTINUE;

	return ret;
}
 
bool Application::CleanUp()
{
	bool ret = true;

	for (int i = NUM_MODULES - 1; i >= 0 && ret; --i)
		ret = modules[i]->CleanUp();

	return ret;
}

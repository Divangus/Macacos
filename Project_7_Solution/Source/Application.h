#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 17

class Module;
class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleAudio;
class ModulePlayer;
class ModuleScene;
class ModuleParticles;
class ModuleCollisions;
class ModuleEnemies;
class ModuleRender;
class ModuleIntroScene;
class ModuleFadeToBlack;
class ModuleOver;
class ModuleWin;
class ModuleChooseCharacter;
class ModuleLevel2;
class ModuleTitle;

class Application
{

public:

	//Constructor. Creates all necessary modules for the application
	Application();

	//Destructor. Removes all module objects
	~Application();

	//Initializes all modules
	bool Init();

	//Updates all modules (PreUpdate, Update and PostUpdate)
	update_status Update();

	//Releases all the application data
	bool CleanUp();

public:
	// An array to store all modules
	Module* modules[NUM_MODULES];

	// All the modules stored individually
	ModuleWindow* window = nullptr;
	ModuleInput* input = nullptr;
	ModuleTextures* textures = nullptr;
	ModuleAudio* audio = nullptr;

	ModulePlayer* player = nullptr;
	ModuleIntroScene* sceneIntro = nullptr;
	ModuleScene* scene = nullptr;
	ModuleEnemies* enemies = nullptr;
	ModuleParticles* particles = nullptr;

	ModuleCollisions* collisions = nullptr;
	ModuleFadeToBlack* fade = nullptr;

	ModuleRender* render = nullptr;
	ModuleOver* over = nullptr;
	ModuleTitle* title = nullptr;
	ModuleLevel2* level2 = nullptr;
	ModuleWin* winScreen = nullptr;
	ModuleChooseCharacter* character = nullptr;
	
};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__
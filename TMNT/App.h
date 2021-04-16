#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 1

class Module;
class ModuleWindow;


class Application
{

public:
	Application();

	~Application();

	bool Init();

	update_status Update();

	bool CleanUp();

public:
	Module* modules[NUM_MODULES];

	ModuleWindow* window = nullptr;
};

extern Application* App;

#endif //__APPLICATION_H__

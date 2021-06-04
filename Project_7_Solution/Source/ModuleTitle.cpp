#include "ModuleTitle.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL_Scancode.h"


ModuleTitle::ModuleTitle(bool startEnabled) : Module(startEnabled)
{

	AnimTitle.PushBack({0,0,304,222});
	AnimTitle.PushBack({306,0,304,222 });
	AnimTitle.PushBack({ 612,0,304,222 });
	AnimTitle.PushBack({ 918,0,304,222 });
	AnimTitle.PushBack({ 1224,0,304,222 });
	AnimTitle.PushBack({ 1530,0,304,222 });
	AnimTitle.PushBack({ 0,232,304,222 });
	AnimTitle.PushBack({ 306,232,304,222 });
	AnimTitle.PushBack({ 612,232,304,222 });
	AnimTitle.PushBack({ 918,232,304,222 });
	AnimTitle.PushBack({ 1224,232,304,222 });
	AnimTitle.PushBack({ 1530,232,304,222 });
	AnimTitle.PushBack({ 0,458,304,222 });
	AnimTitle.PushBack({ 306,458,304,222 });
	AnimTitle.PushBack({ 612,458,304,222 });
	AnimTitle.PushBack({ 918,458,304,222 });
	AnimTitle.PushBack({ 1224,458,304,222 });
	AnimTitle.PushBack({ 1530,458,304,222 });
	AnimTitle.PushBack({ 0,687,304,222 });
	AnimTitle.PushBack({ 306,687,304,222 });
	AnimTitle.PushBack({ 612,687,304,222 });
	AnimTitle.PushBack({ 918,687,304,222 });
	AnimTitle.PushBack({ 1224,687,304,222 });
	AnimTitle.PushBack({ 1530,687,304,222 });
	AnimTitle.PushBack({ 0,916,304,222 });
	AnimTitle.PushBack({ 306,916,304,222 });
	AnimTitle.PushBack({ 612,916,304,222 });
	AnimTitle.PushBack({ 918,916,304,222 });
	AnimTitle.PushBack({ 1224,916,304,222 });
	AnimTitle.PushBack({ 1530,916,304,222 });
	AnimTitle.PushBack({ 0,1140,304,222 });
	AnimTitle.PushBack({ 306,1140,304,222 });
	AnimTitle.PushBack({ 612,1140,304,222 });
	AnimTitle.PushBack({ 918,1140,304,222 });
	AnimTitle.PushBack({ 1224,1140,304,222 });
	AnimTitle.PushBack({ 1530,1140,304,222 });
	AnimTitle.PushBack({ 0,1374,304,222 });
	AnimTitle.PushBack({ 306,1374,304,222 });
	AnimTitle.PushBack({ 612,1374,304,222 });
	AnimTitle.PushBack({ 918,1374,304,222 });
	AnimTitle.PushBack({ 1224,1374,304,222 });
	AnimTitle.PushBack({ 1530,1374,304,222 });
	AnimTitle.PushBack({ 0,1603,304,222 });
	AnimTitle.PushBack({ 306,1603,304,222 });
	AnimTitle.PushBack({ 612,1603,304,222 });
	AnimTitle.PushBack({ 918,1603,304,222 });
	AnimTitle.PushBack({ 1224,1603,304,222 });
	AnimTitle.PushBack({ 1530,1603,304,222 });
	AnimTitle.PushBack({ 0,1832,304,222 });
	AnimTitle.PushBack({ 306,1832,304,222 });
	AnimTitle.PushBack({ 612,1832,304,222 });
	AnimTitle.PushBack({ 918,1832,304,222 });
	AnimTitle.PushBack({ 1224,1832,304,222 });
	AnimTitle.PushBack({ 1530,1832,304,222 });
	AnimTitle.PushBack({ 12,2062,304,222 });
	AnimTitle.PushBack({ 406,2062,304,222 });
	AnimTitle.PushBack({ 797,2062,304,222 });
	AnimTitle.PushBack({ 1178,2062,304,222 });
	AnimTitle.PushBack({ 12,2309,304,222 });
	AnimTitle.PushBack({ 406,2309,304,222 });
	AnimTitle.PushBack({ 797,2309,304,222 });
	AnimTitle.PushBack({ 1178,2309,304,222 });
	AnimTitle.PushBack({ 12,2583,304,222 });
	AnimTitle.PushBack({ 406,2583,304,222 });
	AnimTitle.PushBack({ 797,2583,304,222 });
	AnimTitle.PushBack({ 1178,2583,304,222 });
	AnimTitle.PushBack({ 12,2848,304,222 });
	AnimTitle.PushBack({ 406,2848,304,222 });
	AnimTitle.PushBack({ 797,2848,304,222 });
	AnimTitle.PushBack({ 1178,2848,304,222 });
	AnimTitle.loop = false;
	AnimTitle.speed = 0.12f;

	
}

ModuleTitle::~ModuleTitle()
{

}

// Load assets
bool ModuleTitle::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/AnimTitle.png");
	
	App->audio->PlayMusic("Assets/titleMusic.ogg", 1.0f);
	
	App->render->camera.x = 0;
	App->render->camera.y = 0;

	
	return ret;
}

update_status ModuleTitle::Update()
{
	AnimTitle.Update();
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) {
		App->fade->FadeToBlack(this, (Module*)App->character, 90);
	}
	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleTitle::PostUpdate()
{
	App->render->Blit(bgTexture, 0, 0, &(AnimTitle.GetCurrentFrame()), 0);
	return update_status::UPDATE_CONTINUE;
}

bool ModuleTitle::CleanUp() {
	LOG("Clearing Over");

	App->textures->Unload(bgTexture);

	return true;
}
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 20

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleParticles;
class ModuleAudio;
class ModuleScore;
class ModuleSceneForest;
class ModuleSceneStart;
class ModuleSceneIntro;
class ModuleUI;
class ModulePlayer;
class ModulePlayerTwo;
class ModulePartner;
class ModulePartner2;
class ModuleFadeToBlack;
class ModuleCollision;
class ModuleEnemies;
class ModuleFonts;
class ModulePowerup;
class Module;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleAudio* audio;
	ModuleScore* scene_score;
	ModuleSceneForest* scene_forest;
	ModuleSceneStart* scene_start;
	ModuleSceneIntro* scene_intro;
	ModuleCollision* collision;
	ModuleUI* ui;
	ModulePlayer* player;
	ModulePlayerTwo* player2;
	ModulePartner* partner;
	ModulePartner2* partner2;
	ModuleFadeToBlack* fade;
	ModuleParticles* particles;
	ModuleEnemies* enemies;
	ModuleFonts* fonts;
	ModulePowerup* pu;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__
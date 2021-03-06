#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;

	//Koyori Bullets
	bullet.anim.PushBack({ 24, 136, 13, 13 });
	bullet.anim.loop = true;
	bullet.life = 1400;
	bullet.speed.x = 12;

	bullet2.anim.PushBack({ 48, 136, 13, 13 });
	bullet2.anim.loop = true;
	bullet2.life = 1400;
	bullet2.speed.x = 12;

	bullet3.anim.PushBack({ 72, 136, 13, 13 });
	bullet3.anim.loop = true;
	bullet3.life = 1400;
	bullet3.speed.x = 12;

	bullet4.anim.PushBack({ 97, 136, 13, 13 });
	bullet4.anim.loop = true;
	bullet4.life = 1400;
	bullet4.speed.x = 12;

	bullet5.anim.PushBack({ 120, 136, 13, 13 });
	bullet5.anim.loop = true;
	bullet5.life = 1400;
	bullet5.speed.x = 12;

	//Sho Bullets
	shoot.anim.PushBack({ 26,107,26,2 });
	shoot.anim.loop = true;
	shoot.life = 1400;
	shoot.speed.x = 12;

	shoot1.anim.PushBack({ 26,111,26,2 });
	shoot1.anim.loop = true;
	shoot1.life = 1400;
	shoot1.speed.x = 12;

	shoot2.anim.PushBack({ 26,115,26,2 });
	shoot2.anim.loop = true;
	shoot2.life = 1400;
	shoot2.speed.x = 12;

	//Enemies Explosion

	explosion.anim.PushBack({ 24, 206, 56, 65 });
	explosion.anim.PushBack({ 81, 206, 56, 65 });
	explosion.anim.PushBack({ 140, 206, 56, 65 });
	explosion.anim.PushBack({ 202, 206, 56, 65 });
	explosion.anim.PushBack({ 264, 206, 56, 65 });
	explosion.anim.PushBack({ 326, 206, 56, 65 });
	explosion.anim.PushBack({ 387, 206, 56, 65 });
	explosion.anim.PushBack({ 454, 206, 56, 65 });
	explosion.anim.PushBack({ 521, 206, 56, 65 });
	explosion.anim.PushBack({ 588, 206, 56, 65 });
	explosion.anim.PushBack({ 654, 206, 56, 65 });
	explosion.anim.loop = false;
	explosion.anim.speed = 0.10f;
	explosion.life = 700;

	//Power UP/DOWN
	power_up.anim.PushBack({ 5,313,26,15 });
	power_up.anim.PushBack({ 5,331,26,15 });
	power_up.anim.PushBack({ 5,350,26,15 });
	power_up.anim.loop = true;
	power_up.anim.speed = 0.20f;
	power_up.life = 1000;

	power_down.anim.PushBack({ 36,331,26,15 });
	power_down.anim.PushBack({ 36,350,26,15 });
	power_down.anim.loop = true;
	power_down.anim.speed = 0.10f;
	power_down.life = 2000;

	//Bullet sparks
	spark.anim.PushBack({32,35,45,19});
	spark.anim.PushBack({ 84,35,45,19 });
	spark.anim.PushBack({ 141,35,45,19 });
	spark.anim.PushBack({213,35,45,19 });
	spark.anim.PushBack({ 267,35,45,19 });
	spark.anim.PushBack({ 325,35,45,19 });
	spark.anim.PushBack({ 391,35,45,19 });
	spark.anim.PushBack({ 457,35,45,19 });
	spark.anim.loop = false;
	spark.anim.speed = 0.10f;
	spark.life = 1200;

	//Mirror Bullets
	mirror_shoot.anim.PushBack({ 26,79,23,13 });
	mirror_shoot.anim.loop = true;
	mirror_shoot.life = 1400;
	mirror_shoot.speed.x = 12;

	c_mirror_green.anim.PushBack({ 55,63,32,13 });
	c_mirror_green.anim.loop = true;
	c_mirror_green.life = 1400;
	c_mirror_green.speed.x = 12;

	c_mirror_blue.anim.PushBack({ 55,79,32,13 });
	c_mirror_blue.anim.loop = true;
	c_mirror_blue.life = 1400;
	c_mirror_blue.speed.x = 12;

	c_mirror_cyan.anim.PushBack({ 55,95,32,13 });
	c_mirror_cyan.anim.loop = true;
	c_mirror_cyan.life = 1400;
	c_mirror_cyan.speed.x = 12;

	//Basaro Bullet
	egg_shoot.anim.PushBack({ 14,11,13,13 });
	egg_shoot.anim.PushBack({ 38,11,13,13 });
	egg_shoot.anim.PushBack({ 62,11,13,13 });
	egg_shoot.anim.speed = 0.10f;
	egg_shoot.anim.loop = false;
	egg_shoot.life = 1400;
	egg_shoot.speed.x = 5;

	cat_shoot.anim.PushBack({1,278,57,32});
	cat_shoot.anim.PushBack({ 61,278,57,32 });
	cat_shoot.anim.PushBack({ 122,278,57,32 });
	cat_shoot.anim.speed = 0.10f;
	cat_shoot.anim.loop = true;
	cat_shoot.life = 1400;
	cat_shoot.speed.x = 3;

	basaro_shot.anim.PushBack({379,134,15,15});
	basaro_shot.anim.speed = 0.10f;
	basaro_shot.anim.loop = true;
	basaro_shot.life = 1400;
	basaro_shot.speed.x = 12;

	//Ninja shurikens

	shuriken.anim.PushBack({ 46,176,8,8 });
	shuriken.anim.PushBack({ 58,175,10,10 });
	shuriken.anim.PushBack({ 71,175,10,10 });
	shuriken.anim.PushBack({ 84,175,10,10 });
	shuriken.anim.PushBack({ 98,176,8,8 });
	shuriken.speed.x = -10;
	shuriken.anim.loop = true;
	shuriken.life = 1400;


}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("assets/sprite/particles.png");

	shoot_audio = App->audio->LoadEffect("assets/audio/Shot_Koyori.wav");
	shoot_sho = App->audio->LoadEffect("assets/audio/Shot_Sho.wav");
	power_up_koyori_fx = App->audio->LoadEffect("assets/audio/power_up_koyori.wav");
	power_up_sho_fx = App->audio->LoadEffect("assets/audio/power_up_sho.wav");

	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");

	App->audio->UnloadFx(power_up_sho_fx);
	App->audio->UnloadFx(power_up_koyori_fx);
	App->audio->UnloadFx(shoot_sho);
	App->audio->UnloadFx(shoot_audio);

	App->textures->Unload(graphics);

	// Unload fx

	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if(p == nullptr)
			continue;

		if(p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if(SDL_GetTicks() >= p->born)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if(p->fx_played == false)
			{
				p->fx_played = true;
				//App->audio->PlayFx(p->fx);
			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, PARTICLE_TYPE particle_type, Uint32 delay)
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			if(collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			if (particle_type == PARTICLE_SHOT) {
				p->fx = 1;
				App->audio->PlaySoundEffects(shoot_audio, p->fx);
			}
			if (particle_type == PARTICLE_SHOT_2) {
				p->fx = 2;
				App->audio->PlaySoundEffects(shoot_sho, p->fx);
			}
			if (particle_type == PARTICLE_POWER_UP_KOYORI) {
				p->fx = 5;
				App->audio->PlaySoundEffects(power_up_koyori_fx, p->fx);
			}
			if (particle_type == PARTICLE_POWER_UP_SHO) {
				p->fx = 6;
				App->audio->PlaySoundEffects(power_up_sho_fx, p->fx);
			}
			active[i] = p;
			break;
		}
	}
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if(active[i] != nullptr && active[i]->collider == c1)
		{
			//AddParticle(explosion, active[i]->position.x, active[i]->position.y);
			delete active[i];
			active[i] = nullptr;
			break;
		}
	}
}

// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) : 
anim(p.anim), position(p.position), speed(p.speed),
fx(p.fx), born(p.born), life(p.life)
{}

Particle::~Particle()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

bool Particle::Update()
{
	bool ret = true;

	if(life > 0)
	{
		if((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if(anim.Finished())
			ret = false;

	position.x += speed.x;
	position.y += speed.y;

	if(collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}


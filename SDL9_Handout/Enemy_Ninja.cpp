#include "Application.h"
#include "Enemy_Ninja.h"
#include "ModuleEnemies.h"
#include "ModuleCollision.h"
#include "ModuleUI.h"


Enemy_Ninja::Enemy_Ninja(int x, int y) :Enemy(x, y)
{
	fly.PushBack({ 18,113,30,42 });

	lift.PushBack({ 158,113,30,42 });
	lift.PushBack({ 65,113,30,42 });
	lift.PushBack({ 112,113,30,42 });
	lift.PushBack({ 158,113,30,42 });
	lift.speed = App->enemies->speed;

	run.PushBack({206,14,43,34});
	run.PushBack({ 253,14,48,34 });
	run.PushBack({ 312,14,27,34 });
	run.PushBack({ 362,14,36,34 });
	run.PushBack({ 414,8,37,39 });
	run.PushBack({ 206,66,43,34 });
	run.PushBack({ 253,66,27,35 });
	run.PushBack({ 312,67,43,34 });
	run.PushBack({ 253,66,27,35 });
	run.speed = App->enemies->speed;

	up.PushBack({ 362,68,27,33 });

	movement.PushBack({ 1.75f, 3.0f }, 58, &fly);
	movement.PushBack({ 1.0f, 0.0f }, 20, &lift);
	movement.PushBack({ -1.5f, 0.0f }, 40, &run);
	movement.PushBack({ 3.00f,-3.00f }, 80, &up);

	animation = &fly;
	
	collider = App->collision->AddCollider({ 0, 0, 30, 30 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	originalposition.y = y;
	originalposition.x = x;
}

void Enemy_Ninja::Move()
{
	if(App->ui->enemies_movement){
	position = originalposition + movement.GetCurrentSpeed(&animation);
	}
	
}
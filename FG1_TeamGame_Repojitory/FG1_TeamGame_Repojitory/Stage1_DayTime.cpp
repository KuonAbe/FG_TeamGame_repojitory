#include "Stage1_DayTime.h"

void Stage1_DayTime::Init()
{
	sun_Pos_X = 0;
	sun_Pos_Y = 0;
	moon_Pos_X = 0;
	moon_Pos_Y = 0;
	Sun_Tex = LoadGraph("Sun.png");
	Moon_Tex = LoadGraph("Moon.png");
	night_Back_Tex = LoadGraph("night_Back.png");
	time.Init();
	starPos = AM6;
}

void Stage1_DayTime::Update()
{
	if (time.nowTime() <= 200)
		starPos = AM6;
	else if (time.nowTime() <= 400)
		starPos = AM9;
	else if (time.nowTime() <= 600)
		starPos = AM12;
	else if (time.nowTime() <= 800)
		starPos = PM3;
	else if (time.nowTime() <= 1000)
		starPos = PM6;
	else if (time.nowTime() <= 1200)
		starPos = PM9;
	else if (time.nowTime() <= 1600)
		starPos = PM11;
	else if (time.nowTime() <= 2000)
		starPos = PM12;
	else if (time.nowTime() <= 2400)
		starPos = AM3;
	else if (time.nowTime() <= 2800)
		starPos = AM5;
}

void Stage1_DayTime::Draw()
{

	switch (starPos)
	{
	case Stage1_DayTime::AM6:
		sun_Pos_X = 100;
		sun_Pos_Y = 400;
		DrawGraph(sun_Pos_X, sun_Pos_Y, Sun_Tex, TRUE);
		break;
	case Stage1_DayTime::AM9:
		sun_Pos_X = 500;
		sun_Pos_Y = 200;
		DrawGraph(sun_Pos_X, sun_Pos_Y, Sun_Tex, TRUE);
		break;
	case Stage1_DayTime::AM12:
		sun_Pos_X = 900;
		sun_Pos_Y = 0;
		DrawGraph(sun_Pos_X, sun_Pos_Y, Sun_Tex, TRUE);
		break;
	case Stage1_DayTime::PM3:
		sun_Pos_X = 1400;
		sun_Pos_Y = 200;
		DrawGraph(sun_Pos_X, sun_Pos_Y, Sun_Tex, TRUE);
		break;
	case Stage1_DayTime::PM6:
		sun_Pos_X = 1800;
		sun_Pos_Y = 400;
		DrawGraph(sun_Pos_X, sun_Pos_Y, Sun_Tex, TRUE);
		break;
	case Stage1_DayTime::PM9:
		moon_Pos_X = 100;
		moon_Pos_Y = 400;
		DrawGraph(0, 0, night_Back_Tex, TRUE);
		DrawGraph(moon_Pos_X, moon_Pos_Y, Moon_Tex, TRUE);
		break;
	case Stage1_DayTime::PM11:
		moon_Pos_X = 500;
		moon_Pos_Y = 200;
		DrawGraph(0, 0, night_Back_Tex, TRUE);
		DrawGraph(moon_Pos_X, moon_Pos_Y, Moon_Tex, TRUE);
		break;
	case Stage1_DayTime::PM12:
		moon_Pos_X = 900;
		moon_Pos_Y = 0;
		DrawGraph(0, 0, night_Back_Tex, TRUE);
		DrawGraph(moon_Pos_X, moon_Pos_Y, Moon_Tex, TRUE);
		break;
	case Stage1_DayTime::AM3:
		moon_Pos_X = 1400;
		moon_Pos_Y = 200;
		DrawGraph(0, 0, night_Back_Tex, TRUE);
		DrawGraph(moon_Pos_X, moon_Pos_Y, Moon_Tex, TRUE);
		break;
	case Stage1_DayTime::AM5:
		moon_Pos_X = 1800;
		moon_Pos_Y = 400;
		DrawGraph(0, 0, night_Back_Tex, TRUE);
		DrawGraph(moon_Pos_X, moon_Pos_Y, Moon_Tex, TRUE);
		break;

	}
}

void Stage1_DayTime::Finish()
{

}
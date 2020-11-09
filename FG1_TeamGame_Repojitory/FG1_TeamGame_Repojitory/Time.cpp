#include "Time.h"

void Time::Init()
{
	time = 0;
}

int Time::nowTime()
{
	time += 1;
	if (time >= 2800)
	{
		time = 0;
	}
	DrawFormatString(0, 0, (255, 255, 255), "time:%d", time);
	return time;
}

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

//ƒQ[ƒ€ƒ^ƒCƒ€
void Time::wait_func()
{
	int term;
	static int t = 0;
	term = GetNowCount() - t;
	if (16 - term > 0)
		Sleep(16-term);
	t = GetNowCount();
	return;
}

void Time::DeltaTime()
{
}
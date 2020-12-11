#include "FrameRate.h"

FrameRate::FrameRate()
{
	mStartTime = 0;
	mCount = 0;
	mFps = 0;
}

bool FrameRate::Update()
{
	if (mCount == 0)
	{
		//1フレーム目なら時刻を記憶
		mStartTime = GetNowCount();
	}
	if (mCount == N)
	{//60フレーム目なら平均を計算する
		int t = GetNowCount();
		mFps = 1000.f / ((t - mStartTime) / (float)N);
		mCount++;
		return true;
	}
	mCount++;
	return true;
}

void FrameRate::Draw()
{
	
}

void FrameRate::Wait()
{
	
}
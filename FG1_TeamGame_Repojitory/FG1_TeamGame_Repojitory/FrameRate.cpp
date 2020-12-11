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
		//1�t���[���ڂȂ玞�����L��
		mStartTime = GetNowCount();
	}
	if (mCount == N)
	{//60�t���[���ڂȂ畽�ς��v�Z����
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
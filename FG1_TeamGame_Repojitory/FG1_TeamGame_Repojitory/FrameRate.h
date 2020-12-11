#pragma once
#include"DxLib.h"
#include<math.h>

class FrameRate
{
	int mStartTime;//測定開始時刻
	int mCount;//カウンタ
	float mFps;//FPS
	static const int N = 60;//平均を取るサンプル数
	static const int FPS = 60;//設定したFPS
	
public:
	FrameRate();
	bool Update();
	void Draw();
	void Wait();
};


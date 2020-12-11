#pragma once
#include"DxLib.h"
#include<math.h>

class FrameRate
{
	int mStartTime;//����J�n����
	int mCount;//�J�E���^
	float mFps;//FPS
	static const int N = 60;//���ς����T���v����
	static const int FPS = 60;//�ݒ肵��FPS
	
public:
	FrameRate();
	bool Update();
	void Draw();
	void Wait();
};


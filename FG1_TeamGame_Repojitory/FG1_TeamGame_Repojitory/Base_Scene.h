#pragma once
#define MAP_WIDTH 100
#define MAP_HEIGHT 17
#define BLOCK_SIZE 64
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
class Base_Scene
{
public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Finish() = 0;
};


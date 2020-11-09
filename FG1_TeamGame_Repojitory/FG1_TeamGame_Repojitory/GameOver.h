#pragma once
#include<DxLib.h>
#include"Base_Scene.h"
#include"Scene_Manager.h"
#include"Input.h"
class GameOver :public Base_Scene
{
private:
	int GameOver_Tex;
	int tex_Pos_X;
	int tex_Pos_Y;
public:
	GameOver();
	~GameOver();
	void Init()override;
	void Update()override;
	void Draw()override;
	void Finish()override;

	Input keyInput;
	Scene_Manager* scene_Manager;

};


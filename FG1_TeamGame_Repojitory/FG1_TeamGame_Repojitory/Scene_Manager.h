#pragma once
#include"Base_Scene.h"

class Base_Scene;

class Scene_Manager
{
private:
	static Base_Scene* m_pScene_1;
public:
	enum Scene {
		TITLE,
		STAGE1,
		CLEAR,
		GAMEOVER,
	};

	void Change_Scene(Scene scene);
	void Init();
	void Update();
	void Draw();
	void Finish();

};


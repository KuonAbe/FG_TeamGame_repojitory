#pragma once
#include<DxLib.h>
#include<iostream>

extern int key[256];

class Input
{
private:
	char currentKey[256];
	char oldKey[256];
public:
	void Update();
	bool InputKeyTrigger(int key);
};


#include "Input.h"

void Input::Update()
{
	for (int i = 0; i < 256; i++)
	{
		oldKey[i] = currentKey[i];
	}
	GetHitKeyStateAll(currentKey);

}

bool Input::InputKeyTrigger(int key)
{
	return (currentKey[key] == 1 && oldKey[key] == 0);

}
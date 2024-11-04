#pragma once
#include "..\\MyEngine_SOURCE\\MySceneManager.h"

#include "MyPlayScene.h"

namespace my
{
	void LoadScenes()
	{
		MySceneManager::CreateScene<MyPlayScene>(L"PlayScene");

		MySceneManager::LoadScene(L"PlayScene");
	}
}
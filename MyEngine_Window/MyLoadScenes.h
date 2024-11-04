#pragma once
#include "..\\MyEngine_SOURCE\\MySceneManager.h"

#include "MyPlayScene.h"
#include "MyTitleScene.h"

namespace my
{
	void LoadScenes()
	{
		MySceneManager::CreateScene<MyTitleScene>(L"TitleScene");
		MySceneManager::CreateScene<MyPlayScene>(L"PlayScene");

		MySceneManager::LoadScene(L"PlayScene");
	}
}
#pragma once
#include "..\\MyEngine_SOURCE\\MySceneManager.h"

#include "MyPlayScene.h"
#include "MyTitleScene.h"
#include "MyToolScene.h"

namespace my
{
	void LoadScenes()
	{
		//MySceneManager::CreateScene<MyTitleScene>(L"TitleScene");
		MySceneManager::CreateScene<MyPlayScene>(L"PlayScene");
		//MySceneManager::CreateScene<MyToolScene>(L"ToolScene");

		MySceneManager::LoadScene(L"PlayScene");
	}
}
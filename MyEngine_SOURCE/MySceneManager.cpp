#include "MySceneManager.h"

namespace my
{
	std::map<const std::wstring, MyScene*> MySceneManager::mScene = {};
	MyScene* MySceneManager::mActiveScene = nullptr;

	void MySceneManager::Initialize()
	{

	}

	void MySceneManager::Update()
	{
		mActiveScene->Update();
	}

	void MySceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void MySceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}
}
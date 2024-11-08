#include "MySceneManager.h"

namespace my
{
	std::map<const std::wstring, MyScene*> MySceneManager::mScene = {};
	MyScene* MySceneManager::mActiveScene = nullptr;

	MyScene* MySceneManager::LoadScene(const std::wstring& name)
	{
		if (mActiveScene)
			mActiveScene->OnExit();

		std::map<std::wstring, MyScene*>::iterator iter
			= mScene.find(name);

		if (iter == mScene.end())
			return nullptr;

		mActiveScene = iter->second;
		mActiveScene->OnEnter();

		return iter->second;
	}

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

	void MySceneManager::Release()
	{
		for (auto& iter : mScene)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
}
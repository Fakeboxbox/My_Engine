#include "MySceneManager.h"
#include "MyDontDestroyOnLoad.h"

namespace my
{
	std::map<const std::wstring, MyScene*> MySceneManager::mScene = {};
	MyScene* MySceneManager::mActiveScene = nullptr;
	MyScene* MySceneManager::mDontDestroyOnLoad = nullptr;

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
		mDontDestroyOnLoad = CreateScene<MyDontDestroyOnLoad>(L"DontDestroyOnLoad");
	}

	void MySceneManager::Update()
	{
		mActiveScene->Update();
		mDontDestroyOnLoad->Update();
	}

	void MySceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
		mDontDestroyOnLoad->LateUpdate();
	}

	void MySceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
		mDontDestroyOnLoad->Render(hdc);
	}

	void MySceneManager::Destroy()
	{
		mActiveScene->Destroy();
		mDontDestroyOnLoad->Destroy();
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
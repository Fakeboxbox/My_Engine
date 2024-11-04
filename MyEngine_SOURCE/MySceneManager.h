#pragma once
#include "MyScene.h"

namespace my
{
	class MySceneManager
	{
	public:
		template <typename T>
		static MyScene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			scene->Initialize();

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		static MyScene* LoadScene(const std::wstring& name)
		{
			std::map<const std::wstring, MyScene*>::iterator iter
			= mScene.find(name);

			if (iter == mScene.end())
			{
				return nullptr;
			}

			mActiveScene = iter->second;

			return iter->second;
		}

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		static std::map<const std::wstring, MyScene*> mScene;
		static MyScene* mActiveScene;
	};
}
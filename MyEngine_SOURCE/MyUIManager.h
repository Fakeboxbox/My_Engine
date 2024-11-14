#pragma once
#include "CommonInclude.h"
#include "MyUIBase.h"

namespace my
{
	using namespace enums;
	class MyUIManager
	{
	public:
		static void Initialize();
		static void OnLoad(eUIType type);
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void OnComplete(MyUIBase* addUI);
		static void OnFail();
		static void Release();

		static void Push(eUIType type);
		static void Pop(eUIType type);

	private:
		static std::unordered_map<eUIType, MyUIBase*> mUIs;
		static std::stack<MyUIBase*> mUIBases;
		static std::queue<eUIType> mRequestUIQueue;
		static MyUIBase* mActiveUI;
	};
}


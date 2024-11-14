#include "MyUIManager.h"
#include "MyUIHUD.h"
#include "MyUIButton.h"

namespace my
{
	std::unordered_map<eUIType, MyUIBase*> MyUIManager::mUIs = {};
	std::stack<MyUIBase*> MyUIManager::mUIBases = {};
	std::queue<eUIType> MyUIManager::mRequestUIQueue = {};
	MyUIBase* MyUIManager::mActiveUI = nullptr;

	void MyUIManager::Initialize()
	{
		MyUIHUD* hud = new MyUIHUD();
		mUIs.insert(std::make_pair(eUIType::HpBar, hud));

		MyUIButton* button = new MyUIButton();
		mUIs.insert(std::make_pair(eUIType::Button, button));
	}

	void MyUIManager::OnLoad(eUIType type)
	{
		std::unordered_map<eUIType, MyUIBase*>::iterator iter
			= mUIs.find(type);

		if (iter == mUIs.end())
		{
			OnFail();
			return;
		}

		OnComplete(iter->second);
	}

	void MyUIManager::Update()
	{
		std::stack<MyUIBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			MyUIBase* uiBase = uiBases.top();
			if (uiBase)
			{
				uiBase->Update();
				uiBases.pop();
			}
		}

		if (mRequestUIQueue.size() > 0)
		{
			eUIType requestUI = mRequestUIQueue.front();
			mRequestUIQueue.pop();
			OnLoad(requestUI);
		}
	}

	void MyUIManager::LateUpdate()
	{
		std::stack<MyUIBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			MyUIBase* uiBase = uiBases.top();
			if (uiBase)
			{
				uiBase->LateUpdate();
				uiBases.pop();
			}
		}
	}

	void MyUIManager::Render(HDC hdc)
	{
		if (mUIBases.size() <= 0)
			return;

		std::vector<MyUIBase*> buff;

		MyUIBase* uiBase = nullptr;
		while (mUIBases.size() > 0)
		{
			uiBase = mUIBases.top();
			mUIBases.pop();
			buff.push_back(uiBase);
		}
		std::reverse(buff.begin(), buff.end());

		for (MyUIBase* ui : buff)
		{
			ui->Render(hdc);
			mUIBases.push(ui);
		}
	}

	void MyUIManager::OnComplete(MyUIBase* addUI)
	{
		if (addUI == nullptr)
			return;

		addUI->Initialize();
		addUI->Active();
		addUI->Update();

		// 만약에 현재 추가된 UI가 전체화면이라면
		// 전체화면인 UI를 제외한 나머지를 전부 비활성화

		if (addUI->IsFullScreen())
		{
			std::stack<MyUIBase*> uiBases = mUIBases;
			while (!uiBases.empty())
			{
				MyUIBase* uiBase = uiBases.top();
				uiBases.pop();
				if (uiBase)
				{
					uiBase->InActive();
				}
			}
		}

		mUIBases.push(addUI);
		mActiveUI = nullptr;
	}

	void MyUIManager::OnFail()
	{
		mActiveUI = nullptr;
	}

	void MyUIManager::Release()
	{
		for (auto iter : mUIs)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}

	void MyUIManager::Push(eUIType type)
	{
		mRequestUIQueue.push(type);
	}

	void MyUIManager::Pop(eUIType type)
	{
		if (mUIBases.size() <= 0)
			return;

		// 해당 UI 한개만 스택에서 빼줘야한다.
		std::stack<MyUIBase*> tempStack;

		MyUIBase* uiBase = nullptr;
		while(mUIBases.size() > 0)
		{
			uiBase = mUIBases.top();
			mUIBases.pop();

			if (uiBase->GetType() != type)
			{
				tempStack.push(uiBase);
				continue;
			}

			if (uiBase->IsFullScreen())
			{
				std::stack<MyUIBase*> uiBases = mUIBases;
				while (!uiBases.empty())
				{
					MyUIBase* uiBase = uiBases.top();
					uiBases.pop();
					if (uiBase)
					{
						uiBase->Active();
						break;
					}
				}
			}

			uiBase->UIClear();
		}

		while (tempStack.size() > 0)
		{
			uiBase = tempStack.top();
			tempStack.pop();
			mUIBases.push(uiBase);
		}
	}
}
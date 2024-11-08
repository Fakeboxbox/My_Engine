#include "MyLayer.h"

namespace my
{
	MyLayer::MyLayer()
		: mGameObjects{}
	{

	}

	MyLayer::~MyLayer()
	{
		for (MyGameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			delete gameObj;
			gameObj = nullptr;
		}
	}

	void MyLayer::Initialize()
	{
		for (MyGameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
			{
				continue;
			}

			gameObj->Initialize();
		}
	}

	void MyLayer::Update()
	{
		for (MyGameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
			{
				continue;
			}

			gameObj->Update();
		}
	}

	void MyLayer::LateUpdate()
	{
		for (MyGameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
			{
				continue;
			}

			gameObj->LateUpdate();
		}
	}

	void MyLayer::Render(HDC hdc)
	{
		for (MyGameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
			{
				continue;
			}

			gameObj->Render(hdc);
		}
	}

	void MyLayer::AddGameObject(MyGameObject* gameObject)
	{
		if (gameObject == nullptr)
		{
			return;
		}

		mGameObjects.push_back(gameObject);
	}
}
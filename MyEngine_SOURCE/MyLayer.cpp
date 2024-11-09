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

			MyGameObject::eState state = gameObj->GetActive();
			if (state == MyGameObject::eState::Paused
				|| state == MyGameObject::eState::Dead)
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

			MyGameObject::eState state = gameObj->GetActive();
			if (state == MyGameObject::eState::Paused
				|| state == MyGameObject::eState::Dead)
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

			MyGameObject::eState state = gameObj->GetActive();
			if (state == MyGameObject::eState::Paused
				|| state == MyGameObject::eState::Dead)
			{
				continue;
			}

			gameObj->Render(hdc);
		}
	}

	void MyLayer::Destroy()
	{
		for (GameObjectIter iter = mGameObjects.begin()
			; iter != mGameObjects.end()
			; )
		{
			MyGameObject::eState active = (*iter)->GetActive();
			if (active == MyGameObject::eState::Dead)
			{
				MyGameObject* deathObj = (*iter);
				iter = mGameObjects.erase(iter);

				delete deathObj;
				deathObj = nullptr;

				continue;
			}

			iter++;
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
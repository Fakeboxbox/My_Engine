#include "MyScene.h"

namespace my
{
	MyScene::MyScene()
		: mGameObjects{}
	{

	}

	MyScene::~MyScene()
	{

	}

	void MyScene::Initialize()
	{

	}

	void MyScene::Update()
	{
		for (MyGameObject* gameObj : mGameObjects)
		{
			gameObj->Update();
		}
	}

	void MyScene::LateUpdate()
	{
		for (MyGameObject* gameObj : mGameObjects)
		{
			gameObj->LateUpdate();
		}
	}

	void MyScene::Render(HDC hdc)
	{
		for (MyGameObject* gameObj : mGameObjects)
		{
			gameObj->Render(hdc);
		}
	}

	void MyScene::AddGameObject(MyGameObject* gameObject)
	{
		mGameObjects.push_back(gameObject);
	}
}
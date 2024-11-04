#include "MyPlayScene.h"
#include "MyGameObject.h"

namespace my
{
	MyPlayScene::MyPlayScene()
	{

	}

	MyPlayScene::~MyPlayScene()
	{

	}

	void MyPlayScene::Initialize()
	{
		for (size_t i = 0; i < 100; ++i)
		{
			MyGameObject* obj = new MyGameObject();
			AddGameObject(obj);

			obj->SetPosition(rand() % 1600, rand() % 900);
		}

	}

	void MyPlayScene::Update()
	{
		MyScene::Update();
	}

	void MyPlayScene::LateUpdate()
	{
		MyScene::LateUpdate();
	}

	void MyPlayScene::Render(HDC hdc)
	{
		MyScene::Render(hdc);
	}
}
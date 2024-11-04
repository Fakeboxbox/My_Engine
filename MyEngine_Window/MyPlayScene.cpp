#include "MyPlayScene.h"
#include "MyGameObject.h"
#include "MyPlayer.h"
#include "MyTransform.h"
#include "MySpriteRenderer.h"

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
		/*for (size_t i = 0; i < 100; ++i)
		{
			MyGameObject* obj = new MyGameObject();
			AddGameObject(obj);

			obj->SetPosition(rand() % 1600, rand() % 900);
		}*/

		{
			MyPlayer* pl = new MyPlayer();
			MyTransform* tr = pl->AddComponent<MyTransform>();
			tr->SetPos(800, 450);
			tr->SetName(L"TR");
			MySpriteRenderer* sr = pl->AddComponent<MySpriteRenderer>();
			sr->SetName(L"SR");

			AddGameObject(pl);
		}

		{
			MyPlayer* pl = new MyPlayer();
			MyTransform* tr = pl->AddComponent<MyTransform>();
			tr->SetPos(300, 450);
			tr->SetName(L"TR");
			MySpriteRenderer* sr = pl->AddComponent<MySpriteRenderer>();
			sr->SetName(L"SR");

			AddGameObject(pl);
		}

		{
			MyPlayer* pl = new MyPlayer();
			MyTransform* tr = pl->AddComponent<MyTransform>();
			tr->SetPos(100, 650);
			tr->SetName(L"TR");
			MySpriteRenderer* sr = pl->AddComponent<MySpriteRenderer>();
			sr->SetName(L"SR");

			AddGameObject(pl);
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
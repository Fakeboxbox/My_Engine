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
		{
			MyPlayer* bg = new MyPlayer();
			MyTransform* tr = bg->AddComponent<MyTransform>();
			tr->SetPos(Vector2(0, 0));
			tr->SetName(L"TR");
			MySpriteRenderer* sr = bg->AddComponent<MySpriteRenderer>();
			sr->SetName(L"SR");
			sr->ImageLoad(L"C:\\Users\\danpa\\OneDrive\\πŸ≈¡ »≠∏È\\Project\\MyEngine\\Resources\\CloudOcean.png");

			AddGameObject(bg);
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
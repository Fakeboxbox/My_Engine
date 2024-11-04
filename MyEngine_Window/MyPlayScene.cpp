#include "MyPlayScene.h"
#include "MyGameObject.h"
#include "MyPlayer.h"
#include "MyTransform.h"
#include "MySpriteRenderer.h"
#include "MyInput.h"
#include "MyTitleScene.h"
#include "MySceneManager.h"
#include "MyObject.h"

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
			/*bg = new MyPlayer();
			MyTransform* tr = bg->AddComponent<MyTransform>();
			tr->SetPos(Vector2(0, 0));
			tr->SetName(L"TR");
			MySpriteRenderer* sr = bg->AddComponent<MySpriteRenderer>();
			sr->SetName(L"SR");
			sr->ImageLoad(L"C:\\Users\\danpa\\OneDrive\\πŸ≈¡ »≠∏È\\Project\\MyEngine\\Resources\\CloudOcean.png");

			AddGameObject(bg, eLayerType::BackGround);*/

			bg = object::Instantiate<MyPlayer>(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));
			MySpriteRenderer* sr = bg->AddComponent<MySpriteRenderer>();
			sr->ImageLoad(L"C:\\Users\\danpa\\OneDrive\\πŸ≈¡ »≠∏È\\Project\\MyEngine\\Resources\\CloudOcean.png");

		}
	}

	void MyPlayScene::Update()
	{
		MyScene::Update();
	}

	void MyPlayScene::LateUpdate()
	{
		MyScene::LateUpdate();

		if (MyInput::GetKeyDown(eKeyCode::E))
		{
			MySceneManager::LoadScene(L"TitleScene");
		}
	}

	void MyPlayScene::Render(HDC hdc)
	{
		MyScene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 16, str, 10);
	}

	void MyPlayScene::OnEnter()
	{

	}

	void MyPlayScene::OnExit()
	{
		/*MyTransform* tr = bg->GetComponent<MyTransform>();
		tr->SetPos(Vector2(0, 0));*/
	}
}
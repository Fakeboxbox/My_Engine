#include "MyTitleScene.h"
#include "MyInput.h"
#include "MyPlayScene.h"
#include "MySceneManager.h"

namespace my
{
	MyTitleScene::MyTitleScene()
	{

	}

	MyTitleScene::~MyTitleScene()
	{

	}

	void MyTitleScene::Initialize()
	{
		MyScene::Initialize();
	}

	void MyTitleScene::Update()
	{
		MyScene::Update();
	}

	void MyTitleScene::LateUpdate()
	{
		MyScene::LateUpdate();

		if (MyInput::GetKeyDown(eKeyCode::E))
		{
			MySceneManager::LoadScene(L"PlayScene");
		}
	}

	void MyTitleScene::Render(HDC hdc)
	{
		MyScene::Render(hdc);
		wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 0, 16, str, 11);
	}

	void MyTitleScene::OnEnter()
	{

	}

	void MyTitleScene::OnExit()
	{

	}
}
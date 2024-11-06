#include "MyPlayScene.h"
#include "MyGameObject.h"
#include "MyPlayer.h"
#include "MyTransform.h"
#include "MySpriteRenderer.h"
#include "MyInput.h"
#include "MyTitleScene.h"
#include "MySceneManager.h"
#include "MyObject.h"
#include "MyTexture.h"
#include "MyResources.h"
#include "MyPlayerScript.h"
#include "MyCamera.h"
#include "MyRenderer.h"
#include "MyAnimator.h"

namespace my
{
	MyPlayScene::MyPlayScene()
		: mPlayer(nullptr)
	{

	}

	MyPlayScene::~MyPlayScene()
	{

	}

	void MyPlayScene::Initialize()
	{
		MyGameObject* camera = object::Instantiate<MyGameObject>(enums::eLayerType::None, Vector2(343.0f, 442.0f));
		MyCamera* cameraComp = camera->AddComponent<MyCamera>();
		renderer::mainCamera = cameraComp;
		//camera->AddComponent<MyPlayerScript>();

		// ���ӿ�����Ʈ�� ��������� ���ҽ����� ���� Load�صθ� ����.
		mPlayer = object::Instantiate<MyPlayer>(enums::eLayerType::Player);
		//MySpriteRenderer* sr = mPlayer->AddComponent<MySpriteRenderer>();
		//sr->SetSize(Vector2(3.0f, 3.0f));
		mPlayer->AddComponent<MyPlayerScript>();

		graphcis::MyTexture* packmanTexture = MyResources::Find<graphcis::MyTexture>(L"Cat");
		MyAnimator* animator = mPlayer->AddComponent<MyAnimator>();
		animator->CreateAnimation(L"CatFrontMove", packmanTexture
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.5f);

		animator->PlayAnimation(L"CatFrontMove", true);
		//sr->SetTexture(packmanTexture);

		MyGameObject* bg = object::Instantiate<MyGameObject>(enums::eLayerType::BackGround);
		MySpriteRenderer* bgSr = bg->AddComponent<MySpriteRenderer>();
		bgSr->SetSize(Vector2(3.0f, 3.0f));

		graphcis::MyTexture* bgTexture = MyResources::Find<graphcis::MyTexture>(L"Map");
		bgSr->SetTexture(bgTexture);

		// ���� ������Ʈ �����Ŀ� ���̾�� ���ӿ�����Ʈ���� init �Լ��� ȣ��
		MyScene::Initialize();
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
		/*wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 16, str, 10);*/
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
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
#include "MyCat.h"
#include "MyCatScript.h"

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
		// 게임오브젝트를 만들기전에 리소스들을 전부 Load해두면 좋다.
		MyGameObject* camera = object::Instantiate<MyGameObject>(enums::eLayerType::None, Vector2(343.0f, 442.0f));
		MyCamera* cameraComp = camera->AddComponent<MyCamera>();
		renderer::mainCamera = cameraComp;

		mPlayer = object::Instantiate<MyPlayer>(enums::eLayerType::particle);
		//MySpriteRenderer* sr = mPlayer->AddComponent<MySpriteRenderer>();
		//sr->SetSize(Vector2(3.0f, 3.0f));
		mPlayer->AddComponent<MyPlayerScript>();

		//graphcis::MyTexture* packmanTexture = MyResources::Find<graphcis::MyTexture>(L"MapleEffect");
		//MyAnimator* animator = mPlayer->AddComponent<MyAnimator>();
		//animator->CreateAnimation(L"CatFrontMove", packmanTexture
		//	, Vector2(0.0f, 0.0f), Vector2(386.0f, 246.0f), Vector2::Zero, 8, 0.1f);
		//animator->PlayAnimation(L"CatFrontMove", true);

		graphcis::MyTexture* packmanTexture = MyResources::Find<graphcis::MyTexture>(L"Cat");
		MyAnimator* animator = mPlayer->AddComponent<MyAnimator>();
		
		animator->CreateAnimation(L"DownWalk", packmanTexture
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		animator->CreateAnimation(L"RightWalk", packmanTexture
			, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		animator->CreateAnimation(L"UpWalk", packmanTexture
			, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		animator->CreateAnimation(L"LeftWalk", packmanTexture
			, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		animator->CreateAnimation(L"SitDown", packmanTexture
			, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		animator->CreateAnimation(L"Grooming", packmanTexture
			, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		animator->PlayAnimation(L"SitDown", false);

		mPlayer->GetComponent<MyTransform>()->SetPos(Vector2(100.0f, 100.0f));
		mPlayer->GetComponent<MyTransform>()->SetScale(Vector2(2.0f, 2.0f));
		//mPlayer->GetComponent<MyTransform>()->SetRotation(30.0f);
		//sr->SetTexture(packmanTexture);

		//MyGameObject* bg = object::Instantiate<MyGameObject>(enums::eLayerType::Player);
		//MySpriteRenderer* bgSr = bg->AddComponent<MySpriteRenderer>();
		//bgSr->SetSize(Vector2(3.0f, 3.0f));

		//graphcis::MyTexture* bgTexture = MyResources::Find<graphcis::MyTexture>(L"Bubble");
		//bgSr->SetTexture(bgTexture);

		MyCat* cat = object::Instantiate<MyCat>(enums::eLayerType::particle);
		cat->AddComponent<MyCatScript>();

		graphcis::MyTexture* CatTexture = MyResources::Find<graphcis::MyTexture>(L"Cat");
		MyAnimator* catAnimator = cat->AddComponent<MyAnimator>();

		catAnimator->CreateAnimation(L"DownWalk", CatTexture
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		catAnimator->CreateAnimation(L"RightWalk", CatTexture
			, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		catAnimator->CreateAnimation(L"UpWalk", CatTexture
			, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		catAnimator->CreateAnimation(L"LeftWalk", CatTexture
			, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		catAnimator->CreateAnimation(L"SitDown", CatTexture
			, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		catAnimator->CreateAnimation(L"Grooming", CatTexture
			, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		catAnimator->CreateAnimation(L"LayDown", CatTexture
			, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		catAnimator->PlayAnimation(L"SitDown", false);

		cat->GetComponent<MyTransform>()->SetPos(Vector2(200.0f, 200.0f));
		cat->GetComponent<MyTransform>()->SetScale(Vector2(2.0f, 2.0f));

		// 게임 오브젝트 생성후에 레이어와 게임오브젝트들의 init 함수를 호출
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
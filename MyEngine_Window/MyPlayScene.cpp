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
#include "MyBoxCollider2D.h"
#include "MyCircleCollider2D.h"
#include "MyColliderManager.h"

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
		// 콜라이더끼리의 충돌체크 활성화 코드
		MyColliderManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Animal, true);

		// 게임오브젝트를 만들기전에 리소스들을 전부 Load해두면 좋다.
		MyGameObject* camera = object::Instantiate<MyGameObject>(enums::eLayerType::None, Vector2(343.0f, 442.0f));
		MyCamera* cameraComp = camera->AddComponent<MyCamera>();
		renderer::mainCamera = cameraComp;

		//Player
		mPlayer = object::Instantiate<MyPlayer>(enums::eLayerType::Player);
		object::DontDestroyOnLoad(mPlayer);
		MyPlayerScript* plScript = mPlayer->AddComponent<MyPlayerScript>();

		//MyBoxCollider2D* collider = mPlayer->AddComponent<MyBoxCollider2D>();
		MyCircleCollider2D* collider = mPlayer->AddComponent<MyCircleCollider2D>();
		collider->SetOffset(Vector2(-50.0f, -50.0f));

		graphcis::MyTexture* playerTexture = MyResources::Find<graphcis::MyTexture>(L"Player");
		MyAnimator* playerAnimator = mPlayer->AddComponent<MyAnimator>();
		
		playerAnimator->CreateAnimation(L"Idle", playerTexture
			, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);

		playerAnimator->CreateAnimation(L"FrontGiveWater", playerTexture
			, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.1f);

		playerAnimator->PlayAnimation(L"Idle", false);

		playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&MyPlayerScript::AttackEffect, plScript);

		mPlayer->GetComponent<MyTransform>()->SetPos(Vector2(300.0f, 250.0f));


		//Cat
		MyCat* cat = object::Instantiate<MyCat>(enums::eLayerType::Animal);
		//cat->SetActive(true);
		cat->AddComponent<MyCatScript>();
		//cameraComp->SetTarget(cat);

		graphcis::MyTexture* CatTexture = MyResources::Find<graphcis::MyTexture>(L"Cat");
		MyAnimator* catAnimator = cat->AddComponent<MyAnimator>();

		//MyBoxCollider2D* catCollider = cat->AddComponent<MyBoxCollider2D>();
		MyCircleCollider2D* catCollider = cat->AddComponent<MyCircleCollider2D>();
		catCollider->SetOffset(Vector2(-50.0f, -50.0f));

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

		// cat -> mushroom 애니메이션폴더 구조 적용 테스트 코드 
		catAnimator->CreateAnimationByFolder(L"MushroomIdle", L"..\\Resources\\Mushroom", Vector2::Zero, 0.1f);
		catAnimator->PlayAnimation(L"MushroomIdle", true);

		cat->GetComponent<MyTransform>()->SetPos(Vector2(200.0f, 200.0f));
		cat->GetComponent<MyTransform>()->SetScale(Vector2(1.0f, 1.0f));

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
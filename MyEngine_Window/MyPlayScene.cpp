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
#include "MyTile.h"
#include "MyTilemapRenderer.h"
#include "MyRigdbody.h"
#include "MyFloor.h"
#include "MyFloorScript.h"

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
		// 저장한 맵 불러오는 예시
		/*FILE* pFile = nullptr;
		_wfopen_s(&pFile, L"..\\Resources\\Test", L"rb");

		while (true)
		{
			int idxX = 0;
			int idxY = 0;

			int posX = 0;
			int posY = 0;

			if (fread(&idxX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&idxY, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posY, sizeof(int), 1, pFile) == NULL)
				break;

			MyTile* tile = object::Instantiate<MyTile>(eLayerType::Tile, Vector2(posX, posY));
			MyTilemapRenderer* tmr = tile->AddComponent<MyTilemapRenderer>();
			tmr->SetTexture(MyResources::Find<graphics::MyTexture>(L"SpringFloor"));
			tmr->SetIndex(Vector2(idxX, idxY));
		}
		fclose(pFile);*/

		// 게임오브젝트를 만들기전에 리소스들을 전부 Load해두면 좋다.
		MyGameObject* camera = object::Instantiate<MyGameObject>(enums::eLayerType::None, Vector2(343.0f, 442.0f));
		MyCamera* cameraComp = camera->AddComponent<MyCamera>();
		renderer::mainCamera = cameraComp;

		//Player
		mPlayer = object::Instantiate<MyPlayer>(enums::eLayerType::Player);
		object::DontDestroyOnLoad(mPlayer);
		MyPlayerScript* plScript = mPlayer->AddComponent<MyPlayerScript>();

		MyBoxCollider2D* collider = mPlayer->AddComponent<MyBoxCollider2D>();
		collider->SetOffset(Vector2(-50.0f, -50.0f));

		graphics::MyTexture* playerTexture = MyResources::Find<graphics::MyTexture>(L"Player");
		MyAnimator* playerAnimator = mPlayer->AddComponent<MyAnimator>();
		
		playerAnimator->CreateAnimation(L"Idle", playerTexture
			, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);

		playerAnimator->CreateAnimation(L"FrontGiveWater", playerTexture
			, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.1f);

		playerAnimator->PlayAnimation(L"Idle", false);

		playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&MyPlayerScript::AttackEffect, plScript);

		mPlayer->GetComponent<MyTransform>()->SetPos(Vector2(300.0f, 250.0f));
		mPlayer->AddComponent<MyRigdbody>();

		MyFloor* floor = object::Instantiate<MyFloor>(eLayerType::Floor, Vector2(100.0f, 600.0f));
		floor->SetName(L"Floor");
		MyBoxCollider2D* floorCol = floor->AddComponent<MyBoxCollider2D>();
		floorCol->SetSize(Vector2(3.0f, 1.0f));
		floor->AddComponent<MyFloorScript>();

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
		MyScene::OnEnter();

		MyColliderManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Animal, true);
		MyColliderManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Floor, true);
	}

	void MyPlayScene::OnExit()
	{
		/*MyTransform* tr = bg->GetComponent<MyTransform>();
		tr->SetPos(Vector2(0, 0));*/
	}
}
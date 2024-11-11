#include "MyPlayerScript.h"
#include "MyInput.h"
#include "MyTransform.h"
#include "MyTime.h"
#include "MyGameObject.h"
#include "MyAnimator.h"
#include "MyCat.h"
#include "MyCatScript.h"
#include "MyObject.h"
#include "MyCollider.h"
#include "MyResources.h"

namespace my
{
	MyPlayerScript::MyPlayerScript()
		: mState(eState::Idle)
		, mAnimator(nullptr)
	{

	}

	MyPlayerScript::~MyPlayerScript()
	{

	}

	void MyPlayerScript::Initialize()
	{

	}

	void MyPlayerScript::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<MyAnimator>();

		switch (mState)
		{
		case my::MyPlayerScript::eState::Idle:
			idle();
			break;

		case my::MyPlayerScript::eState::Walk:
			move();
			break;

		case my::MyPlayerScript::eState::Sleep:
			break;

		case my::MyPlayerScript::eState::GiveWater:
			giveWater();
			break;

		case my::MyPlayerScript::eState::Attack:
			break;

		default:
			break;
		}
	}

	void MyPlayerScript::LateUpdate()
	{

	}

	void MyPlayerScript::Render(HDC hdc)
	{

	}

	void MyPlayerScript::AttackEffect()
	{
		////Cat
		//MyCat* cat = object::Instantiate<MyCat>(enums::eLayerType::Animal);
		//MyCatScript* catSrc = cat->AddComponent<MyCatScript>();

		////벡터 테스트 코드
		//catSrc->SetPlayer(GetOwner());

		//graphcis::MyTexture* CatTexture = MyResources::Find<graphcis::MyTexture>(L"Cat");
		//MyAnimator* catAnimator = cat->AddComponent<MyAnimator>();

		//catAnimator->CreateAnimation(L"DownWalk", CatTexture
		//	, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		//catAnimator->CreateAnimation(L"RightWalk", CatTexture
		//	, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		//catAnimator->CreateAnimation(L"UpWalk", CatTexture
		//	, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		//catAnimator->CreateAnimation(L"LeftWalk", CatTexture
		//	, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		//catAnimator->CreateAnimation(L"SitDown", CatTexture
		//	, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		//catAnimator->CreateAnimation(L"Grooming", CatTexture
		//	, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		//catAnimator->CreateAnimation(L"LayDown", CatTexture
		//	, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		//catAnimator->PlayAnimation(L"SitDown", false);

		//MyTransform* tr = GetOwner()->GetComponent<MyTransform>();

		//cat->GetComponent<MyTransform>()->SetPos(tr->GetPosition());
		//cat->GetComponent<MyTransform>()->SetScale(Vector2(2.0f, 2.0f));

		//Vector2 mousePos = MyInput::GetMousePosition();
		//catSrc->mDest = mousePos;
	}

	void MyPlayerScript::OnCollisionEnter(MyCollider* other)
	{
		other->GetOwner()->GetComponent<MyTransform>()->SetPos(Vector2(400.0f, 500.0f));
	}

	void MyPlayerScript::OnCollisionStay(MyCollider* other)
	{
		int a = 0;
	}

	void MyPlayerScript::OnCollisionExit(MyCollider* other)
	{
		int a = 0;
	}

	void MyPlayerScript::idle()
	{
		if (MyInput::GetKeyDown(eKeyCode::LButton))
		{
			//Cat
			MyCat* cat = object::Instantiate<MyCat>(enums::eLayerType::Animal);
			MyCatScript* catSrc = cat->AddComponent<MyCatScript>();

			//벡터 테스트 코드
			catSrc->SetPlayer(GetOwner());

			graphics::MyTexture* CatTexture = MyResources::Find<graphics::MyTexture>(L"Cat");
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

			MyTransform* tr = GetOwner()->GetComponent<MyTransform>();

			cat->GetComponent<MyTransform>()->SetPos(tr->GetPosition());
			cat->GetComponent<MyTransform>()->SetScale(Vector2(2.0f, 2.0f));

			Vector2 mousePos = MyInput::GetMousePosition();
			catSrc->mDest = mousePos;

			/*mState = MyPlayerScript::eState::GiveWater;
			mAnimator->PlayAnimation(L"FrontGiveWater", false);

			Vector2 mousePos = MyInput::GetMousePosition();*/
		}
		
		MyTransform* tr = GetOwner()->GetComponent<MyTransform>();
		Vector2 pos = tr->GetPosition();

		if (MyInput::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * MyTime::DeltaTime();
		}
		if (MyInput::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * MyTime::DeltaTime();
		}
		if (MyInput::GetKey(eKeyCode::Up))
		{
			pos.y -= 100.0f * MyTime::DeltaTime();
		}
		if (MyInput::GetKey(eKeyCode::Down))
		{
			pos.y += 100.0f * MyTime::DeltaTime();
		}

		tr->SetPos(pos);

		if (MyInput::GetKeyUp(eKeyCode::Right) || MyInput::GetKeyUp(eKeyCode::Left)
			|| MyInput::GetKeyUp(eKeyCode::Up) || MyInput::GetKeyUp(eKeyCode::Down))
		{
			mState = MyPlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"Idle", false);
		}
	}

	void MyPlayerScript::move()
	{
		MyTransform* tr = GetOwner()->GetComponent<MyTransform>();
		Vector2 pos = tr->GetPosition();

		if (MyInput::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * MyTime::DeltaTime();
		}
		if (MyInput::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * MyTime::DeltaTime();
		}
		if (MyInput::GetKey(eKeyCode::Up))
		{
			pos.y -= 100.0f * MyTime::DeltaTime();
		}
		if (MyInput::GetKey(eKeyCode::Down))
		{
			pos.y += 100.0f * MyTime::DeltaTime();
		}

		tr->SetPos(pos);

		if (MyInput::GetKeyUp(eKeyCode::Right) || MyInput::GetKeyUp(eKeyCode::Left)
			 || MyInput::GetKeyUp(eKeyCode::Up) || MyInput::GetKeyUp(eKeyCode::Down))
		{
			mState = MyPlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"Idle", false);
		}
	}

	void MyPlayerScript::giveWater()
	{
		if (mAnimator->IsCompleteAnimation())
		{
			mState = MyPlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"Idle", false);
		}
	}
}

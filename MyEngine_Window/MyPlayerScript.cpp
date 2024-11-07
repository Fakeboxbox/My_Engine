#include "MyPlayerScript.h"
#include "MyInput.h"
#include "MyTransform.h"
#include "MyTime.h"
#include "MyGameObject.h"
#include "MyAnimator.h"

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

	void MyPlayerScript::idle()
	{
		if (MyInput::GetKey(eKeyCode::LButton))
		{
			mState = MyPlayerScript::eState::GiveWater;
			mAnimator->PlayAnimation(L"FrontGiveWater", false);

			Vector2 mousePos = MyInput::GetMousePosition();
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

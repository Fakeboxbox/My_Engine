#include "MyPlayerScript.h"
#include "MyInput.h"
#include "MyTransform.h"
#include "MyTime.h"
#include "MyGameObject.h"
#include "MyAnimator.h"

namespace my
{
	MyPlayerScript::MyPlayerScript()
		: mState(eState::SitDown)
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
		case my::MyPlayerScript::eState::SitDown:
			sitDown();
			break;

		case my::MyPlayerScript::eState::Walk:
			move();
			break;

		case my::MyPlayerScript::eState::Sleep:
			break;

		case my::MyPlayerScript::eState::Attack:
			break;

		default:
			break;
		}

		/*if (MyInput::GetKey(eKeyCode::Right))
		{
			MyTransform* tr = GetOwner()->GetComponent<MyTransform>();
			Vector2 pos = tr->GetPosition();
			pos.x += 100.0f * MyTime::DeltaTime();
			tr->SetPos(pos);
		}

		if (MyInput::GetKey(eKeyCode::Left))
		{
			MyTransform* tr = GetOwner()->GetComponent<MyTransform>();
			Vector2 pos = tr->GetPosition();
			pos.x -= 100.0f * MyTime::DeltaTime();
			tr->SetPos(pos);
		}

		if (MyInput::GetKey(eKeyCode::Up))
		{
			MyTransform* tr = GetOwner()->GetComponent<MyTransform>();
			Vector2 pos = tr->GetPosition();
			pos.y -= 100.0f * MyTime::DeltaTime();
			tr->SetPos(pos);
		}

		if (MyInput::GetKey(eKeyCode::Down))
		{
			MyTransform* tr = GetOwner()->GetComponent<MyTransform>();
			Vector2 pos = tr->GetPosition();
			pos.y += 100.0f * MyTime::DeltaTime();
			tr->SetPos(pos);
		}*/
	}

	void MyPlayerScript::LateUpdate()
	{

	}

	void MyPlayerScript::Render(HDC hdc)
	{

	}

	void MyPlayerScript::sitDown()
	{
		if (MyInput::GetKey(eKeyCode::Right))
		{
			mState = MyPlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"RightWalk", true);
		}
		if (MyInput::GetKey(eKeyCode::Left))
		{
			mState = MyPlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"LeftWalk", true);
		}
		if (MyInput::GetKey(eKeyCode::Up))
		{
			mState = MyPlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"UpWalk", true);
		}
		if (MyInput::GetKey(eKeyCode::Down))
		{
			mState = MyPlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"DownWalk", true);
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
			mState = MyPlayerScript::eState::SitDown;
			mAnimator->PlayAnimation(L"SitDown", false);
		}
	}
}

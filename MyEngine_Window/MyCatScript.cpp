#include "MyCatScript.h"
#include "MyInput.h"
#include "MyTransform.h"
#include "MyTime.h"
#include "MyGameObject.h"
#include "MyAnimator.h"
#include "MyObject.h"

namespace my
{
	MyCatScript::MyCatScript()
		: mState(eState::SitDown)
		, mAnimator(nullptr)
		, mTime(0.0f)
		, mDirection(eDirection::End)
		, mDeathTime(0.0f)
		, mDest(Vector2::Zero)
		, mRadian(0.0f)
	{

	}

	MyCatScript::~MyCatScript()
	{

	}

	void MyCatScript::Initialize()
	{

	}

	void MyCatScript::Update()
	{
		mDeathTime += MyTime::DeltaTime();
		if (mDeathTime > 6.0f)
		{
			object::Destroy(GetOwner());
		}

		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<MyAnimator>();

		switch (mState)
		{
		case my::MyCatScript::eState::SitDown:
			sitDown();
			break;

		case my::MyCatScript::eState::Walk:
			move();
			break;

		case my::MyCatScript::eState::Sleep:
			break;

		case my::MyCatScript::eState::LayDown:
			break;

		case my::MyCatScript::eState::Attack:
			break;

		default:
			break;
		}
	}

	void MyCatScript::LateUpdate()
	{

	}

	void MyCatScript::Render(HDC hdc)
	{

	}

	void MyCatScript::sitDown()
	{

		mTime += MyTime::DeltaTime();

		// 벡터 활용 테스트 코드
		/*MyTransform* tr = GetOwner()->GetComponent<MyTransform>();
		Vector2 pos = tr->GetPosition();*/

		// 마우스 위치 이동 (벡터의 뺏셈 활용)
		/*MyTransform* plTr = mPlayer->GetComponent<MyTransform>();
		Vector2 dest = mDest - plTr->GetPosition();
		pos += dest.normalize() * (100.0f * MyTime::DeltaTime());*/

		// 삼각함수를 통한 이동
		/*mRadian += 5.0f * MyTime::DeltaTime();
		pos += Vector2(1.0f, 2.0f * cosf(mRadian)) * (100.0f * MyTime::DeltaTime());*/

		// 마우스 위치 이동 (벡터의 뺏셈 활용)
		//MyTransform* plTr = mPlayer->GetComponent<MyTransform>();
		//Vector2 dest = mDest - plTr->GetPosition();
		//dest.normalize();

		//float rotDegree = Vector2::Dot(dest, Vector2::Right);	// cos세타
		//rotDegree = acosf(rotDegree);

		//ConvertDegree(rotDegree);

		//pos += dest * (100.0f * MyTime::DeltaTime());

		//tr->SetPos(pos);

		/*if (mTime > 3.0f)
		{
			mState = MyCatScript::eState::Walk;
			int direction = (rand() % 4);
			mDirection = (MyCatScript::eDirection)direction;
			PlayWalkAnimationByDirection(mDirection);
			mTime = 0;
		}*/
	}

	void MyCatScript::move()
	{
		mTime += MyTime::DeltaTime();

		if (mTime > 2.0f)
		{
			int isLayDown = rand() % 2;
			if (isLayDown)
			{
				mState = MyCatScript::eState::LayDown;
				mAnimator->PlayAnimation(L"LayDown", false);
			}
			else
			{
				mState = MyCatScript::eState::SitDown;
				mAnimator->PlayAnimation(L"SitDown", false);
			}
		}

		MyTransform* tr = GetOwner()->GetComponent<MyTransform>();
		Vector2 pos = tr->GetPosition();

		translate(tr);
	}

	void MyCatScript::layDown()
	{

	}

	void MyCatScript::PlayWalkAnimationByDirection(eDirection direction)
	{
		switch (direction)
		{
		case my::MyCatScript::eDirection::Left:
			mAnimator->PlayAnimation(L"LeftWalk", true);
			break;

		case my::MyCatScript::eDirection::Right:
			mAnimator->PlayAnimation(L"RightWalk", true);
			break;

		case my::MyCatScript::eDirection::Down:
			mAnimator->PlayAnimation(L"DownWalk", true);
			break;

		case my::MyCatScript::eDirection::Up:
			mAnimator->PlayAnimation(L"UpWalk", true);
			break;

		case my::MyCatScript::eDirection::End:
			break;

		default:
			assert(false);
			break;
		}
	}

	void MyCatScript::translate(MyTransform* tr)
	{
		Vector2 pos = tr->GetPosition();

		switch (mDirection)
		{
		case MyCatScript::eDirection::Left:
			pos.x -= 100.0f * MyTime::DeltaTime();
			break;

		case MyCatScript::eDirection::Right:
			pos.x += 100.0f * MyTime::DeltaTime();
			break;

		case MyCatScript::eDirection::Down:
			pos.y += 100.0f * MyTime::DeltaTime();
			break;

		case MyCatScript::eDirection::Up:
			pos.y -= 100.0f * MyTime::DeltaTime();
			break;

		case MyCatScript::eDirection::End:
			break;

		default:
			assert(false);
			break;
		}

		tr->SetPos(pos);
	}
}
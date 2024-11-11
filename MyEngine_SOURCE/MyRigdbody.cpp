#include "MyRigdbody.h"
#include "MyTime.h"
#include "MyTransform.h"
#include "MyGameObject.h"

namespace my
{
	MyRigdbody::MyRigdbody()
		: MyComponent(enums::eComponentType::Rigidbody)
		, mbGround(false)
		, mMass(1.0f)
		, mFriction(10.0f)
		, mForce(Vector2::Zero)
		, mVelocity(Vector2::Zero)
		, mLimitedVelocity(Vector2(200.0f, 1000.0f))
		, mGravity(Vector2(0.0f, 800.0f))
		, mAccelation(Vector2::Zero)
	{

	}

	MyRigdbody::~MyRigdbody()
	{

	}

	void MyRigdbody::Initialize()
	{

	}

	void MyRigdbody::Update()
	{
		// f(힘) = m(질량) * a(가속도)
		// a = f / m;
		
		mAccelation = mForce / mMass;

		// 속도에 가속도를 더한다
		mVelocity += mAccelation * MyTime::DeltaTime();

		if (mbGround)
		{
			//땅위에 있을때
			Vector2 gravity = mGravity;
			gravity.normalize();

			float dot = Vector2::Dot(mVelocity, gravity);
			mVelocity -= gravity * dot;
		}
		else
		{
			//공중에 있을때
			mVelocity += mGravity * MyTime::DeltaTime();
		}

		// 최대 속도 제한
		Vector2 gravity = mGravity;
		gravity.normalize();
		float dot = Vector2::Dot(mVelocity, gravity);
		gravity = gravity * dot;

		Vector2 sideVelocity = mVelocity - gravity;

		if (mLimitedVelocity.y < gravity.length())
		{
			gravity.normalize();
			gravity *= mLimitedVelocity.y;
		}

		if (mLimitedVelocity.x < sideVelocity.length())
		{
			sideVelocity.normalize();
			sideVelocity *= mLimitedVelocity.x;
		}

		mVelocity = gravity + sideVelocity;

		if (!(mVelocity == Vector2::Zero))
		{
			// 속도에 반대방향으로 마찰력 적용
			Vector2 friction = -mVelocity;
			friction = friction.normalize() * mFriction * mMass * MyTime::DeltaTime();

			//마찰력으로 인한 속도 감소량이 현재 속도보다 큰 경우
			if (mVelocity.length() <= friction.length())
			{
				//멈춰
				mVelocity = Vector2::Zero;
			}
			else
			{
				mVelocity += friction;
			}
		}

		MyTransform* tr = GetOwner()->GetComponent<MyTransform>();
		Vector2 pos = tr->GetPosition();
		pos = pos + mVelocity * MyTime::DeltaTime();
		tr->SetPos(pos);

		mForce.clear();
	}

	void MyRigdbody::LateUpdate()
	{

	}

	void MyRigdbody::Render(HDC hdc)
	{

	}
}

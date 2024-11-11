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
		// f(��) = m(����) * a(���ӵ�)
		// a = f / m;
		
		mAccelation = mForce / mMass;

		// �ӵ��� ���ӵ��� ���Ѵ�
		mVelocity += mAccelation * MyTime::DeltaTime();

		if (mbGround)
		{
			//������ ������
			Vector2 gravity = mGravity;
			gravity.normalize();

			float dot = Vector2::Dot(mVelocity, gravity);
			mVelocity -= gravity * dot;
		}
		else
		{
			//���߿� ������
			mVelocity += mGravity * MyTime::DeltaTime();
		}

		// �ִ� �ӵ� ����
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
			// �ӵ��� �ݴ�������� ������ ����
			Vector2 friction = -mVelocity;
			friction = friction.normalize() * mFriction * mMass * MyTime::DeltaTime();

			//���������� ���� �ӵ� ���ҷ��� ���� �ӵ����� ū ���
			if (mVelocity.length() <= friction.length())
			{
				//����
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

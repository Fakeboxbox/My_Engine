#include "MyCamera.h"
#include "MyGameObject.h"
#include "MyTransform.h"
#include "MyApplication.h"

extern my::MyApplication application;

namespace my
{
	MyCamera::MyCamera()
		: MyComponent(enums::eComponentType::Camera)
		, mTarget(nullptr)
		, mDistance(Vector2::Zero)
		, mResolution(Vector2::Zero)
		, mLookPosition(Vector2::Zero)
	{

	}

	MyCamera::~MyCamera()
	{

	}

	void MyCamera::Initialize()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
	}

	void MyCamera::Update()
	{
		if (mTarget)
		{
			MyTransform* tr = mTarget->GetComponent<MyTransform>();
			mLookPosition = tr->GetPosition();
		}
		else
		{
			MyTransform* cameraTr = GetOwner()->GetComponent<MyTransform>();
			mLookPosition = cameraTr->GetPosition();
		}

		mDistance = mLookPosition - (mResolution / 2.0f);
	}

	void MyCamera::LateUpdate()
	{

	}

	void MyCamera::Render(HDC hdc)
	{

	}
}
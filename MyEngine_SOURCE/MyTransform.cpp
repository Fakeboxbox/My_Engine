#include "MyTransform.h"

namespace my
{
	MyTransform::MyTransform()
		: MyComponent(enums::eComponentType::Transform)
		, mPosition(Vector2::Zero)
		, mScale(Vector2::One)
		, mRotation(0.0f)
	{

	}

	MyTransform::~MyTransform()
	{

	}

	void MyTransform::Initialize()
	{

	}

	void MyTransform::Update()
	{

	}

	void MyTransform::LateUpdate()
	{

	}

	void MyTransform::Render(HDC hdc)
	{

	}
}
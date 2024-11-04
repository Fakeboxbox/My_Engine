#include "MyGameObject.h"
#include "MyInput.h"
#include "MyTime.h"

namespace my
{
	MyGameObject::MyGameObject()
		: mX(0)
		, mY(0)
	{

	}

	MyGameObject::~MyGameObject()
	{

	}

	void MyGameObject::Update()
	{
		const int speed = 100.0f;

		if (MyInput::GetKey(eKeyCode::A))
		{
			mX -= speed * MyTime::DeltaTime();
		}

		if (MyInput::GetKey(eKeyCode::D))
		{
			mX += speed * MyTime::DeltaTime();
		}

		if (MyInput::GetKey(eKeyCode::W))
		{
			mY -= speed * MyTime::DeltaTime();
		}

		if (MyInput::GetKey(eKeyCode::S))
		{
			mY += speed * MyTime::DeltaTime();
		}
	}

	void MyGameObject::LateUpdate()
	{

	}

	void MyGameObject::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		HPEN redpen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
		HPEN oldpen = (HPEN)SelectObject(hdc, redpen);
		SelectObject(hdc, oldpen);

		Ellipse(hdc, mX, mY, 100 + mX, 100 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(brush);
		DeleteObject(redpen);
	}
}
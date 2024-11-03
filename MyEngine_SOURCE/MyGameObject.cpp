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
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
			HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

			HPEN redpen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
			HPEN oldpen = (HPEN)SelectObject(hdc, redpen);
			SelectObject(hdc, oldpen);

			Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

			SelectObject(hdc, oldBrush);
			DeleteObject(brush);
			DeleteObject(redpen);
	}
}
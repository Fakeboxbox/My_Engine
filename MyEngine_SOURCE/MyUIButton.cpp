#include "MyUIButton.h"
#include "MyInput.h"

namespace my
{
	MyUIButton::MyUIButton()
		: MyUIBase(eUIType::Button)
		, mTexture(nullptr)
	{

	}

	MyUIButton::~MyUIButton()
	{

	}

	void MyUIButton::OnInit()
	{
		SetPos(Vector2(200.0f, 200.0f));
		SetSize(Vector2(200.0f, 200.0f));

		mOnclik = std::bind(&MyUIButton::ButtonClick, this);
	}

	void MyUIButton::OnActive()
	{

	}

	void MyUIButton::OnInActive()
	{

	}

	void MyUIButton::OnUpdate()
	{
		Vector2 mousePos = MyInput::GetMousePosition();

		if (mPosition.x <= mousePos.x && mousePos.x <= mPosition.x + mSize.x
			&& mPosition.y <= mousePos.y && mousePos.y <= mPosition.y + mSize.y)
		{
			mbMouseOn = true;
		}
		else
		{
			mbMouseOn = false;
		}

		if (MyInput::GetKeyDown(eKeyCode::LButton))
		{
			if (mbMouseOn)
			{
				mOnclik();
			}
		}
	}

	void MyUIButton::OnLateUpdate()
	{

	}

	void MyUIButton::OnRender(HDC hdc)
	{
		Rectangle(hdc
			, (int)mPosition.x, (int)mPosition.y
			, mPosition.x + mSize.x, mPosition.y + mSize.y);
	}

	void MyUIButton::OnClear()
	{

	}

	void MyUIButton::ButtonClick()
	{

	}
}
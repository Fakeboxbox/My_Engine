#include "MyInput.h"

namespace my
{
	std::vector<MyInput::Key> MyInput::Keys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z',
		'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP
	};

	void MyInput::Initialize()
	{
		CreateKeys();
	}

	void MyInput::Update()
	{
		UpdateKeys();
	}

	void MyInput::CreateKeys()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; ++i)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			Keys.push_back(key);
		}
	}

	void MyInput::UpdateKeys()
	{
		std::for_each(Keys.begin(), Keys.end(),
			[](Key& key) -> void
			{
				UpdateKey(key);
			});
	}

	void MyInput::UpdateKey(MyInput::Key& key)
	{
		if (IsKeyDown(key.keyCode))
		{
			UpdateKeyDown(key);
		}
		else
		{
			UpdateKeyUp(key);
		}
	}

	bool MyInput::IsKeyDown(eKeyCode keycode)
	{
		return GetAsyncKeyState(ASCII[(UINT)keycode]) & 0x8000;
	}

	void MyInput::UpdateKeyDown(MyInput::Key& key)
	{
		if (key.bPressed == true)
		{
			key.state = eKeyState::Pressed;
		}
		else
		{
			key.state = eKeyState::Down;
		}

		key.bPressed = true;
	}

	void MyInput::UpdateKeyUp(MyInput::Key& key)
	{
		if (key.bPressed == true)
		{
			key.state = eKeyState::Up;
		}
		else
		{
			key.state = eKeyState::None;
		}

		key.bPressed = false;
	}
}
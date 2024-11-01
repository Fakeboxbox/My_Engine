#include "MyInput.h"

namespace my
{
	std::vector<MyInput::Key> MyInput::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z',
		'X', 'C', 'V', 'B', 'N', 'M'
	};

	void MyInput::Initialize()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; ++i)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}

	void MyInput::Update()
	{
		for (size_t i = 0; i < mKeys.size(); ++i)
		{
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].bPressed == true)
				{
					mKeys[i].state = eKeyState::Pressed;
				}
				else
				{
					mKeys[i].state = eKeyState::Down;
				}

				mKeys[i].bPressed = true;
			}
			else
			{
				if (mKeys[i].bPressed == true)
				{
					mKeys[i].state = eKeyState::Up;
				}
				else
				{
					mKeys[i].state = eKeyState::None;
				}

				mKeys[i].bPressed = false;
			}
		}
	}
}
#pragma once
#include "CommonInclude.h"

namespace my
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None
	};

	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L, Z,
		X, C, V, B, N, M, 
		Left, Right, Down, Up,
		LButton, MButton, RButton,
		End
	};

	class MyInput
	{
	public:	
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};

		static void Initialize();
		static void Update();

		__forceinline static bool GetKey(eKeyCode keycode) { return Keys[(UINT)keycode].state == eKeyState::Pressed; }
		__forceinline static bool GetKeyDown(eKeyCode keycode) { return Keys[(UINT)keycode].state == eKeyState::Down; }
		__forceinline static bool GetKeyUp(eKeyCode keycode) { return Keys[(UINT)keycode].state == eKeyState::Up; }
		__forceinline static math::Vector2 GetMousePosition() { return mMousePositon; }

	private:
		static void CreateKeys();
		static void UpdateKeys();
		static void UpdateKey(MyInput::Key& key);
		static bool IsKeyDown(eKeyCode keycode);
		static void UpdateKeyDown(MyInput::Key& key);
		static void UpdateKeyUp(MyInput::Key& key);
		static void GetMousePostionByWindow();
		static void ClearKeys();

	private:
		static std::vector<Key> Keys;
		static math::Vector2 mMousePositon;
	};
}


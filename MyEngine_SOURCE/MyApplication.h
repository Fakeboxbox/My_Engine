#pragma once
#include "MyGameObject.h"

namespace my
{
	class MyApplication
	{
	public:
		MyApplication();
		~MyApplication();

		void Initialize(HWND hwnd);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		float mSpeed;

		MyGameObject mPlayer;
	};
}
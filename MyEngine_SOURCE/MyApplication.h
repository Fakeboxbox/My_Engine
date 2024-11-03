#pragma once
#include "MyGameObject.h"

namespace my
{
	class MyApplication
	{
	public:
		MyApplication();
		~MyApplication();
		
		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		float mSpeed;

		MyGameObject mPlayer;
	};
}
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
		void ClearRenderTarget();
		void CopyRenderTarget(HDC sorce, HDC dest);
		void AdjustWindowCustomRect(HWND hwnd, UINT width, UINT height);
		void CreateBuffer(UINT width, UINT height);
		void InitializeEtc();

		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;
	};
}
#include "MyApplication.h"
#include "MyInput.h"
#include "MyTime.h"

namespace my
{
	MyApplication::MyApplication()	
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mSpeed(0.0f)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBitmap(NULL)
	{

	}

	MyApplication::~MyApplication()
	{

	}

	void MyApplication::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		
		RECT rect = {0, 0, width, height};
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);

		//윈도우 해상도에 맞는 백버퍼(도화지) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		//백버퍼를 가르킬 DC생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);

		mPlayer.SetPosition(0, 0);

		MyInput::Initialize();
		MyTime::Initialize();
	}

	void MyApplication::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void MyApplication::Update()
	{
		MyInput::Update();
		MyTime::Update();
		mPlayer.Update();
	}

	void MyApplication::LateUpdate()
	{
		mPlayer.LateUpdate();
	}

	void MyApplication::Render()
	{
		Rectangle(mBackHdc, 0, 0, 1600, 900);

		MyTime::Render(mBackHdc);
		mPlayer.Render(mBackHdc);

		// BackBuffer에 있는것을 원본 Buffer에 복사(그려준다)
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}
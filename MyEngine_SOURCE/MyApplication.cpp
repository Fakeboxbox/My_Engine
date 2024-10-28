#include "MyApplication.h"

namespace my
{
	MyApplication::MyApplication()	
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mSpeed(0.0f)
	{

	}

	MyApplication::~MyApplication()
	{

	}

	void MyApplication::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		mPlayer.SetPosition(0, 0);
	}

	void MyApplication::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void MyApplication::Update()
	{
		mPlayer.Update();
	}

	void MyApplication::LateUpdate()
	{
		mPlayer.LateUpdate();
	}

	void MyApplication::Render()
	{
		mPlayer.Render(mHdc);
	}
}
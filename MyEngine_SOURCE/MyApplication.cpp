#include "MyApplication.h"
#include "MyInput.h"
#include "MyTime.h"
#include "MySceneManager.h"

namespace my
{
	MyApplication::MyApplication()	
		: mHwnd(nullptr)
		, mHdc(nullptr)
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
		AdjustWindowCustomRect(hwnd, width, height);
		CreateBuffer(width, height);
		InitializeEtc();

		MySceneManager::Initialize();
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

		MySceneManager::Update();
	}

	void MyApplication::LateUpdate()
	{
		MySceneManager::LateUpdate();
	}

	void MyApplication::Render()
	{
		ClearRenderTarget();

		MyTime::Render(mBackHdc);
		MySceneManager::Render(mBackHdc);

		CopyRenderTarget(mBackHdc, mHdc);
	}

	void MyApplication::ClearRenderTarget()
	{
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}

	void MyApplication::CopyRenderTarget(HDC sorce, HDC dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHeight, sorce, 0, 0, SRCCOPY);
	}

	void MyApplication::AdjustWindowCustomRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);
	}

	void MyApplication::CreateBuffer(UINT width, UINT height)
	{
		//윈도우 해상도에 맞는 백버퍼(도화지) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		//백버퍼를 가르킬 DC생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}

	void MyApplication::InitializeEtc()
	{
		MyInput::Initialize();
		MyTime::Initialize();
	}
}
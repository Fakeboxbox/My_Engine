#include "MyApplication.h"
#include "MyInput.h"
#include "MyTime.h"
#include "MySceneManager.h"
#include "MyResources.h"
#include "MyColliderManager.h"
#include "MyUIManager.h"

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

		MyColliderManager::Initialize();
		MyUIManager::Initialize();
		MySceneManager::Initialize();
	}

	void MyApplication::Run()
	{
		Update();
		LateUpdate();
		Render();
		Destory();
	}

	void MyApplication::Update()
	{
		MyInput::Update();
		MyTime::Update();

		MyColliderManager::Update();
		MyUIManager::Update();
		MySceneManager::Update();
	}

	void MyApplication::LateUpdate()
	{
		MyColliderManager::LateUpdate();
		MyUIManager::LateUpdate();
		MySceneManager::LateUpdate();
	}

	void MyApplication::Render()
	{
		ClearRenderTarget();

		MyTime::Render(mBackHdc);

		MyColliderManager::Render(mBackHdc);
		MyUIManager::Render(mBackHdc);
		MySceneManager::Render(mBackHdc);

		CopyRenderTarget(mBackHdc, mHdc);
	}

	void MyApplication::Destory()
	{
		MySceneManager::Destroy();
	}

	void MyApplication::Release()
	{
		MySceneManager::Release();
		MyUIManager::Release();
		MyResources::Release();
	}

	void MyApplication::ClearRenderTarget()
	{
		HBRUSH grayBrush = (HBRUSH)CreateSolidBrush(RGB(128, 128, 128));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHdc, grayBrush);

		Rectangle(mBackHdc, -1, -1, 1601, 901);

		(HBRUSH)SelectObject(mBackHdc, oldBrush);
		DeleteObject(grayBrush);
	}

	void MyApplication::CopyRenderTarget(HDC sorce, HDC dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHeight, sorce, 0, 0, SRCCOPY);
	}

	void MyApplication::AdjustWindowCustomRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, (LONG)width, (LONG)height };
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
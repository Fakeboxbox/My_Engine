#include "MyTexture.h"
#include "MyApplication.h"
#include "MyResources.h"

extern my::MyApplication application;	// extern: 해당 전역변수가 존재함을 알리는 키워드

namespace my::graphics
{
	MyTexture* MyTexture::Create(const std::wstring& name, UINT width, UINT height)
	{
		MyTexture* image = MyResources::Find<MyTexture>(name);
		if (image)
			return image;

		image = new MyTexture();
		image->SetName(name);
		image->SetWidth(width);
		image->SetHeight(height);

		HDC hdc = application.GetHdc();
		HWND hwnd = application.GetHwnd();

		image->mBitmap = CreateCompatibleBitmap(hdc, width, height);
		image->mHdc = CreateCompatibleDC(hdc);

		// 뒷배경에 흰색이아닌 투명색으로 칠해주는 코드 -> mushroom은 이미지 자체에 흰색 배경이므로 적용 x
		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);
		Rectangle(image->mHdc
			, -1
			, -1
			, image->GetWidth() + 1
			, image->GetHeight() + 1);
		(HBRUSH)SelectObject(image->mHdc, oldBrush);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(image->mHdc, image->mBitmap);
		DeleteObject(oldBitmap);

		MyResources::Insert(name, image);

		return image;
	}

	MyTexture::MyTexture()
		: MyResource(enums::eResourceType::Texture)
		, mbAlpha(false)
	{

	}

	MyTexture::~MyTexture()
	{

	}

	HRESULT MyTexture::Load(const std::wstring& path)
	{
		std::wstring ext = path.substr(path.find_last_of(L".") + 1);

		if (ext == L"bmp")
		{
			mType = eTextureType::Bmp;
			mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP
				, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			if (mBitmap == nullptr)
				return S_FALSE;

			BITMAP info = {};
			GetObject(mBitmap, sizeof(BITMAP), &info);

			mWidth = info.bmWidth;
			mHeight = info.bmHeight;

			if (info.bmBitsPixel == 32)
				mbAlpha = true;
			if (info.bmBitsPixel == 24)
				mbAlpha = false;

			HDC mainDC = application.GetHdc();
			mHdc = CreateCompatibleDC(mainDC);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
			DeleteObject(oldBitmap);
		}
		else if (ext == L"png")
		{
			mType = eTextureType::Png;
			mImage = Gdiplus::Image::FromFile(path.c_str());

			if (mImage == nullptr)
				return S_FALSE;

			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();
		}

		return S_OK;
	}
}

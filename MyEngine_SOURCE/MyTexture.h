#pragma once
#include "MyResource.h"

namespace my::graphcis
{
	class MyTexture : public MyResource
	{
	public:
		enum class eTextureType
		{
			Bmp,
			Png,
			None
		};

		MyTexture();
		~MyTexture();

		virtual HRESULT Load(const std::wstring& path) override;

		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
		HDC GetHdc() { return mHdc; }
		eTextureType GetTextureType() { return mType; }
		Gdiplus::Image* GetImage() { return mImage; }
		

	private:
		Gdiplus::Image* mImage;
		HBITMAP mBitmap;
		HDC mHdc;

		eTextureType mType;
		UINT mWidth;
		UINT mHeight;
	};
}



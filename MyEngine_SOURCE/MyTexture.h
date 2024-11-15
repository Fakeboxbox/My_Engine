#pragma once
#include "MyResource.h"

namespace my::graphics
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

		static MyTexture* Create(const std::wstring& name, UINT width, UINT height);

		MyTexture();
		~MyTexture();

		virtual HRESULT Load(const std::wstring& path) override;

		COLORREF GetPixel(int x, int y);

		UINT GetWidth() { return mWidth; }
		void SetWidth(UINT width) { mWidth = width; }
		UINT GetHeight() { return mHeight; }
		void SetHeight(UINT height) { mHeight = height; }
		HDC GetHdc() { return mHdc; }
		eTextureType GetTextureType() { return mType; }
		Gdiplus::Image* GetImage() { return mImage; }
		bool IsAlpha() { return mbAlpha; }
		

	private:
		bool mbAlpha;
		Gdiplus::Image* mImage;
		HBITMAP mBitmap;
		HDC mHdc;

		eTextureType mType;
		UINT mWidth;
		UINT mHeight;
	};
}



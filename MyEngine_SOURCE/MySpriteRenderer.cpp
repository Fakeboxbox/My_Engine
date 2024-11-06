#include "MySpriteRenderer.h"
#include "MyGameObject.h"
#include "MyTransform.h"
#include "MyTexture.h"

namespace my
{
	MySpriteRenderer::MySpriteRenderer()
		: MyComponent()
		, mTexture(nullptr)
		, mSize(Vector2::One)
	{

	}

	MySpriteRenderer::~MySpriteRenderer()
	{

	}

	void MySpriteRenderer::Initialize()
	{

	}

	void MySpriteRenderer::Update()
	{

	}

	void MySpriteRenderer::LateUpdate()
	{

	}

	void MySpriteRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr) // 텍스처 세팅 해주세요!
			assert(false);

		MyTransform* tr = GetOwner()->GetComponent<MyTransform>();
		Vector2 pos = tr->GetPosition();

		if (mTexture->GetTextureType() == graphcis::MyTexture::eTextureType::Bmp)
		{
			TransparentBlt(hdc, pos.x, pos.y
				, mTexture->GetWidth(), mTexture->GetHeight()
				, mTexture->GetHDC(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
				, RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType() == graphcis::MyTexture::eTextureType::Png)
		{
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage(), 
				Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth(), mTexture->GetHeight()));
		}
	}
}
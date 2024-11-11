#include "MySpriteRenderer.h"
#include "MyGameObject.h"
#include "MyTransform.h"
#include "MyTexture.h"
#include "MyRenderer.h"

namespace my
{
	MySpriteRenderer::MySpriteRenderer()
		: MyComponent(enums::eComponentType::SpriteRenderer)
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
		float rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();

		pos = renderer::mainCamera->CalculatePosition(pos);

		if (mTexture->GetTextureType() == graphics::MyTexture::eTextureType::Bmp)
		{
			if (mTexture->IsAlpha())	// 알파채널이 있다면 
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255;	// 0(transparent) ~ 255(opaque)

				AlphaBlend(hdc
					, pos.x
					, pos.y
					, mTexture->GetWidth() * mSize.x * scale.x
					, mTexture->GetHeight() * mSize.y * scale.y
					, mTexture->GetHdc()
					, 0, 0
					, mTexture->GetWidth()
					, mTexture->GetHeight()
					, func);
			}
			else
			{
				TransparentBlt(hdc
					, pos.x
					, pos.y
					, mTexture->GetWidth() * mSize.x * scale.x
					, mTexture->GetHeight() * mSize.y * scale.y
					, mTexture->GetHdc()
					, 0, 0
					, mTexture->GetWidth()
					, mTexture->GetHeight()
					, RGB(255, 0, 255));
			}
		}
		else if (mTexture->GetTextureType() == graphics::MyTexture::eTextureType::Png)
		{
			// 투명화시킬 픽셀의 색 범위
			Gdiplus::ImageAttributes imgAtt = {};
			imgAtt.SetColorKey(Gdiplus::Color(100, 100, 100), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(mTexture->GetImage(), 
				Gdiplus::Rect
				(
					pos.x, pos.y
					, mTexture->GetWidth() * mSize.x * scale.x
					, mTexture->GetHeight() * mSize.y * scale.y
				)
				, 0 , 0
				, mTexture->GetWidth(), mTexture->GetHeight()
				, Gdiplus::UnitPixel
				, nullptr);
		}
	}
}
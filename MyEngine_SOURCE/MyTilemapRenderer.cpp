#include "MyTilemapRenderer.h"
#include "MyGameObject.h"
#include "MyTransform.h"
#include "MyTexture.h"
#include "MyRenderer.h"

namespace my
{
	MyTilemapRenderer::MyTilemapRenderer()
		: MyComponent(enums::eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mSize(Vector2(3.0f, 3.0f))
		, mIndex(Vector2::Zero)
		, mTileSize(Vector2(16.0f, 16.0f))
	{

	}

	MyTilemapRenderer::~MyTilemapRenderer()
	{

	}

	void MyTilemapRenderer::Initialize()
	{

	}

	void MyTilemapRenderer::Update()
	{

	}

	void MyTilemapRenderer::LateUpdate()
	{

	}

	void MyTilemapRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr) // �ؽ�ó ���� ���ּ���!
			assert(false);

		MyTransform* tr = GetOwner()->GetComponent<MyTransform>();
		Vector2 pos = tr->GetPosition();
		float rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();

		pos = renderer::mainCamera->CalculatePosition(pos);

		if (mTexture->GetTextureType() == graphics::MyTexture::eTextureType::Bmp)
		{
			if (mTexture->IsAlpha())	// ����ä���� �ִٸ� 
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
					, mIndex.x * mTileSize.x * mSize.x * scale.x
					, mIndex.y * mTileSize.y * mSize.y * scale.y
					, mTexture->GetHdc()
					, mIndex.x * mTileSize.x, mIndex.y * mTileSize.y
					, mTileSize.x
					, mTileSize.y
					, RGB(255, 0, 255));
			}
		}
		//else if (mTexture->GetTextureType() == graphics::MyTexture::eTextureType::Png)
		//{
		//	// ����ȭ��ų �ȼ��� �� ����
		//	Gdiplus::ImageAttributes imgAtt = {};
		//	imgAtt.SetColorKey(Gdiplus::Color(100, 100, 100), Gdiplus::Color(255, 255, 255));

		//	Gdiplus::Graphics graphics(hdc);

		//	graphics.TranslateTransform(pos.x, pos.y);
		//	graphics.RotateTransform(rot);
		//	graphics.TranslateTransform(-pos.x, -pos.y);

		//	graphics.DrawImage(mTexture->GetImage(),
		//		Gdiplus::Rect
		//		(
		//			pos.x, pos.y
		//			, mTexture->GetWidth() * mSize.x * scale.x
		//			, mTexture->GetHeight() * mSize.y * scale.y
		//		)
		//		, 0, 0
		//		, mTexture->GetWidth(), mTexture->GetHeight()
		//		, Gdiplus::UnitPixel
		//		, nullptr);
		//}
	}
}
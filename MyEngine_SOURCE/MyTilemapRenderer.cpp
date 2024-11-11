#include "MyTilemapRenderer.h"
#include "MyGameObject.h"
#include "MyTransform.h"
#include "MyTexture.h"
#include "MyRenderer.h"

namespace my
{
	Vector2 MyTilemapRenderer::TileSize = Vector2::One;

	MyTilemapRenderer::MyTilemapRenderer()
		: MyComponent(enums::eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mSize(Vector2(3.0f, 3.0f))
		, mIndex(Vector2::Zero)
		, mTileSize(Vector2(16.0f, 16.0f))
	{
		TileSize = mTileSize * mSize;
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
					, mTileSize.x * mSize.x * scale.x
					, mTileSize.y * mSize.y * scale.y
					, mTexture->GetHdc()
					, mIndex.x * mTileSize.x, mIndex.y * mTileSize.y
					, mTileSize.x
					, mTileSize.y
					, RGB(255, 0, 255));
			}
		}
	}
}
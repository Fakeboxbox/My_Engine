#include "MyAnimation.h"
#include "MyTime.h"
#include "MyTransform.h"
#include "MyGameObject.h"
#include "MyAnimator.h"
#include "MyRenderer.h"
#include "MyCamera.h"

namespace my
{
	MyAnimation::MyAnimation()
		: MyResource(enums::eResourceType::Animation)
		, mAnimator(nullptr)
		, mTexture(nullptr)
		, mAnimationSheet{}
		, mIndex(-1)
		, mTime(0.0f)
		, mbComplete(false)
	{

	}

	MyAnimation::~MyAnimation()
	{

	}

	HRESULT MyAnimation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	void MyAnimation::Update()
	{
		if (mbComplete)
			return;

		mTime += MyTime::DeltaTime();

		if (mAnimationSheet[mIndex].duration < mTime)
		{
			mTime = 0.0f;

			if (mIndex < mAnimationSheet.size() - 1)
				mIndex++;
			else
				mbComplete = true;
		}
	}

	void MyAnimation::Render(HDC hdc)
	{
		// 알파블렌드를 쓸 수 있는 조건 : 해당 이미지에 알파채널이 있어야한다.

		if (mTexture == nullptr)
			return;

		MyGameObject* gameObj = mAnimator->GetOwner();
		MyTransform* tr = gameObj->GetComponent<MyTransform>();
		Vector2 pos = tr->GetPosition();
		float rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePosition(pos);

		graphcis::MyTexture::eTextureType type = mTexture->GetTextureType();
		Sprite sprite = mAnimationSheet[mIndex];

		if (type == graphcis::MyTexture::eTextureType::Bmp)
		{
			HDC imgHdc = mTexture->GetHdc();

			if (mTexture->IsAlpha())	// 알파채널이 있다면 
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255;	// 0(transparent) ~ 255(opaque)

				AlphaBlend(hdc
					, pos.x - (sprite.size.x / 2.0f) + sprite.offset.x
					, pos.y - (sprite.size.y / 2.0f) + sprite.offset.y
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
					, imgHdc
					, (int)sprite.leftTop.x
					, (int)sprite.leftTop.y
					, (int)sprite.size.x
					, (int)sprite.size.y
					, func);
			}
			else	// 알파채널이 없다면 
			{
				TransparentBlt(hdc
					, pos.x - (sprite.size.x / 2.0f) + sprite.offset.x
					, pos.y - (sprite.size.y / 2.0f) + sprite.offset.y
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
					, imgHdc
					, (int)sprite.leftTop.x
					, (int)sprite.leftTop.y
					, (int)sprite.size.x
					, (int)sprite.size.y
					, RGB(255, 0, 255));
			}
		}
		else if (type == graphcis::MyTexture::eTextureType::Png)
		{
			Gdiplus::ImageAttributes imgAtt = {};
			imgAtt.SetColorKey(Gdiplus::Color(100, 100, 100), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(mTexture->GetImage()

				, Gdiplus::Rect
				(
					  pos.x - (sprite.size.x / 2.0f)
					, pos.y - (sprite.size.y / 2.0f)
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
				)
				, (int)sprite.leftTop.x
				, (int)sprite.leftTop.y
				, (int)sprite.size.x
				, (int)sprite.size.y
				, Gdiplus::UnitPixel
				, nullptr
			);
		}
	}

	void MyAnimation::CreateAnimation(const std::wstring& name, graphcis::MyTexture* spriteSheet
		, Vector2 leftTop, Vector2 size, Vector2 offset ,UINT spriteLegth, float duration)
	{
		mTexture = spriteSheet;

		for (size_t i = 0; i < spriteLegth; i++)
		{
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + (size.x * i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			mAnimationSheet.push_back(sprite);
		}
	}

	void MyAnimation::Reset()
	{
		mTime = 0.0f;
		mIndex = 0;
		mbComplete = false;
	}
}
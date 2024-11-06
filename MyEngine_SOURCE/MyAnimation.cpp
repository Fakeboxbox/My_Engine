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

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePosition(pos);

		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 125;	// 0(transparent) ~ 255(opaque)

		Sprite sprite = mAnimationSheet[mIndex];
		HDC imgHdc = mTexture->GetHdc();

		AlphaBlend(hdc
			, pos.x, pos.y
			, sprite.size.x * 5
			, sprite.size.y * 5
			, imgHdc
			, sprite.leftTop.x
			, sprite.leftTop.y
			, sprite.size.x
			, sprite.size.y
			, func);
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
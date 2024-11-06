#include "MyAnimator.h"

namespace my
{
	MyAnimator::MyAnimator()
		: MyComponent(enums::eComponentType::Animator)
		, mAnimations{}
		, mActiveAnimation(nullptr)
		, mbLoop(false)
	{

	}

	MyAnimator::~MyAnimator()
	{

	}

	void MyAnimator::Initialize()
	{

	}

	void MyAnimator::Update()
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Update();

			if (mActiveAnimation->IsComplete() == true 
				&& mbLoop == true)
			{
				mActiveAnimation->Reset();
			}
		}
	}

	void MyAnimator::LateUpdate()
	{

	}

	void MyAnimator::Render(HDC hdc)
	{
		if (mActiveAnimation)
			mActiveAnimation->Render(hdc);
	}

	void MyAnimator::CreateAnimation(const std::wstring& name
		, graphcis::MyTexture* spriteSheet
		, Vector2 leftTop
		, Vector2 size, Vector2 offset
		, UINT spriteLegth, float duration)
	{
		MyAnimation* animation = nullptr;
		animation = FindAnimation(name);
		if (animation != nullptr)
			return;

		animation = new MyAnimation();
		animation->CreateAnimation(name, spriteSheet,
			leftTop, size, offset, spriteLegth, duration);

		animation->SetAnimator(this);

		mAnimations.insert(std::make_pair(name, animation));
	}

	MyAnimation* MyAnimator::FindAnimation(const std::wstring& name)
	{
		auto iter = mAnimations.find(name);

		if(iter == mAnimations.end())
			return nullptr;

		return iter->second;
	}

	void MyAnimator::PlayAnimation(const std::wstring& name, bool loop)
	{
		MyAnimation* animation = FindAnimation(name);
		
		if (animation == nullptr)
			return;

		mActiveAnimation = animation;
		mActiveAnimation->Reset();
		mbLoop = loop;
	}
}
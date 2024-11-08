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
		for (auto& iter : mAnimations)
		{
			delete iter.second;
			iter.second = nullptr;
		}

		for (auto& iter : mEvents)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}

	void MyAnimator::Initialize()
	{

	}

	void MyAnimator::Update()
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Update();

			Events* events = FindEvents(mActiveAnimation->GetName());

			if (mActiveAnimation->IsComplete() == true)
			{
				if(events)
					events->completeEvent();

				if(mbLoop == true)
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
		animation->SetName(name);
		animation->CreateAnimation(name, spriteSheet,
			leftTop, size, offset, spriteLegth, duration);

		animation->SetAnimator(this);

		Events* events = new Events();
		mEvents.insert(std::make_pair(name, events));

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

		if (mActiveAnimation)
		{
			Events* currentEvents = FindEvents(mActiveAnimation->GetName());

			if (currentEvents)
				currentEvents->endEvent();
		}

		Events* nextEvents = FindEvents(animation->GetName());
		
		if (nextEvents)
			nextEvents->startEvent();

		mActiveAnimation = animation;
		mActiveAnimation->Reset();
		mbLoop = loop;
	}

	MyAnimator::Events* MyAnimator::FindEvents(const std::wstring& name)
	{
		auto iter = mEvents.find(name);

		if (iter == mEvents.end())
			return nullptr;

		return iter->second;
	}

	std::function<void()>& MyAnimator::GetStartEvent(const std::wstring& name)
	{
		// TODO: 여기에 return 문을 삽입합니다.
		Events* events = FindEvents(name);
		return events->startEvent.mEvent;
	}

	std::function<void()>& MyAnimator::GetCompleteEvent(const std::wstring& name)
	{
		// TODO: 여기에 return 문을 삽입합니다.
		Events* events = FindEvents(name);
		return events->completeEvent.mEvent;
	}

	std::function<void()>& MyAnimator::GetEndEvent(const std::wstring& name)
	{
		// TODO: 여기에 return 문을 삽입합니다.
		Events* events = FindEvents(name);
		return events->endEvent.mEvent;
	}
}
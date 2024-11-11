#include "MyAnimator.h"
#include "MyResources.h"
#include "MyTexture.h"

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
		, graphics::MyTexture* spriteSheet
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

	void MyAnimator::CreateAnimationByFolder(const std::wstring& name, const std::wstring& path, Vector2 offset, float duration)
	{
		MyAnimation* animation = nullptr;
		animation = FindAnimation(name);
		if (animation != nullptr)
			return;

		int fileCount = 0;
		std::filesystem::path fs(path);
		std::vector<graphics::MyTexture*> images = {};

		for ( auto& p : std::filesystem::recursive_directory_iterator(fs))
		{
			std::wstring fileName = p.path().filename();
			std::wstring fullName = p.path();

			graphics::MyTexture* texture = MyResources::Load<graphics::MyTexture>(fileName, fullName);
			images.push_back(texture);
			fileCount++;
		}
		UINT sheetWidth = images[0]->GetWidth() * fileCount;
		UINT sheetHeight = images[0]->GetHeight();
		graphics::MyTexture* spriteSheet = graphics::MyTexture::Create(name, sheetWidth, sheetHeight);

		UINT imageWidth = images[0]->GetWidth();
		UINT imageHeight = images[0]->GetHeight();

		for (size_t i = 0; i < images.size(); i++)
		{
			BitBlt(spriteSheet->GetHdc(), i * imageWidth, 0
				, imageWidth, imageHeight
				, images[i]->GetHdc(), 0, 0, SRCCOPY);
		}

		CreateAnimation(name, spriteSheet
			, Vector2(0.0f, 0.0f), Vector2(imageWidth, imageHeight)
			, offset, fileCount, duration);
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
		// TODO: ���⿡ return ���� �����մϴ�.
		Events* events = FindEvents(name);
		return events->startEvent.mEvent;
	}

	std::function<void()>& MyAnimator::GetCompleteEvent(const std::wstring& name)
	{
		// TODO: ���⿡ return ���� �����մϴ�.
		Events* events = FindEvents(name);
		return events->completeEvent.mEvent;
	}

	std::function<void()>& MyAnimator::GetEndEvent(const std::wstring& name)
	{
		// TODO: ���⿡ return ���� �����մϴ�.
		Events* events = FindEvents(name);
		return events->endEvent.mEvent;
	}
}
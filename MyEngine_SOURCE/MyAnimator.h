#pragma once
#include "MyComponent.h"
#include "MyAnimation.h"

namespace my
{
	class MyAnimator : public MyComponent
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}

			void operator()()
			{
				if (mEvent)
					mEvent();
			}

			std::function<void()> mEvent;
		};

		struct Events
		{
			Event startEvent;
			Event completeEvent;
			Event endEvent;
		};

		MyAnimator();
		~MyAnimator();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void CreateAnimation(const std::wstring& name
			, graphics::MyTexture* spriteSheet
			, Vector2 leftTop
			, Vector2 size
			, Vector2 offset
			, UINT spriteLegth
			, float duration);

		void CreateAnimationByFolder(const std::wstring& name, const std::wstring& path
			, Vector2 offset, float duration);

		MyAnimation* FindAnimation(const std::wstring& name);
		void PlayAnimation(const std::wstring& name, bool loop = true);

		Events* FindEvents(const std::wstring& name);
		std::function<void()>& GetStartEvent(const std::wstring& name);
		std::function<void()>& GetCompleteEvent(const std::wstring& name);
		std::function<void()>& GetEndEvent(const std::wstring& name);

		bool IsCompleteAnimation() { return mActiveAnimation->IsComplete(); }

	private:
		std::map<std::wstring, MyAnimation*> mAnimations;
		MyAnimation* mActiveAnimation;
		bool mbLoop;

		//Event
		std::map<std::wstring, Events*> mEvents;
	};
}

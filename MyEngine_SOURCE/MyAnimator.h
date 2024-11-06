#pragma once
#include "MyComponent.h"
#include "MyAnimation.h"

namespace my
{
	class MyAnimator : public MyComponent
	{
	public:
		MyAnimator();
		~MyAnimator();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void CreateAnimation(const std::wstring& name
			, graphcis::MyTexture* spriteSheet
			, Vector2 leftTop
			, Vector2 size
			, Vector2 offset
			, UINT spriteLegth
			, float duration);

		MyAnimation* FindAnimation(const std::wstring& name);
		void PlayAnimation(const std::wstring& name, bool loop = true);

	private:
		std::map<std::wstring, MyAnimation*> mAnimations;
		MyAnimation* mActiveAnimation;
		bool mbLoop;
	};
}

#pragma once
#include "MyResource.h"
#include "MyTexture.h"

namespace my 
{
	class MyAnimation : public MyResource
	{
	public:
		struct Sprite
		{
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float duration;

			Sprite()	// 구조체에서도 생성자가 가능했구나...
				: leftTop(Vector2::Zero)
				, size(Vector2::Zero)
				, offset(Vector2::Zero)
				, duration(0.0f)
			{

			}
		};

		MyAnimation();
		~MyAnimation();

		HRESULT Load(const std::wstring& path) override;

		void Update();
		void Render(HDC hdc);

		void CreateAnimation(const std::wstring& name
			, graphics::MyTexture* spriteSheet
			, Vector2 leftTop
			, Vector2 size
			, Vector2 offset
			, UINT spriteLegth
			, float duration);

		void Reset();

		bool IsComplete() { return mbComplete; }
		void SetAnimator(class MyAnimator* animator) { mAnimator = animator; }

	private:
		class MyAnimator* mAnimator;
		graphics::MyTexture* mTexture;

		std::vector<Sprite> mAnimationSheet;
		int mIndex;
		float mTime;
		bool mbComplete;
	};
}


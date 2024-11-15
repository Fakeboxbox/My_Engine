#pragma once
#include "..\\MyEngine_SOURCE\\MyScript.h"
#include "..\\MyEngine_SOURCE\\MyTexture.h"

namespace my
{
	class MyPlayerScript : public MyScript
	{
	public:
		enum class eState
		{
			Idle,
			Walk,
			Sleep,
			GiveWater,
			Attack
		};

		MyPlayerScript();
		~MyPlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void AttackEffect();

		void OnCollisionEnter(class MyCollider* other) override;
		void OnCollisionStay(class MyCollider* other) override;
		void OnCollisionExit(class MyCollider* other) override;

		void SetPixelMapTexture(graphics::MyTexture* texture) { mPixelMap = texture; }
		
	private:
		void idle();
		void move();
		void giveWater();

	private:
		eState mState;
		class MyAnimator* mAnimator;
		graphics::MyTexture* mPixelMap;
	};
}


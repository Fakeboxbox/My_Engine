#pragma once
#include "..\\MyEngine_SOURCE\\MyScript.h"

namespace my
{
	class MyPlayerScript : public MyScript
	{
	public:
		enum class eState
		{
			SitDown,
			Walk,
			Sleep,
			Attack
		};

		MyPlayerScript();
		~MyPlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		
	private:
		void sitDown();
		void move();

	private:
		eState mState;
		class MyAnimator* mAnimator;
	};
}


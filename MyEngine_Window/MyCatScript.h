#pragma once
#include "..\\MyEngine_SOURCE\\MyScript.h"
#include "..\\MyEngine_SOURCE\\MyTransform.h"

namespace my
{
	class MyCatScript : public MyScript
	{
	public:
		enum class eState
		{
			SitDown,
			Walk,
			Sleep,
			LayDown,
			Attack
		};

		enum class eDirection
		{
			Left,
			Right,
			Down,
			Up,
			End
		};

		MyCatScript();
		~MyCatScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		// 벡터 테스트 코드
		void SetPlayer(class MyGameObject* player) { mPlayer = player; }
		Vector2 mDest;

	private:
		void sitDown();
		void move();
		void layDown();

		void PlayWalkAnimationByDirection(eDirection direction);
		void translate(MyTransform* tr);

	private:
		eState mState;
		eDirection mDirection;
		class MyAnimator* mAnimator;
		float mTime;
		float mDeathTime;

		// 벡터 테스트 코드
		class MyGameObject* mPlayer;
		float mRadian;
	};
}

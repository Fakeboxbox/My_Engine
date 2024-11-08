#pragma once
#include "MyComponent.h"

namespace my
{
	using namespace my::math;
	class MyCamera : public MyComponent
	{
	public:
		Vector2 CalculatePosition(Vector2 pos) { return pos - mDistance; }
		MyCamera();
		~MyCamera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTarget(MyGameObject* target) { mTarget = target; }

	private:
		class MyGameObject* mTarget;
		Vector2 mDistance;
		Vector2 mResolution;
		Vector2 mLookPosition;
	};
}


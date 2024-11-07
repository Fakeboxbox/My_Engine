#pragma once
#include "MyEntity.h"
#include "MyComponent.h"

namespace my
{
	using namespace math;
	class MyTransform : public MyComponent
	{
	public:
		MyTransform();
		~MyTransform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPos(Vector2 pos) { mPosition.x = pos.x, mPosition.y = pos.y; }
		Vector2 GetPosition() { return mPosition; }
		void SetRotation(float rotate) { mRotation = rotate; }
		float GetRotation() { return mRotation; }
		void SetScale(Vector2 scale) { mScale = scale; }
		Vector2 GetScale() { return mScale; }

	private:
		Vector2 mPosition;
		Vector2 mScale;
		float mRotation;
	};
}


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

	private:
		Vector2 mPosition;
	};
}


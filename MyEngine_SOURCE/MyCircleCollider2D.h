#pragma once
#include "MyCollider.h"

namespace my
{
	class MyCircleCollider2D : public MyCollider
	{
	public:
		MyCircleCollider2D();
		~MyCircleCollider2D();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

	private:
		float mRadius;
	};
}


#pragma once
#include "MyCollider.h"

namespace my
{
	class MyBoxCollider2D : public MyCollider
	{
	public:
		MyBoxCollider2D();
		~MyBoxCollider2D();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

	private:
		Vector2 mSize;
	};
}



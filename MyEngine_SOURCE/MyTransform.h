#pragma once
#include "MyEntity.h"
#include "MyComponent.h"

namespace my
{
	struct pos
	{
		int mX;
		int mY;
	};

	class MyTransform : public MyComponent
	{
	public:
		MyTransform();
		~MyTransform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPos(int x, int y)
		{
			mX = x;
			mY = y;
		}

		int GetX()
		{
			return mX;
		}

		int GetY()
		{
			return mY;
		}

	private:
		int mX;
		int mY;
	};
}


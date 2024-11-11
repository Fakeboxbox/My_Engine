#pragma once
#include "..\\MyEngine_SOURCE\\MyGameObject.h"

namespace my
{
	class MyFloor : public MyGameObject
	{
	public:
		MyFloor();
		~MyFloor();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}
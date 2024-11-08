#pragma once
#include "..\\MyEngine_SOURCE\\MyGameObject.h"

namespace my
{
	class MyPlayer : public MyGameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		//void AttackEffect();

	private:

	};
}


#pragma once
#include "..\\MyEngine_SOURCE\\MyGameObject.h"

namespace my
{
	class MyCat : public MyGameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}

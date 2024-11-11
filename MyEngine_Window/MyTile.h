#pragma once
#include "..\\MyEngine_SOURCE\\MyGameObject.h"

namespace my
{
	class MyTile : public MyGameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPosition(int x, int y);
		
	private:

	};
}
#pragma once
#include "..\\MyEngine_SOURCE\\MyScene.h"

namespace my
{
	class MyPlayScene : public MyScene
	{
	public:
		MyPlayScene();
		~MyPlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}

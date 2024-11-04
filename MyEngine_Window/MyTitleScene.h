#pragma once
#include "..\\MyEngine_SOURCE\\MyScene.h"

namespace my
{
	class MyTitleScene : public MyScene
	{
	public:
		MyTitleScene();
		~MyTitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:

	};
}


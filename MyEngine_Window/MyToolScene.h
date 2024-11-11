#pragma once
#include "..\\MyEngine_SOURCE\\MyScene.h"

namespace my
{
	class MyToolScene : public MyScene
	{
	public:
		MyToolScene();
		~MyToolScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:

	};
}

LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
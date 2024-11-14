#pragma once
#include "..\\MyEngine_SOURCE\\MyScene.h"
#include "MyTile.h"

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

		void Save();
		void Load();

	private:
		void renderGreed(HDC hdc);
		void createTileObject();

	private:
		std::vector<MyTile*> mTiles;
	};
}

LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
#include "MyToolScene.h"
#include "MyObject.h"
#include "MyTile.h"
#include "MyTilemapRenderer.h"
#include "MyResources.h"
#include "MyTexture.h"
#include "MyCamera.h"
#include "MyRenderer.h"
#include "MyInput.h"

namespace my
{
	MyToolScene::MyToolScene()
	{

	}

	MyToolScene::~MyToolScene()
	{

	}

	void MyToolScene::Initialize()
	{
		MyGameObject* camera = object::Instantiate<MyGameObject>(enums::eLayerType::particle, Vector2(343.0f, 442.0f));
		MyCamera* cameraComp = camera->AddComponent<MyCamera>();
		renderer::mainCamera = cameraComp;

		MyTile* tile = object::Instantiate<MyTile>(eLayerType::Tile);
		MyTilemapRenderer* tmr = tile->AddComponent<MyTilemapRenderer>();

		tmr->SetTexture(MyResources::Find<graphics::MyTexture>(L"SpringFloor"));

		MyScene::Initialize();
	}

	void MyToolScene::Update()
	{
		MyScene::Update();
	}

	void MyToolScene::LateUpdate()
	{
		MyScene::LateUpdate();

		if (MyInput::GetKey(eKeyCode::LButton))
		{
			Vector2 pos = MyInput::GetMousePosition();

			int idxX = pos.x / MyTilemapRenderer::TileSize.x;
			int idxY = pos.y / MyTilemapRenderer::TileSize.y;

			MyTile* tile = object::Instantiate<MyTile>(eLayerType::Tile);
			MyTilemapRenderer* tmr = tile->AddComponent<MyTilemapRenderer>();
			tmr->SetTexture(MyResources::Find<graphics::MyTexture>(L"SpringFloor"));

			tile->SetPosition(idxX, idxY);
		}
	}

	void MyToolScene::Render(HDC hdc)
	{
		MyScene::Render(hdc);

		for (size_t i = 0; i < 20; i++)
		{
			MoveToEx(hdc, MyTilemapRenderer::TileSize.x * i, 0, NULL);
			LineTo(hdc, MyTilemapRenderer::TileSize.x * i, 1000);
		}

		for (size_t i = 0; i < 30; i++)
		{
			MoveToEx(hdc, 0, MyTilemapRenderer::TileSize.y * i, NULL);
			LineTo(hdc, 1000, MyTilemapRenderer::TileSize.y * i);
		}
	}

	void MyToolScene::OnEnter()
	{
		MyScene::OnEnter();
	}

	void MyToolScene::OnExit()
	{
		MyScene::OnExit();
	}
}

LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		my::graphics::MyTexture* tilemapTexture
			= my::MyResources::Find<my::graphics::MyTexture>(L"SpringFloor");

		TransparentBlt(hdc
			, 0
			, 0
			, tilemapTexture->GetWidth()
			, tilemapTexture->GetHeight()
			, tilemapTexture->GetHdc()
			, 0, 0
			, tilemapTexture->GetWidth()
			, tilemapTexture->GetHeight()
			, RGB(255, 0, 255));

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
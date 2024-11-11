#include "MyToolScene.h"
#include "MyObject.h"
#include "MyTile.h"
#include "MyTilemapRenderer.h"
#include "MyResources.h"
#include "MyTexture.h"
#include "MyCamera.h"
#include "MyCameraScript.h"
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
		camera->AddComponent<MyCameraScript>();
		renderer::mainCamera = cameraComp;

		/*MyTile* tile = object::Instantiate<MyTile>(eLayerType::Tile);
		MyTilemapRenderer* tmr = tile->AddComponent<MyTilemapRenderer>();

		tmr->SetTexture(MyResources::Find<graphics::MyTexture>(L"SpringFloor"));*/

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
			pos = renderer::mainCamera->CalculateTilePosition(pos);

			if (pos.x >= 0.0f && pos.y >= 0.0f)
			{
				int idxX = pos.x / MyTilemapRenderer::TileSize.x;
				int idxY = pos.y / MyTilemapRenderer::TileSize.y;

				MyTile* tile = object::Instantiate<MyTile>(eLayerType::Tile);
				MyTilemapRenderer* tmr = tile->AddComponent<MyTilemapRenderer>();
				tmr->SetTexture(MyResources::Find<graphics::MyTexture>(L"SpringFloor"));
				tmr->SetIndex(MyTilemapRenderer::SelectedIndex);

				tile->SetIndexPosition(idxX, idxY);
				mTiles.push_back(tile);
			}
			else
			{
				//
			}
		}

		if (MyInput::GetKeyDown(eKeyCode::S))
		{
			Save();
		}

		if (MyInput::GetKeyDown(eKeyCode::L))
		{
			Load();
		}
	}

	void MyToolScene::Render(HDC hdc)
	{
		MyScene::Render(hdc);

		for (size_t i = 0; i < 50; i++)
		{
			Vector2 pos = renderer::mainCamera->CalculatePosition
			(
				Vector2(MyTilemapRenderer::TileSize.x * i, 0.0f)
			);

			MoveToEx(hdc, pos.x, 0, NULL);
			LineTo(hdc, pos.x, 1000);
		}

		for (size_t i = 0; i < 50; i++)
		{
			Vector2 pos = renderer::mainCamera->CalculatePosition
			(
				Vector2(0.0f, MyTilemapRenderer::TileSize.y * i)
			);

			MoveToEx(hdc, 0, pos.y, NULL);
			LineTo(hdc, 1000, pos.y);
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

	void MyToolScene::Save()
	{
		// 01010으로 이루어진 데이터를 binary데이터라고 부른다.
		// 하지만 binary데이터는 사람이 이해하기 어렵기 때문에 텍스트 데이터로 저장하는 경우가 많다.

		// 데이터의 저장의 순서가 같은 확장자이면 항상 동일한 순서로 저장을한다.
		// png는 png의 저장순서가 있고 pdf는 pdf의 저장순서가 있다는 의미

		// open a file name 마소에서 제공해주는 설정값들
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"Tile\0*.tile\0";	// 저장하고싶은 확장자명
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetSaveFileName(&ofn))
			return;

		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"wb");

		for (MyTile* tile : mTiles)
		{
			MyTilemapRenderer* tmr = tile->GetComponent<MyTilemapRenderer>();
			MyTransform* tr = tile->GetComponent<MyTransform>();

			Vector2 sourceIndex = tmr->GetIndex();
			Vector2 position = tr->GetPosition();

			int x = sourceIndex.x;
			fwrite(&x, sizeof(int), 1, pFile);
			int y = sourceIndex.y;
			fwrite(&y, sizeof(int), 1, pFile);

			x = position.x;
			fwrite(&x, sizeof(int), 1, pFile);
			y = position.y;
			fwrite(&y, sizeof(int), 1, pFile);
		}

		fclose(pFile);
	}

	void MyToolScene::Load()
	{
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"All\0*.*\0Text\0*, TXT\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetOpenFileName(&ofn))
			return;

		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"rb");

		while (true)
		{
			int idxX = 0;
			int idxY = 0;

			int posX = 0;
			int posY = 0;

			if (fread(&idxX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&idxY, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posY, sizeof(int), 1, pFile) == NULL)
				break;

			MyTile* tile = object::Instantiate<MyTile>(eLayerType::Tile, Vector2(posX, posY));
			MyTilemapRenderer* tmr = tile->AddComponent<MyTilemapRenderer>();
			tmr->SetTexture(MyResources::Find<graphics::MyTexture>(L"SpringFloor"));
			tmr->SetIndex(Vector2(idxX, idxY));

			mTiles.push_back(tile);
		}

		fclose(pFile);
	}
}

LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(hWnd, &mousePos);

		my::math::Vector2 mousePosition;
		mousePosition.x = mousePos.x;
		mousePosition.y = mousePos.y;

		int idxX = mousePosition.x / my::MyTilemapRenderer::OriginTileSize.x;
		int idxY = mousePosition.y / my::MyTilemapRenderer::OriginTileSize.y;

		my::MyTilemapRenderer::SelectedIndex = Vector2(idxX, idxY);
	}
	break;
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
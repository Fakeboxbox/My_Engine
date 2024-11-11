#include "MyToolScene.h"
#include "MyObject.h"
#include "MyTile.h"
#include "MyTilemapRenderer.h"
#include "MyResources.h"
#include "MyTexture.h"
#include "MyCamera.h"
#include "MyRenderer.h"

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
	}

	void MyToolScene::Render(HDC hdc)
	{
		MyScene::Render(hdc);

		for (size_t i = 0; i < 20; i++)
		{
			MoveToEx(hdc, (16 * 3) * i, 0, NULL);
			LineTo(hdc, (16 * 3) * i, 1000);
		}

		for (size_t i = 0; i < 30; i++)
		{
			MoveToEx(hdc, 0, (16 * 3) * i, NULL);
			LineTo(hdc, 1000, (16 * 3) * i);
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
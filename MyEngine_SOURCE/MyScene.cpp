#include "MyScene.h"

namespace my
{
	MyScene::MyScene()
		: mLayers{}
	{
		mLayers.resize((UINT)enums::eLayerType::Max);

		for (size_t i = 0; i < (UINT)enums::eLayerType::Max; ++i)
		{
			mLayers[i] = new MyLayer();
		}
	}

	MyScene::~MyScene()
	{
		for ( MyLayer* layer : mLayers)
		{
			delete layer;
			layer = nullptr;
		}
	}

	void MyScene::Initialize()
	{
		for (MyLayer* layer : mLayers)
		{
			if (layer == nullptr)
			{
				continue;
			}

			layer->Initialize();
		}
	}

	void MyScene::Update()
	{
		for (MyLayer* layer : mLayers)
		{
			if (layer == nullptr)
			{
				continue;
			}

			layer->Update();
		}
	}

	void MyScene::LateUpdate()
	{
		for (MyLayer* layer : mLayers)
		{
			if (layer == nullptr)
			{
				continue;
			}

			layer->LateUpdate();
		}
	}

	void MyScene::Render(HDC hdc)
	{
		for (MyLayer* layer : mLayers)
		{
			if (layer == nullptr)
			{
				continue;
			}

			layer->Render(hdc);
		}
	}

	void MyScene::OnEnter()
	{

	}

	void MyScene::OnExit()
	{

	}

	void MyScene::AddGameObject(MyGameObject* gameObj, const enums::eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObj);
	}
}
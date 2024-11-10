#pragma once
#include "MyComponent.h"
#include "MyGameObject.h"
#include "MyLayer.h"
#include "MyScene.h"
#include "MySceneManager.h"

namespace my::object
{
	template <typename T>
	static T* Instantiate(my::enums::eLayerType type)
	{
		T* gameObject = new T();
		MyScene* activeScene = MySceneManager::GetAcitiveScene();
		MyLayer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(my::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		MyScene* activeScene = MySceneManager::GetAcitiveScene();
		MyLayer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);
		
		MyTransform* tr = gameObject->GetComponent<MyTransform>();
		tr->SetPos(position);

		return gameObject;
	}

	/*static void Destory(MyGameObject* obj)
	{
		if (obj != nullptr)
			return;

		obj->Death();
	}*/
}
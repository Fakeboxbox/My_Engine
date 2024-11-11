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
		gameObject->SetLayerType(type);
		MyScene* activeScene = MySceneManager::GetAcitiveScene();
		MyLayer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(my::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(type);
		MyScene* activeScene = MySceneManager::GetAcitiveScene();
		MyLayer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);
		
		MyTransform* tr = gameObject->GetComponent<MyTransform>();
		tr->SetPos(position);

		return gameObject;
	}

	static void DontDestroyOnLoad(MyGameObject* obj)
	{
		MyScene* activeScene = MySceneManager::GetAcitiveScene();
		// 현재 씬에서 게임오브젝트를 지워준다
		activeScene->EraseGameObject(obj);
		// 해당 게임 오브젝트를 DontDestroyOnLoad씬으로 넣어준다.
		MyScene* dontDestroyOnLoad = MySceneManager::GetDontDestroyOnLoad();
		dontDestroyOnLoad->AddGameObject(obj, obj->GetLayerType());
	}
}
#pragma once
#include "MyEntity.h"
#include "MyGameObject.h"
#include "MyLayer.h"

namespace my
{
	class MyScene : public MyEntity
	{
	public:
		MyScene();
		~MyScene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(MyGameObject* gameObj, const enums::eLayerType type);
		void EraseGameObject(MyGameObject* gameObj);
		MyLayer* GetLayer(enums::eLayerType type) { return mLayers[(UINT)type]; }

	private:
		void createLayers();

	private:
		std::vector<MyLayer*> mLayers;
	};
}

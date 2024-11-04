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

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(MyGameObject* gameObj, const eLayerType type);

	private:
		std::vector<MyLayer*> mLayers;
	};
}

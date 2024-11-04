#pragma once
#include "MyEntity.h"
#include "CommonInclude.h"
#include "MyGameObject.h"

namespace my
{
	class MyLayer : public MyEntity
	{
	public:
		MyLayer();
		~MyLayer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(MyGameObject* gameObject);

	private:
		//eLayerType mType;
		std::vector<MyGameObject*> mGameObjects;
	};
}


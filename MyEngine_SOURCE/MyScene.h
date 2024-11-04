#pragma once
#include "MyEntity.h"
#include "MyGameObject.h"

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

		void AddGameObject(MyGameObject* gameObject);

	private:
		std::vector<MyGameObject*> mGameObjects;
	};
}

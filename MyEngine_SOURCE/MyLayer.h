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
		virtual void Destroy();

		void AddGameObject(MyGameObject* gameObject);
		void EraseGameObject(MyGameObject* eraseGameObj);
		const std::vector<MyGameObject*> GetGameObjects() { return mGameObjects; }

	private:
		void findDeadGameObjects(OUT std::vector<MyGameObject*>& gameObjs);
		void deleteGameObjects(std::vector<MyGameObject*> deleteObjs);
		void eraseDeadGameObject();

	private:
		//eLayerType mType;
		std::vector<MyGameObject*> mGameObjects;
	};

	typedef std::vector<MyGameObject*>::iterator GameObjectIter;
}



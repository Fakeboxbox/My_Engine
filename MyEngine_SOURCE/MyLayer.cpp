#include "MyLayer.h"

namespace my
{
	MyLayer::MyLayer()
		: mGameObjects{}
	{

	}

	MyLayer::~MyLayer()
	{
		for (MyGameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			delete gameObj;
			gameObj = nullptr;
		}
	}

	void MyLayer::Initialize()
	{
		for (MyGameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
			{
				continue;
			}

			gameObj->Initialize();
		}
	}

	void MyLayer::Update()
	{
		for (MyGameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			if (gameObj->IsAcitve() == false)
				continue;

			gameObj->Update();
		}
	}

	void MyLayer::LateUpdate()
	{
		for (MyGameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			if (gameObj->IsAcitve() == false)
				continue;

			gameObj->LateUpdate();
		}
	}

	void MyLayer::Render(HDC hdc)
	{
		for (MyGameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			if (gameObj->IsAcitve() == false)
				continue;

			gameObj->Render(hdc);
		}
	}

	void MyLayer::Destroy()
	{
		std::vector<MyGameObject*> deleteObjects = {};
		findDeadGameObjects(deleteObjects);
		eraseDeadGameObject();
		deleteGameObjects(deleteObjects);
	}

	void MyLayer::AddGameObject(MyGameObject* gameObject)
	{
		if (gameObject == nullptr)
		{
			return;
		}

		mGameObjects.push_back(gameObject);
	}

	void MyLayer::EraseGameObject(MyGameObject* eraseGameObj)
	{
		//std::erase() 는 iter 넣어줘서 해당 이터와 같은 개체 삭제
		// 그리고 []을 캡쳐라고 한다. 람다 캡쳐 알아볼 것 (람다 : 함수인데 함수선언 없이 필요할때 사용하는 함수, 무명함수라 함, 전달인자만 존재)
		std::erase_if(mGameObjects, 
			[=](MyGameObject* gameObj)	// vector에서 특정 조건을 만족시키는 값들을 삭제할때 사용하는 C++20 문법
			{
				return gameObj == eraseGameObj;	// eraseGameObj는 외부에 있기때문에 캡쳐를 통해 어떤식으로 값을 받아올지 정해줘야한다. = 값복사, & 참조
			}
		);
	}

	void MyLayer::findDeadGameObjects(OUT std::vector<MyGameObject*>& gameObjs)	// OUT : 해당 매개변수를 통해 값을 출력할 것이라는 의미, 코드 가독성을 위해 사용
	{
		for (MyGameObject* gameObj : mGameObjects)
		{
			MyGameObject::eState active = gameObj->GetActive();
			if (active == MyGameObject::eState::Dead)
			{
				gameObjs.push_back(gameObj);
			}
		}
	}

	void MyLayer::deleteGameObjects(std::vector<MyGameObject*> deleteObjs)
	{
		for (MyGameObject* obj : deleteObjs)
		{
			delete obj;
			obj = nullptr;
		}
	}

	void MyLayer::eraseDeadGameObject()
	{
		std::erase_if(mGameObjects, 
			[](MyGameObject* gameObj)
			{
				return (gameObj)->IsDead();
			}
		);
	}
}
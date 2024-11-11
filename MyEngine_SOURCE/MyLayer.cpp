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
		//std::erase() �� iter �־��༭ �ش� ���Ϳ� ���� ��ü ����
		// �׸��� []�� ĸ�Ķ�� �Ѵ�. ���� ĸ�� �˾ƺ� �� (���� : �Լ��ε� �Լ����� ���� �ʿ��Ҷ� ����ϴ� �Լ�, �����Լ��� ��, �������ڸ� ����)
		std::erase_if(mGameObjects, 
			[=](MyGameObject* gameObj)	// vector���� Ư�� ������ ������Ű�� ������ �����Ҷ� ����ϴ� C++20 ����
			{
				return gameObj == eraseGameObj;	// eraseGameObj�� �ܺο� �ֱ⶧���� ĸ�ĸ� ���� ������� ���� �޾ƿ��� ��������Ѵ�. = ������, & ����
			}
		);
	}

	void MyLayer::findDeadGameObjects(OUT std::vector<MyGameObject*>& gameObjs)	// OUT : �ش� �Ű������� ���� ���� ����� ���̶�� �ǹ�, �ڵ� �������� ���� ���
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
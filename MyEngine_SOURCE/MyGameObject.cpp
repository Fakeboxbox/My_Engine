#include "MyGameObject.h"
#include "MyTransform.h"

namespace my::object
{
	void Destroy(MyGameObject* gameObject)
	{
		if (gameObject != nullptr)
			gameObject->death();
	}
}

namespace my
{
	MyGameObject::MyGameObject()
		: mState(eState::Active)
	{
		mComponents.resize((UINT)enums::eComponentType::End);
		initializeTransform();
	}

	MyGameObject::~MyGameObject()
	{
		for (MyComponent* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			delete comp;
			comp = nullptr;
		}
	}

	void MyGameObject::Initialize()
	{
		for (MyComponent* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Initialize();
		}
	}

	void MyGameObject::Update()
	{
		for (MyComponent* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Update();
		}
	}

	void MyGameObject::LateUpdate()
	{
		for (MyComponent* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->LateUpdate();
		}
	}

	void MyGameObject::Render(HDC hdc)
	{
		for (MyComponent* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Render(hdc);
		}
	}

	void MyGameObject::initializeTransform()
	{
		AddComponent<MyTransform>();
	}
}
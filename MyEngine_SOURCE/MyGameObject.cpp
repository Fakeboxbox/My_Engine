#include "MyGameObject.h"
#include "MyTransform.h"

namespace my
{
	MyGameObject::MyGameObject()
	{
		mComponents.resize((UINT)enums::eComponentType::End);
		initializeTransform();
	}

	MyGameObject::~MyGameObject()
	{
		for (MyComponent* comp : mComponents)
		{
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
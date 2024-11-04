#include "MyGameObject.h"

namespace my
{
	MyGameObject::MyGameObject()
	{

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
			comp->Initialize();
		}
	}

	void MyGameObject::Update()
	{
		for (MyComponent* comp : mComponents)
		{
			comp->Update();
		}
	}

	void MyGameObject::LateUpdate()
	{
		for (MyComponent* comp : mComponents)
		{
			comp->LateUpdate();
		}
	}

	void MyGameObject::Render(HDC hdc)
	{
		for (MyComponent* comp : mComponents)
		{
			comp->Render(hdc);
		}
	}
}
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


		/*const int speed = 100.0f;

		if (MyInput::GetKey(eKeyCode::A))
		{
			mX -= speed * MyTime::DeltaTime();
		}

		if (MyInput::GetKey(eKeyCode::D))
		{
			mX += speed * MyTime::DeltaTime();
		}

		if (MyInput::GetKey(eKeyCode::W))
		{
			mY -= speed * MyTime::DeltaTime();
		}

		if (MyInput::GetKey(eKeyCode::S))
		{
			mY += speed * MyTime::DeltaTime();
		}*/
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
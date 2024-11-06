#include "MyPlayerScript.h"
#include "MyInput.h"
#include "MyTransform.h"
#include "MyTime.h"
#include "MyGameObject.h"

namespace my
{
	MyPlayerScript::MyPlayerScript()
	{

	}

	MyPlayerScript::~MyPlayerScript()
	{

	}

	void MyPlayerScript::Initialize()
	{

	}

	void MyPlayerScript::Update()
	{
		if (MyInput::GetKey(eKeyCode::Right))
		{
			MyTransform* tr = GetOwner()->GetComponent<MyTransform>();
			Vector2 pos = tr->GetPosition();
			pos.x += 100.0f * MyTime::DeltaTime();
			tr->SetPos(pos);
		}

		if (MyInput::GetKey(eKeyCode::Left))
		{
			MyTransform* tr = GetOwner()->GetComponent<MyTransform>();
			Vector2 pos = tr->GetPosition();
			pos.x -= 100.0f * MyTime::DeltaTime();
			tr->SetPos(pos);
		}

		if (MyInput::GetKey(eKeyCode::Up))
		{
			MyTransform* tr = GetOwner()->GetComponent<MyTransform>();
			Vector2 pos = tr->GetPosition();
			pos.y -= 100.0f * MyTime::DeltaTime();
			tr->SetPos(pos);
		}

		if (MyInput::GetKey(eKeyCode::Down))
		{
			MyTransform* tr = GetOwner()->GetComponent<MyTransform>();
			Vector2 pos = tr->GetPosition();
			pos.y += 100.0f * MyTime::DeltaTime();
			tr->SetPos(pos);
		}
	}

	void MyPlayerScript::LateUpdate()
	{

	}

	void MyPlayerScript::Render(HDC hdc)
	{

	}
}

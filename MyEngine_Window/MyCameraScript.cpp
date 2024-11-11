#include "MyCameraScript.h"
#include "MyInput.h"
#include "MyTransform.h"
#include "MyTime.h"
#include "MyGameObject.h"
#include "MyAnimator.h"
#include "MyObject.h"
#include "MyResources.h"

namespace my
{
	MyCameraScript::MyCameraScript()
	{

	}

	MyCameraScript::~MyCameraScript()
	{

	}

	void MyCameraScript::Initialize()
	{

	}

	void MyCameraScript::Update()
	{
		MyTransform* tr = GetOwner()->GetComponent<MyTransform>();
		Vector2 pos = tr->GetPosition();

		if (MyInput::GetKey(eKeyCode::Right))
		{
			pos.x += 1000.0f * MyTime::DeltaTime();
		}
		if (MyInput::GetKey(eKeyCode::Left))
		{
			pos.x -= 1000.0f * MyTime::DeltaTime();
		}
		if (MyInput::GetKey(eKeyCode::Up))
		{
			pos.y -= 1000.0f * MyTime::DeltaTime();
		}
		if (MyInput::GetKey(eKeyCode::Down))
		{
			pos.y += 1000.0f * MyTime::DeltaTime();
		}

		tr->SetPos(pos);
	}

	void MyCameraScript::LateUpdate()
	{

	}

	void MyCameraScript::Render(HDC hdc)
	{

	}
}
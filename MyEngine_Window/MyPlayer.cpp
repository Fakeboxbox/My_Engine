#include "MyPlayer.h"
#include "MyInput.h"
#include "MyTransform.h"
#include "MyTime.h"

namespace my
{
	void MyPlayer::Initialize()
	{
		MyGameObject::Initialize();
	}

	void MyPlayer::Update()
	{
		MyGameObject::Update();
	}

	void MyPlayer::LateUpdate()
	{
		MyGameObject::LateUpdate();

		if (MyInput::GetKey(eKeyCode::Right))
		{
			MyTransform* tr = GetComponent<MyTransform>();
			Vector2 pos = tr->GetPosition();
			pos.x += 100.0f * MyTime::DeltaTime();
			tr->SetPos(pos);
		}
	}

	void MyPlayer::Render(HDC hdc)
	{
		MyGameObject::Render(hdc);
	}
}
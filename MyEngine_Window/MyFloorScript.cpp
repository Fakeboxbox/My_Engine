#include "MyFloorScript.h"
#include "MyCatScript.h"
#include "MyInput.h"
#include "MyTransform.h"
#include "MyTime.h"
#include "MyGameObject.h"
#include "MyAnimator.h"
#include "MyObject.h"
#include "MyRigdbody.h"

namespace my
{
	MyFloorScript::MyFloorScript()
	{

	}

	MyFloorScript::~MyFloorScript()
	{

	}

	void MyFloorScript::Initialize()
	{

	}

	void MyFloorScript::Update()
	{

	}

	void MyFloorScript::LateUpdate()
	{

	}

	void MyFloorScript::Render(HDC hdc)
	{

	}

	void MyFloorScript::OnCollisionEnter(MyCollider* other)
	{
		MyRigdbody* playerRb = other->GetOwner()->GetComponent<MyRigdbody>();
		MyTransform* playerTr = other->GetOwner()->GetComponent<MyTransform>();
		MyCollider* playerCol = other;

		MyRigdbody* floorRb = this->GetOwner()->GetComponent<MyRigdbody>();
		MyTransform* floorTr = this->GetOwner()->GetComponent<MyTransform>();
		MyCollider* floorCol = this->GetOwner()->GetComponent<MyCollider>();

		float len = fabs(playerTr->GetPosition().y - floorTr->GetPosition().y);
		float scale = fabs(playerCol->GetSize().y * 100 / 2.0f - floorCol->GetSize().y * 100 / 2.0f);

		if (len < scale)
		{
			Vector2 playerPos = playerTr->GetPosition();
			playerPos.y -= (scale - len) - 1.0f;

			playerTr->SetPos(playerPos);
		}

		playerRb->SetGround(true);
	}

	void MyFloorScript::OnCollisionStay(MyCollider* other)
	{

	}

	void MyFloorScript::OnCollisionExit(MyCollider* other)
	{

	}
}
#include "MyCollider.h"
#include "MyScript.h"
#include "MyGameObject.h"

namespace my
{
	UINT32 MyCollider::mCollisonID = 1;

	MyCollider::MyCollider(eColliderType type)
		: MyComponent(enums::eComponentType::Collider)
		, mType(type)
		, mID(mCollisonID++)
		, mSize(Vector2::One)
	{

	}

	MyCollider::~MyCollider()
	{

	}

	void MyCollider::Initialize()
	{

	}

	void MyCollider::Update()
	{

	}

	void MyCollider::LateUpdate()
	{

	}

	void MyCollider::Render(HDC hdc)
	{

	}

	void MyCollider::OnCollisionEnter(MyCollider* other)
	{
		MyScript* script = GetOwner()->GetComponent<MyScript>();
		script->OnCollisionEnter(other);
	}

	void MyCollider::OnCollisionStay(MyCollider* other)
	{
		MyScript* script = GetOwner()->GetComponent<MyScript>();
		script->OnCollisionStay(other);
	}

	void MyCollider::OnCollisionExit(MyCollider* other)
	{
		MyScript* script = GetOwner()->GetComponent<MyScript>();
		script->OnCollisionExit(other);
	}
}
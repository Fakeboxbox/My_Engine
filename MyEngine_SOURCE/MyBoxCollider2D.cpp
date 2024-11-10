#include "MyBoxCollider2D.h"
#include "MyTransform.h"
#include "MyGameObject.h"

namespace my
{
	MyBoxCollider2D::MyBoxCollider2D()
	{

	}

	MyBoxCollider2D::~MyBoxCollider2D()
	{

	}

	void MyBoxCollider2D::Initialize()
	{

	}

	void MyBoxCollider2D::Update()
	{

	}

	void MyBoxCollider2D::LateUpdate()
	{

	}

	void MyBoxCollider2D::Render(HDC hdc)
	{
		MyTransform* tr = GetOwner()->GetComponent<MyTransform>();
		Vector2 pos = tr->GetPosition();

		Vector2 offset = GetOffset();

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

		HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

		Rectangle(hdc
			, pos.x + offset.x
			, pos.y + offset.y
			, pos.x + offset.x + 100
			, pos.y + offset.y + 100);

		(HBRUSH)SelectObject(hdc, oldBrush);
		(HPEN)SelectObject(hdc, oldPen);

		DeleteObject(greenPen);
	}
}
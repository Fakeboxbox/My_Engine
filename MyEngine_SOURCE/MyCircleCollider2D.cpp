#include "MyCircleCollider2D.h"
#include "MyTransform.h"
#include "MyGameObject.h"
#include "MyRenderer.h"
#include "MyCamera.h"

namespace my
{
	MyCircleCollider2D::MyCircleCollider2D()
		: MyCollider(enums::eColliderType::Circle2D)
		, mRadius(0.0f)
	{

	}

	MyCircleCollider2D::~MyCircleCollider2D()
	{

	}

	void MyCircleCollider2D::Initialize()
	{

	}

	void MyCircleCollider2D::Update()
	{

	}

	void MyCircleCollider2D::LateUpdate()
	{

	}

	void MyCircleCollider2D::Render(HDC hdc)
	{
		MyTransform* tr = GetOwner()->GetComponent<MyTransform>();
		Vector2 pos = tr->GetPosition();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePosition(pos);

		Vector2 offset = GetOffset();

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

		HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

		Vector2 rightBottom;
		rightBottom.x = pos.x + offset.x + 100 * GetSize().x;
		rightBottom.y = pos.y + offset.y + 100 * GetSize().y;

		Ellipse(hdc
			, pos.x + offset.x
			, pos.y + offset.y
			, rightBottom.x
			, rightBottom.y);

		(HBRUSH)SelectObject(hdc, oldBrush);
		(HPEN)SelectObject(hdc, oldPen);

		DeleteObject(greenPen);
	}
}
#include "MySpriteRenderer.h"
#include "MyGameObject.h"
#include "MyTransform.h"

namespace my
{
	MySpriteRenderer::MySpriteRenderer()
	{

	}

	MySpriteRenderer::~MySpriteRenderer()
	{

	}

	void MySpriteRenderer::Initialize()
	{

	}

	void MySpriteRenderer::Update()
	{

	}

	void MySpriteRenderer::LateUpdate()
	{

	}

	void MySpriteRenderer::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		HPEN redpen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
		HPEN oldpen = (HPEN)SelectObject(hdc, redpen);
		SelectObject(hdc, oldpen);

		MyTransform* tr = GetOwner()->GetComponent<MyTransform>();

		Ellipse(hdc, tr->GetX(), tr->GetY(), 100 + tr->GetX(), 100 + tr->GetY());

		SelectObject(hdc, oldBrush);
		DeleteObject(brush);
		DeleteObject(redpen);
	}
}
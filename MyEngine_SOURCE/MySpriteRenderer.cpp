#include "MySpriteRenderer.h"
#include "MyGameObject.h"
#include "MyTransform.h"

namespace my
{
	MySpriteRenderer::MySpriteRenderer()
		: mImage(nullptr)
		, mWidth(0)
		, mHeight(0)
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
		MyTransform* tr = GetOwner()->GetComponent<MyTransform>();
		Vector2 pos = tr->GetPosition();

		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));
	}

	void MySpriteRenderer::ImageLoad(const std::wstring& path)
	{
		mImage = Gdiplus::Image::FromFile(path.c_str());
		mWidth = mImage->GetWidth();
		mHeight = mImage->GetHeight();
	}
}
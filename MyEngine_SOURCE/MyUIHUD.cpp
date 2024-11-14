#include "MyUIHUD.h"
#include "MyResources.h"

namespace my
{
	MyUIHUD::MyUIHUD()
		:MyUIBase(eUIType::HpBar)
		, mTexture(nullptr)
	{

	}

	MyUIHUD::~MyUIHUD()
	{

	}

	void MyUIHUD::OnInit()
	{
		mTexture = MyResources::Find<graphics::MyTexture>(L"HPBAR");
	}

	void MyUIHUD::OnActive()
	{

	}

	void MyUIHUD::OnInActive()
	{

	}

	void MyUIHUD::OnUpdate()
	{

	}

	void MyUIHUD::OnLateUpdate()
	{

	}

	void MyUIHUD::OnRender(HDC hdc)
	{
		TransparentBlt(hdc
			, 0
			, 0
			, mTexture->GetWidth()
			, mTexture->GetHeight()
			, mTexture->GetHdc()
			, 0, 0
			, mTexture->GetWidth()
			, mTexture->GetHeight()
			, RGB(255, 0, 255));
	}

	void MyUIHUD::OnClear()
	{

	}
}
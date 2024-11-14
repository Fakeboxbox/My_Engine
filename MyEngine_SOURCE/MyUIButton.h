#pragma once
#include "MyUIBase.h"
#include "MyTexture.h"

namespace my
{
	class MyUIButton : public MyUIBase
	{
	public:
		MyUIButton();
		~MyUIButton();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnUpdate() override;
		virtual void OnLateUpdate() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void ButtonClick();

	private:
		graphics::MyTexture* mTexture;
		Event mOnclik;
	};
}



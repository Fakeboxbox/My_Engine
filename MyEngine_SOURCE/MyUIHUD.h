#pragma once
#include "MyUIBase.h"
#include "MyTexture.h"

namespace my
{
	class MyUIHUD : public MyUIBase
	{
	public:
		MyUIHUD();
		~MyUIHUD();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnUpdate() override;
		virtual void OnLateUpdate() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

	private:
		graphics::MyTexture* mTexture;

	};
}


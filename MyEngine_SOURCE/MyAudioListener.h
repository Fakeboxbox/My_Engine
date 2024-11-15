#pragma once
#include "MyComponent.h"

namespace my
{
	class MyAudioListener : public MyComponent
	{
	public:
		MyAudioListener();
		~MyAudioListener();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}
#pragma once
#include "..\\MyEngine_SOURCE\\MyScript.h"

namespace my
{
	class MyPlayerScript : public MyScript
	{
	public:
		MyPlayerScript();
		~MyPlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}


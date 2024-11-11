#pragma once
#include "..\\MyEngine_SOURCE\\MyScript.h"
#include "..\\MyEngine_SOURCE\\MyTransform.h"

namespace my
{
	class MyCameraScript : public MyScript
	{
	public:
		MyCameraScript();
		~MyCameraScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}



#pragma once
#include "..\\MyEngine_SOURCE\\MyScript.h"

namespace my
{
	class MyFloorScript : public MyScript
	{
	public:
		MyFloorScript();
		~MyFloorScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnCollisionEnter(MyCollider* other) override;
		void OnCollisionStay(MyCollider* other) override;
		void OnCollisionExit(MyCollider* other) override;

	private:
		
	};
}

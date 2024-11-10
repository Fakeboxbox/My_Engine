#pragma once
#include "MyComponent.h"

namespace my
{
	class MyScript : public MyComponent
	{
	public:
		MyScript();
		~MyScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class MyCollider* other);
		virtual void OnCollisionStay(class MyCollider* other);
		virtual void OnCollisionExit(class MyCollider* other);

	private:

	};
}


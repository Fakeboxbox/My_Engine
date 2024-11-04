#pragma once
#include "MyEntity.h"
#include "MyComponent.h"

namespace my
{
	class MySpriteRenderer : public MyComponent
	{
	public:
		MySpriteRenderer();
		~MySpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}

#pragma once
#include "MyEntity.h"
#include "MyComponent.h"
#include "MyTexture.h"

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

		void SetTexture(graphcis::MyTexture* texture) { mTexture = texture; }
		void SetSize(math::Vector2 size) { mSize = size; }

	private:
		graphcis::MyTexture* mTexture;
		math::Vector2 mSize;
	};
}
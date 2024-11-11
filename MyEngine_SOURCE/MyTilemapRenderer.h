#pragma once
#include "MyEntity.h"
#include "MyComponent.h"
#include "MyTexture.h"

namespace my
{
	class MyTilemapRenderer : public MyComponent
	{
	public:
		MyTilemapRenderer();
		~MyTilemapRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTexture(graphics::MyTexture* texture) { mTexture = texture; }
		void SetSize(Vector2 size) { mSize = size; }

	public:
		static Vector2 TileSize;

	private:
		graphics::MyTexture* mTexture;
		Vector2 mSize;
		Vector2 mIndex;
		Vector2 mTileSize;
	};
}
#include "MyTile.h"
#include "MyTransform.h"
#include "MyTilemapRenderer.h"

namespace my
{
	void MyTile::Initialize()
	{
		MyGameObject::Initialize();
	}

	void MyTile::Update()
	{
		MyGameObject::Update();
	}

	void MyTile::LateUpdate()
	{
		MyGameObject::LateUpdate();
	}

	void MyTile::Render(HDC hdc)
	{
		MyGameObject::Render(hdc);
	}

	void MyTile::SetIndexPosition(int x, int y)
	{
		MyTransform* tr = GetComponent<MyTransform>();
		Vector2 pos;
		pos.x = x * MyTilemapRenderer::TileSize.x;
		pos.y = y * MyTilemapRenderer::TileSize.y;
		tr->SetPos(pos);
	}
}
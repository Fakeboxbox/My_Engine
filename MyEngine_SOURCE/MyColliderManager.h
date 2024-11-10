#pragma once
#include "CommonInclude.h"
#include "MyBoxCollider2D.h"
#include "MyCircleCollider2D.h"

namespace my
{
	using namespace enums;

	union CollisionID	// ����ü : �����͸� ��� �ɰ��� �ҷ��� �� �ֵ��� �ϴ� ����
	{
		struct
		{
			UINT32 left;
			UINT32 right;
		};

		UINT64 id;
	};

	class MyColliderManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

		static void CollisionLayerCheck(eLayerType left, eLayerType right, bool enable);
		static void LayerCollision(class MyScene* scene, eLayerType left, eLayerType right);
		static void ColliderCollision(MyCollider* left, MyCollider* right);
		static bool Intersect(MyCollider* left, MyCollider* right);

	private:
		static std::bitset<(UINT)eLayerType::Max> mCollisionLayerMatrix[(UINT)eLayerType::Max];
		static std::unordered_map<UINT64, bool> mCollisionMap;
	};
}


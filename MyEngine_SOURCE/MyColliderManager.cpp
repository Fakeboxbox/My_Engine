#include "MyColliderManager.h"
#include "MyScene.h"
#include "MySceneManager.h"
#include "MyGameObject.h"
#include "MyCollider.h"

namespace my
{
	std::bitset<(UINT)eLayerType::Max> MyColliderManager::mCollisionLayerMatrix[(UINT)eLayerType::Max] = {};

	void MyColliderManager::Initialize()
	{

	}

	void MyColliderManager::Update()
	{
		MyScene* scene = MySceneManager::GetAcitiveScene();

		for (UINT row = 0; row < (UINT)eLayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)eLayerType::Max; col++)
			{
				if (mCollisionLayerMatrix[row][col] == true)
				{
					// 충돌체크
					LayerCollision(scene, (eLayerType)row, (eLayerType)col);
				}
			}
		}
	}

	void MyColliderManager::LateUpdate()
	{
		
	}

	void MyColliderManager::Render(HDC hdc)
	{

	}

	void MyColliderManager::CollisionLayerCheck(eLayerType left, eLayerType right, bool enable)
	{
		int row = 0;
		int col = 0;

		if (left <= right)
		{
			row = (UINT)left;
			col = (UINT)right;
		}
		else
		{
			row = (UINT)right;
			col = (UINT)left;
		}

		mCollisionLayerMatrix[row][col] = enable;
	}

	void MyColliderManager::LayerCollision(MyScene* scene, eLayerType left, eLayerType right)
	{
		const std::vector<MyGameObject*>& lefts = scene->GetLayer(left)->GetGameObjects();
		const std::vector<MyGameObject*>& rights = scene->GetLayer(right)->GetGameObjects();

		// 지금은 2중포문으로 충돌체크를 하고있지만 현업에서는 옥트리를 사용하기도 한다. 이것이 좀더 연산량이 적다.
		for (MyGameObject* left : lefts)
		{
			if (left->IsAcitve() == false)
				continue;

			MyCollider* leftCol = left->GetComponent<MyCollider>();
			if (leftCol == nullptr)
				continue;
			
			for (MyGameObject* right : rights)
			{
				if (right->IsAcitve() == false)
					continue;

				MyCollider* rightCol = right->GetComponent<MyCollider>();
				if (rightCol == nullptr)
					continue;

				if (left == right)
					continue;

				ColliderCollision(leftCol, rightCol);
			}
		}
	}

	void MyColliderManager::ColliderCollision(MyCollider* left, MyCollider* right)
	{
		// 충돌체크 로직 작성
	}
}

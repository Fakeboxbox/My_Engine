#include "MyColliderManager.h"
#include "MyScene.h"
#include "MySceneManager.h"
#include "MyGameObject.h"
#include "MyCollider.h"
#include "MyTransform.h"

namespace my
{
	std::bitset<(UINT)eLayerType::Max> MyColliderManager::mCollisionLayerMatrix[(UINT)eLayerType::Max] = {};
	std::unordered_map<UINT64, bool> MyColliderManager::mCollisionMap = {};

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
		// 두 충돌체 번호를 가져온 ID를 확인해서 CollisionID값을 세팅
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();

		// 해당 ID로 충돌체 정보를 검색해준다.
		// 만약 충돌체 정도가 없다면 충돌정보를 생성해준다.
		auto iter = mCollisionMap.find(id.id);
		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert(std::make_pair(id.id, false));
			iter = mCollisionMap.find(id.id);
		}

		// 충돌체크 로직 작성
		if (Intersect(left, right))
		{
			if (iter->second == false)	// 최초 충돌시
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);
				iter->second = true;
			}
			else	// 이미 충돌 중
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}


		}
		else
		{
			if (iter->second == true)	// 충돌중이었으나 이제는 충돌이 아닌 상태
			{
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);
				iter->second = false;
			}
		}
	}

	bool MyColliderManager::Intersect(MyCollider* left, MyCollider* right)
	{
		MyTransform* leftTr = left->GetOwner()->GetComponent<MyTransform>();
		MyTransform* rightTr = right->GetOwner()->GetComponent<MyTransform>();

		Vector2 leftPos = leftTr->GetPosition() + left->GetOffset();
		Vector2 rightPos = rightTr->GetPosition() + right->GetOffset();

		// size 1, 1 일때 기본크기가 100픽셀
		Vector2 leftSize = left->GetSize() * 100.0f;
		Vector2 rightSize = right->GetSize() * 100.0f;

		// AABB 충돌
		enums::eColliderType leftType = left->GetColliderType();
		enums::eColliderType rightType = right->GetColliderType();

		if (leftType == enums::eColliderType::Rect2D
			&& rightType == enums::eColliderType::Rect2D)
		{
			// rect - rect
			if (fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f)
				&& fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f))
			{
				return true;
			}
		}

		if (leftType == enums::eColliderType::Circle2D
			&& rightType == enums::eColliderType::Circle2D)
		{
			// circle - circle
			Vector2 leftCirclePos = leftPos + (leftSize / 2.0f);
			Vector2 rightCirclePos = rightPos + (rightSize / 2.0f);

			float distance = (leftCirclePos - rightCirclePos).length();
			if (distance <= (leftSize.x / 2.0f + rightSize.x / 2.0f))
			{
				return true;
			}
		}

		if (leftType == enums::eColliderType::Rect2D && rightType == enums::eColliderType::Circle2D
			|| leftType == enums::eColliderType::Circle2D && rightType == enums::eColliderType::Rect2D)
		{
			// rect - circle || circle - rect
			
		}

		return false;
	}
}

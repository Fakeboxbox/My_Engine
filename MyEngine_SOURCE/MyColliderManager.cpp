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
					// �浹üũ
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

		// ������ 2���������� �浹üũ�� �ϰ������� ���������� ��Ʈ���� ����ϱ⵵ �Ѵ�. �̰��� ���� ���귮�� ����.
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
		// �� �浹ü ��ȣ�� ������ ID�� Ȯ���ؼ� CollisionID���� ����
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();

		// �ش� ID�� �浹ü ������ �˻����ش�.
		// ���� �浹ü ������ ���ٸ� �浹������ �������ش�.
		auto iter = mCollisionMap.find(id.id);
		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert(std::make_pair(id.id, false));
			iter = mCollisionMap.find(id.id);
		}

		// �浹üũ ���� �ۼ�
		if (Intersect(left, right))
		{
			if (iter->second == false)	// ���� �浹��
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);
				iter->second = true;
			}
			else	// �̹� �浹 ��
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}


		}
		else
		{
			if (iter->second == true)	// �浹���̾����� ������ �浹�� �ƴ� ����
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

		// size 1, 1 �϶� �⺻ũ�Ⱑ 100�ȼ�
		Vector2 leftSize = left->GetSize() * 100.0f;
		Vector2 rightSize = right->GetSize() * 100.0f;

		// AABB �浹
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

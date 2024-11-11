#pragma once
#include "CommonInclude.h"
#include "MyComponent.h"
#include "MyCollider.h"

namespace my::object
{
	void Destroy(MyGameObject* gameObject);
}

namespace my
{
	class MyGameObject : public MyEntity
	{
	public:
		friend void object::Destroy(MyGameObject* obj);

		enum class eState
		{
			Active,
			Paused,
			Dead,
			End
		};

		MyGameObject();
		~MyGameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);
			mComponents[(UINT)comp->GetType()] = comp;
			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (MyComponent* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);	//dynamic_cast : 부모 클래스의 포인터에서 자식 클래스의 포인터로 다운 캐스팅 해주는 연산자

				if (component)
					break;
			}

			return component;
		}

		eState GetActive() { return mState; }

		void SetActive(bool power)
		{
			if (power == true)
				mState = eState::Active;
			if (power == false)
				mState = eState::Paused;
		}

		bool IsAcitve() { return mState == eState::Active; }
		bool IsDead() { return mState == eState::Dead; }
		void SetLayerType(eLayerType layerType) { mLayerType = layerType; }
		eLayerType GetLayerType() { return mLayerType; }

	private:
		void initializeTransform();
		void death() { mState = eState::Dead; }

	private:
		eState mState;
		std::vector<MyComponent*> mComponents;
		eLayerType mLayerType;
	};
}
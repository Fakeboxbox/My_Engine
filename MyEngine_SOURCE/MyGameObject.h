#pragma once
#include "CommonInclude.h"
#include "MyComponent.h"

namespace my
{
	class MyGameObject
	{
	public:
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
				component = dynamic_cast<T*>(comp);	//dynamic_cast : �θ� Ŭ������ �����Ϳ��� �ڽ� Ŭ������ �����ͷ� �ٿ� ĳ���� ���ִ� ������

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

		void Death() { mState = eState::Dead; }

	private:
		void initializeTransform();

	private:
		eState mState;
		std::vector<MyComponent*> mComponents;
	};
}
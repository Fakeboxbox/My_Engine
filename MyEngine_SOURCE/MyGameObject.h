#pragma once
#include "CommonInclude.h"
#include "MyComponent.h"

namespace my
{
	class MyGameObject
	{
	public:
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
			comp->SetOwner(this);
			mComponents.push_back(comp);

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

		//void SetPosition(float x, float y)
		//{
		//	mX = x;
		//	mY = y;
		//}

		//float GetPositionX()
		//{
		//	return mX;
		//}

		//float GetPositionY()
		//{
		//	return mY;
		//}

	private:
		//���� ������Ʈ�� ��ǥ
		//float mX;
		//float mY;

		std::vector<MyComponent*> mComponents;
	};
}
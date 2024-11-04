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
				component = dynamic_cast<T*>(comp);	//dynamic_cast : 부모 클래스의 포인터에서 자식 클래스의 포인터로 다운 캐스팅 해주는 연산자

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
		//게임 오브젝트의 좌표
		//float mX;
		//float mY;

		std::vector<MyComponent*> mComponents;
	};
}
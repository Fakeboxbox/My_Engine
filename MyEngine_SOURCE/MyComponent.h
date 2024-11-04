#pragma once
#include "MyEntity.h"

namespace my
{
	class MyGameObject;
	class MyComponent : public MyEntity
	{
	public:
		MyComponent();
		~MyComponent();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(MyGameObject* owner) { mOwner = owner; }
		MyGameObject* GetOwner() { return mOwner; }

	private:
		MyGameObject* mOwner;
	};
}


#pragma once
#include "MyEntity.h"

namespace my
{
	class MyGameObject;
	class MyComponent : public MyEntity
	{
	public:
		MyComponent(enums::eComponentType Type);
		~MyComponent();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(MyGameObject* owner) { mOwner = owner; }
		MyGameObject* GetOwner() { return mOwner; }
		enums::eComponentType GetType() { return mType; }

	private:
		MyGameObject* mOwner;
		enums::eComponentType mType;
	};
}


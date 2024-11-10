#pragma once
#include "MyEntity.h"

namespace my
{
	using namespace enums;
	class MyGameObject;
	class MyComponent : public MyEntity
	{
	public:
		MyComponent(eComponentType type);
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


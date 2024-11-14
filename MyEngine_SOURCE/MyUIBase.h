#pragma once
#include "MyEntity.h"

namespace my
{
	using namespace enums;
	class MyUIBase : public MyEntity
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}
			void operator()()
			{
				if (mEvent)
					mEvent();
			}
			std::function<void()> mEvent;
		};

		MyUIBase(eUIType type);
		virtual ~MyUIBase();

		void Initialize();	// UI가 로드 되었을때 초기화 해주는 함수
		void Update();
		void LateUpdate();
		void Render(HDC hdc);
		void Active();	// UI가 활성화되면 호출되는 함수
		void InActive(); // UI가 비활성화되면 호출되는 함수
		void UIClear(); // UI가 사라질때 호출되는 함수

		virtual void OnInit();
		virtual void OnActive();
		virtual void OnInActive();
		virtual void OnUpdate();
		virtual void OnLateUpdate();
		virtual void OnRender(HDC hdc);
		virtual void OnClear();

		eUIType GetType() { return mType; }
		void SetType(eUIType type) { mType = type; }
		void SetFullScreen(bool enable) { mbFullScreen = enable; }
		bool IsFullScreen() { return mbFullScreen; }
		Vector2 GetPos() { return mPosition; }
		void SetPos(Vector2 pos) { mPosition = pos; }
		Vector2 GetSize() { return mSize; }
		void SetSize(Vector2 size) { mSize = size; }

	protected:
		Vector2 mPosition;
		Vector2 mSize;
		bool mbMouseOn;

	private:
		eUIType mType;
		bool mbFullScreen;
		bool mbEnabled;

		MyUIBase* mParent;
	};
}


#pragma once
#include "MyScene.h"

namespace my
{
	class MyDontDestroyOnLoad : public MyScene
	{
	public:
		MyDontDestroyOnLoad();
		~MyDontDestroyOnLoad();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:

	};
}
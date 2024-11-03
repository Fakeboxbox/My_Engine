#pragma once
#include "CommonInclude.h"

namespace my
{
	class MyTime
	{

	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return DeltaTimeValue; }

	private:
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PreFrequency;
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTimeValue;
	};
}


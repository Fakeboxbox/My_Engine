#include "MyTime.h"

namespace my
{
	LARGE_INTEGER MyTime::CpuFrequency = {};
	LARGE_INTEGER MyTime::PreFrequency = {};
	LARGE_INTEGER MyTime::CurrentFrequency = {};
	float MyTime::DeltaTimeValue = 0.0f;

	void MyTime::Initialize()
	{
		QueryPerformanceFrequency(&CpuFrequency);

		QueryPerformanceCounter(&PreFrequency);
	}

	void MyTime::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		float differenceFrequency = (static_cast<float>(CurrentFrequency.QuadPart - PreFrequency.QuadPart));
		DeltaTimeValue = differenceFrequency / (static_cast<float>(CpuFrequency.QuadPart));
		PreFrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	void MyTime::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;

		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %d", (int)fps);
		int len = wcsnlen_s(str, 50);


		TextOut(hdc, 0, 0, str, len);
	}
}
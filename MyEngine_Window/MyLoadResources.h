#pragma once
#include "..\\MyEngine_SOURCE\\MyResources.h"
#include "..\\MyEngine_SOURCE\\MyTexture.h"


namespace my
{
	void LoadResources()
	{
		MyResources::Load<graphcis::MyTexture>(L"BG", L"C:\\Users\\danpa\\OneDrive\\πŸ≈¡ »≠∏È\\Project\\MyEngine\\Resources\\CloudOcean.png");
	}
}
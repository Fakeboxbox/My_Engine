#pragma once
#include "..\\MyEngine_SOURCE\\MyResources.h"
#include "..\\MyEngine_SOURCE\\MyTexture.h"


namespace my
{
	void LoadResources()
	{
		MyResources::Load<graphcis::MyTexture>(L"Map", L"C:\\Users\\danpa\\OneDrive\\πŸ≈¡ »≠∏È\\Project\\MyEngine\\Resources\\img\\map\\map_pure.png");
		MyResources::Load<graphcis::MyTexture>(L"PackMan", L"C:\\Users\\danpa\\OneDrive\\πŸ≈¡ »≠∏È\\Project\\MyEngine\\Resources\\img\\pacman\\0.png");
		MyResources::Load<graphcis::MyTexture>(L"Cat", L"C:\\Users\\danpa\\OneDrive\\πŸ≈¡ »≠∏È\\Project\\MyEngine\\Resources\\ChickenAlpha.bmp");
	}
}
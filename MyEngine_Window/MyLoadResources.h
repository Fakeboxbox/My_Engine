#pragma once
#include "..\\MyEngine_SOURCE\\MyResources.h"
#include "..\\MyEngine_SOURCE\\MyTexture.h"


namespace my
{
	void LoadResources()
	{
		MyResources::Load<graphics::MyTexture>(L"Chicken", L"..\\Resources\\chicken.bmp");
		MyResources::Load<graphics::MyTexture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
		MyResources::Load<graphics::MyTexture>(L"Player", L"..\\Resources\\Player.bmp");
		MyResources::Load<graphics::MyTexture>(L"SpringFloor", L"..\\Resources\\SpringFloor.bmp");
	}
}
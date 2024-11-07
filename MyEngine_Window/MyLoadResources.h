#pragma once
#include "..\\MyEngine_SOURCE\\MyResources.h"
#include "..\\MyEngine_SOURCE\\MyTexture.h"


namespace my
{
	void LoadResources()
	{
		MyResources::Load<graphcis::MyTexture>(L"Chicken", L"..\\Resources\\chicken.bmp");
		MyResources::Load<graphcis::MyTexture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
		MyResources::Load<graphcis::MyTexture>(L"Player", L"..\\Resources\\Player.bmp");
	}
}
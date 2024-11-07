#pragma once
#include "..\\MyEngine_SOURCE\\MyResources.h"
#include "..\\MyEngine_SOURCE\\MyTexture.h"


namespace my
{
	void LoadResources()
	{
		MyResources::Load<graphcis::MyTexture>(L"Map", L"..\\Resources\\img\\map\\map_pure.png");
		MyResources::Load<graphcis::MyTexture>(L"PackMan", L"..\\Resources\\img\\pacman\\0.png");
		MyResources::Load<graphcis::MyTexture>(L"Chicken", L"..\\Resources\\chicken.bmp");
		MyResources::Load<graphcis::MyTexture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
		MyResources::Load<graphcis::MyTexture>(L"Bubble", L"..\\Resources\\Bubble.png");
		MyResources::Load<graphcis::MyTexture>(L"MapleEffect", L"..\\Resources\\ezgif.com-gif-maker.png");
	}
}
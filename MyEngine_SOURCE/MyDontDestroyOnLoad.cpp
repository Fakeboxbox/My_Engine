#include "MyDontDestroyOnLoad.h"

namespace my
{
	MyDontDestroyOnLoad::MyDontDestroyOnLoad()
	{
		
	}

	MyDontDestroyOnLoad::~MyDontDestroyOnLoad()
	{

	}

	void MyDontDestroyOnLoad::Initialize()
	{
		MyScene::Initialize();
	}

	void MyDontDestroyOnLoad::Update()
	{
		MyScene::Update();
	}

	void MyDontDestroyOnLoad::LateUpdate()
	{
		MyScene::LateUpdate();
	}

	void MyDontDestroyOnLoad::Render(HDC hdc)
	{
		MyScene::Render(hdc);
	}

	void MyDontDestroyOnLoad::OnEnter()
	{
		MyScene::OnEnter();
	}
	void MyDontDestroyOnLoad::OnExit()
	{
		MyScene::OnExit();
	}
}
#include "MyUIBase.h"

namespace my
{
	MyUIBase::MyUIBase(eUIType type)
		: mType(type)
		, mbMouseOn(false)
		, mPosition(Vector2::Zero)
		, mSize(Vector2::Zero)
		, mbFullScreen(false)
		, mbEnabled(false)
	{

	}

	MyUIBase::~MyUIBase()
	{

	}

	void MyUIBase::Initialize()
	{
		OnInit();
	}

	void MyUIBase::Update()
	{
		if (mbEnabled)
			OnUpdate();
	}

	void MyUIBase::LateUpdate()
	{
		if (mbEnabled)
			OnLateUpdate();
	}

	void MyUIBase::Render(HDC hdc)
	{
		if (mbEnabled)
			OnRender(hdc);
	}

	void MyUIBase::Active()
	{
		mbEnabled = true;
		OnActive();
	}

	void MyUIBase::InActive()
	{
		mbEnabled = false;
		OnInActive();
	}

	void MyUIBase::UIClear()
	{
		OnClear();
	}

	void MyUIBase::OnInit()
	{

	}

	void MyUIBase::OnActive()
	{

	}

	void MyUIBase::OnInActive()
	{

	}

	void MyUIBase::OnUpdate()
	{

	}

	void MyUIBase::OnLateUpdate()
	{

	}

	void MyUIBase::OnRender(HDC hdc)
	{

	}

	void MyUIBase::OnClear()
	{

	}
}
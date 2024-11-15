#include "MyAudioListener.h"
#include "MyTransform.h"
#include "MyGameObject.h"
#include "MyFmod.h"

namespace my
{
	MyAudioListener::MyAudioListener()
		: MyComponent(eComponentType::AudioListener)
	{

	}

	MyAudioListener::~MyAudioListener()
	{

	}

	void MyAudioListener::Initialize()
	{

	}

	void MyAudioListener::Update()
	{

	}

	void MyAudioListener::LateUpdate()
	{
		MyTransform* tr = GetOwner()->GetComponent<MyTransform>();
		Vector2 pos = tr->GetPosition();

		MyFmod::Set3DListenerAttributes(&pos);
	}

	void MyAudioListener::Render(HDC hdc)
	{

	}
}
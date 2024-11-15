#include "MyAudioSource.h"
#include "MyTransform.h"
#include "MyGameObject.h"
#include "MyFmod.h"

namespace my
{
	MyAudioSource::MyAudioSource()
		:MyComponent(eComponentType::AudioSource)
		, mAudioClip(nullptr)
	{

	}

	MyAudioSource::~MyAudioSource()
	{

	}

	void MyAudioSource::Initialize()
	{

	}

	void MyAudioSource::Update()
	{

	}

	void MyAudioSource::LateUpdate()
	{
		MyTransform* tr = GetOwner()->GetComponent<MyTransform>();
		Vector2 pos = tr->GetPosition();

		mAudioClip->Set3DAttributes(pos);
	}

	void MyAudioSource::Render(HDC hdc)
	{

	}

	void MyAudioSource::Play()
	{
		mAudioClip->Play();
	}

	void MyAudioSource::Stop()
	{
		mAudioClip->Stop();
	}

	void MyAudioSource::SetLoop(bool loop)
	{
		mAudioClip->SetLoop(loop);
	}
}
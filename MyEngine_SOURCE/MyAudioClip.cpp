#include "MyAudioClip.h"

namespace my
{
	MyAudioClip::MyAudioClip()
		: MyResource(enums::eResourceType::AudioClip)
		, mSound(nullptr)
		, mChannel(nullptr)
		, mMinDistance(1.0f)
		, mMaxDistance(1000.0f)
		, mbLoop(false)
	{

	}

	MyAudioClip::~MyAudioClip()
	{
		mSound->release();
		mSound = nullptr;
	}

	HRESULT MyAudioClip::Load(const std::wstring& path)
	{
		std::string cPath(path.begin(), path.end());
		if (!MyFmod::CreateSound(cPath, &mSound))
			return S_FALSE;

		mSound->set3DMinMaxDistance(mMinDistance, mMaxDistance);

		return S_OK;
	}

	void MyAudioClip::Play()
	{
		if (mbLoop)
			mSound->setMode(FMOD_LOOP_NORMAL);
		else
			mSound->setMode(FMOD_LOOP_OFF);

		MyFmod::SoundPlay(mSound, &mChannel);
	}

	void MyAudioClip::Stop()
	{
		mChannel->stop();
	}

	void MyAudioClip::Set3DAttributes(const Vector2 pos)
	{

	}
}
#pragma once
#include "MyFmod.h"
#include "MyResource.h"

namespace my
{
	class MyAudioClip : public MyResource
	{
	public:
		MyAudioClip();
		virtual ~MyAudioClip();

		virtual HRESULT Load(const std::wstring& path) override;

		void Play();
		void Stop();
		void Set3DAttributes(const Vector2 pos);
		void SetLoop(bool loop) { mbLoop = loop; }

	private:
		FMOD::Sound* mSound;
		FMOD::Channel* mChannel;
		float mMinDistance;
		float mMaxDistance;
		bool mbLoop;
	};
}

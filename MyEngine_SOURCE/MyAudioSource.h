#pragma once
#include "MyComponent.h"
#include "MyAudioClip.h"

namespace my
{
	class MyAudioSource : public MyComponent
	{
	public:
		MyAudioSource();
		~MyAudioSource();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void Play();
		void Stop();
		void SetLoop(bool loop);

		void SetClip(MyAudioClip* clip) { mAudioClip = clip; }
		MyAudioClip* GetClip() { return mAudioClip; }

	private:
		MyAudioClip* mAudioClip;
	};

}

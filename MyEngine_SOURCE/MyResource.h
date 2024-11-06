#pragma once
#include "MyEntity.h"

namespace my
{
	//게임에서 사용되는 데이터들의 종류
	// 이미지, 사운드등
	// 저장 게임 플레이데이터 HDD, 클라우드 저장을 해둔다.
	// 이것도 리소스이다.

	class MyResource : public MyEntity	// 순수가상함수가 하나라도 들어있는 클래스를 추상 클래스라고 칭함 -> 추상클래스는 메모리 할당이 안되기에 상속받아서 사용해야한다.
	{
	public:
		MyResource(enums::eResourceType Type);
		MyResource() = delete;
		virtual ~MyResource();

		virtual HRESULT Load(const std::wstring& path) = 0;	// 순수가상함수 실제 메모리할당이 불가능해지는 문법 -> 무조건 상속해서 사용하란 의미
		// HRESULT == bool 윈도우에서는 HRESULT 사용 권장

		void SetPath(const std::wstring& path) { mPath = path; }
		const std::wstring& GetPath() { return mPath; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}
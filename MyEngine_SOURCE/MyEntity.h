#pragma once
#include "CommonInclude.h"

namespace my
{
	class MyEntity
	{
	public:
		MyEntity();
		virtual ~MyEntity();

		void SetName(const std::wstring& name) { mName = name; }
		std::wstring& GetName() { return mName; }

	private:
		std::wstring mName;
	};
}
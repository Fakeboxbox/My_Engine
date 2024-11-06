#pragma once
#include "MyEntity.h"

namespace my
{
	//���ӿ��� ���Ǵ� �����͵��� ����
	// �̹���, �����
	// ���� ���� �÷��̵����� HDD, Ŭ���� ������ �صд�.
	// �̰͵� ���ҽ��̴�.

	class MyResource : public MyEntity	// ���������Լ��� �ϳ��� ����ִ� Ŭ������ �߻� Ŭ������� Ī�� -> �߻�Ŭ������ �޸� �Ҵ��� �ȵǱ⿡ ��ӹ޾Ƽ� ����ؾ��Ѵ�.
	{
	public:
		MyResource(enums::eResourceType Type);
		MyResource() = delete;
		virtual ~MyResource();

		virtual HRESULT Load(const std::wstring& path) = 0;	// ���������Լ� ���� �޸��Ҵ��� �Ұ��������� ���� -> ������ ����ؼ� ����϶� �ǹ�
		// HRESULT == bool �����쿡���� HRESULT ��� ����

		void SetPath(const std::wstring& path) { mPath = path; }
		const std::wstring& GetPath() { return mPath; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}
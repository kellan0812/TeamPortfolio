#include "Stdafx.h"
#include "KeyManager.h"

HRESULT KeyManager::init(void)
{
	// 키값을 전부 눌려있지 않은 상태로 초기화
	for (int i = 0; i < KEY_MAX; i++)
	{
		this->setKeyDown(i, false);
		this->setKeyUp(i, false);
	}
	return S_OK;
}

bool KeyManager::isOnceKeyDown(int key)
{
	/*
	GetAsyncKeyState: API 공용함수   프레임구축안하고 간단하게 작업할때 씀
	- 어떤 키가 입력된건지 체크 or 프로그램에서 키를 입력받고 싶을때 사용한다.
	-> 메세지 큐에 있는 키의 정보를 확인한다(가져온다)

	0x0000 : 이전에 누른 적이 없고 호출 시점에서 눌려잇지 않은 상태
	0x0001 : 이전에 누른 적이 있고 호출 시점에서 눌려잇지않은 상태
	0x8000	: 이전에 누른 적이 없고 호출 시점에서 눌린 상태
	0x8001 : 이전에 누른 적이 있고 호출시점에서 눌린 상태

	*/

	//AND 연산 : & 연산자
	//비트 단위로 AND 연산을 하겠다.
	// ㄴ 둘 다 1일때만 1이고, 아니면 결과가 0이다.
	if (GetAsyncKeyState(key) & 0x8000)
	{
		if (!this->getKeyDown()[key])  // ! 는 부정
		{
			this->setKeyDown(key, true);  
			return true;
		}
	}
	else this->setKeyDown(key, false);
	return false;
}

bool KeyManager::isOnceKeyUp(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		this->setKeyUp(key, true);
	}
	else
	{
		if (this->getKeyUp()[key])
		{
			this->setKeyUp(key, false);
			return true;
		}
	}

	return false;
}

bool KeyManager::isStayKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000) return true;
	
	return false;
}

bool KeyManager::isToggleKey(int key)
{
	if (GetKeyState(key) & 0x0001) return true;

	return false;
}

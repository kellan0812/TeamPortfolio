#include "stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void) //초기화
{
	GameNode::init(TRUE);
	IMAGEMANAGER->addImage("슈팅 맵", "Resources/Images/BackGround/ShootingBG.bmp", WINSIZE_X,WINSIZE_Y);

	_rocket = new Rocket;
	_rocket->init();
	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();	
	_rocket->release();
}

void MainGame::update(void) // 갱신
{
	GameNode::update();
	_rocket->update();
}

void MainGame::render(void) // 그려줘
{
	//검은색 빈 비트맵
	//PatBlt() : 사각형 영역을 브러쉬로 채우는 함수
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	IMAGEMANAGER->findImage("슈팅 맵")->render(getMemDC());
	_rocket->render();

	this->getBackBuffer()->render(getHDC()); //백버퍼의 내용을 HDC에 그린다.
}
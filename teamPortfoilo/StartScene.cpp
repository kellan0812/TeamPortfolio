#include "stdafx.h"
#include "StartScene.h"


HRESULT StartScene::init(void)
{
	IMAGEMANAGER->addImage("시작화면", "Resources/Images/BackGround/bgAll.bmp", 1280, 800);
	//IMAGEMANAGER->addImage("텍스트 알파", "Resources/Images/Object/StartText.bmp", 1000, 100, true, RGB(255, 0, 255));
	_alpha = _bgAlpha = 0;
	_isAlphaIncrese = false;
	return S_OK;
}

void StartScene::release(void)
{
}

void StartScene::update(void)
{
	_bgAlpha += 0.5f;
	if (_bgAlpha >= 255) _bgAlpha = 255;

	if (_alpha == 0 || _alpha == 255) _isAlphaIncrese = !_isAlphaIncrese;		//논리 뒤집기
	if (_isAlphaIncrese) _alpha += 1.0f; else _alpha -= 1.5;					//논리 뒤집기
}

void StartScene::render(void)
{
	IMAGEMANAGER->alphaRender("시작화면", getMemDC(), 0, 0, _bgAlpha);

	if (_bgAlpha >= 160)
	{
		//IMAGEMANAGER->alphaRender("텍스트 알파", getMemDC(), 130, WINSIZE_Y / 2, 255);
	}
}

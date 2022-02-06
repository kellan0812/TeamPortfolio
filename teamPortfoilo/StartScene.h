#pragma once
#include "GameNode.h"

class StartScene :public GameNode
{
private:
	float _alpha;
	float _bgAlpha;
	int _alphaA, _alphaNum;
	bool _isAlphaIncrese;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	StartScene() {}
	~StartScene() {}
};


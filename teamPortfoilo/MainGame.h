#pragma once
#include "GameNode.h"
#include "Rocket.h"
class MainGame : public GameNode
{
private:
	Rocket* _rocket;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	MainGame() {}
	~MainGame() {}
};
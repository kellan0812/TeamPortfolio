#pragma once
#include"GameNode.h"
struct Enemy
{
    RECT _rcEnemy;
    int _enemyHp;
    bool _isDamage;
    bool _isWaiting;
};
struct Player
{
    RECT _rcPlayer;
    int _plHp;
    bool _isLeft;
    bool _isDefend;
    bool _isWaiting;
    int _skillTime;
};
class SecondScene :public GameNode
{
private:
    Enemy _enemy;
    Player _player;

    int _count;
    int _indexA;
    int _indexB;
    int _alphaA;
    int _enemyAttCount;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	SecondScene() {}
	~SecondScene(){}
};
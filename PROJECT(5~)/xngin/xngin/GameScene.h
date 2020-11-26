#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Animation.h"
#include "MainScene.h"
#include "Number.h"
#include <list>
class GameScene : public Scene
{
private:
	int levelArray[5];
	int nowClickArray[5];
	int needClickArray[5];
	Sprite* body;
	Animation* left_Hand;
	Animation* right_Hand;
	Sprite* left_Hand_Button;
	Sprite* right_Hand_Button;
	Sprite* body_Button;
	Sprite* left_Leg_Button;
	Sprite* right_Leg_Button;
	Sprite* left_Leg;
	Sprite* right_Leg;
	Animation* player;
	std::list<Sprite*> backgroundList;
	std::list<Sprite*> bridgeList;
	std::list<Sprite*> obstacleList;
	std::list<Sprite*> coinList;
	bool firstBackground;
	int score;
	float scrollSpeed;
	float gravity;
	bool doubleJump, isJump;
	Number numArray[4];
public:
	GameScene();
	~GameScene();
	void Render();
	void Update(float dTime);
};


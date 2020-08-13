#include "stdafx.h"
#include "GameScene.h"


GameScene::GameScene() {
	gravity = 0;
	isJump = false;
	doubleJump = false;
	backgroundList.push_back(new Sprite("Resources/Sprites/BG.png"));
	Sprite* tmpBackground = new Sprite("Resources/Sprites/BG.png");
	tmpBackground->setPos(0, 0);
	backgroundList.push_back(tmpBackground);
	Sprite* tempBackground = new Sprite("Resources/Sprites/BG.png");
	tempBackground->setPos(SCREEN_WIDTH, 0);
	backgroundList.push_back(tempBackground);


	Sprite* tmpBridge = new Sprite("Resources/Sprites/LoopMap.png");
	tmpBridge->setPos(0, 350);
	bridgeList.push_back(tmpBridge);
	Sprite * tempBridge = new Sprite("Resources/Sprites/LoopMap.png");
	tempBridge ->setPos(SCREEN_WIDTH, 350);
	bridgeList.push_back(tempBridge);



	player = new Animation(2);
	player->AddFrame("Resources/Sprites/CH0.png");
	player->AddFrame("Resources/Sprites/CH1.png");
	player->AddFrame("Resources/Sprites/CH2.png");
	player->setPos(50, 150);
}

GameScene::~GameScene() {

}
void GameScene::Render() {
	for (auto& background : backgroundList) {
		background->Render();
	}
	for (auto& bridge : bridgeList) {
		bridge ->Render();
	}
	player->Render();
}
void GameScene::Update(float dTime) {
	Scene::Update(dTime);
	gravity += 9.8f;
	player->setPos(player->getPosX(), player->getPosY() + gravity * dTime);
	if (isJump) {
		player->setPos(player->getPosX(), player->getPosY() - 500 * dTime);
		if (doubleJump) {
			player->setPos(player->getPosX(), player->getPosY() - 300 * dTime);
		}
		if (inputManager->GetKeyState(VK_SPACE) == KEY_DOWN) {
			doubleJump = true;
		}
	}
	if (player->getPosY() > 150) {
		player->setPos(player->getPosX(), 150);
		doubleJump = false;
		isJump = false;
	}
	if (inputManager->GetKeyState(VK_SPACE) == KEY_DOWN) {
		if (player->getPosY() == 150) {
			isJump = true;
			gravity = 0;
		}
	}
	player->Update(dTime * 10);
	int backgroundDiff = 500 * dTime;
	for (auto iter = backgroundList.begin(); iter != backgroundList.end(); iter++) {
		(*iter)->setPos((*iter)->getPosX() - backgroundDiff, (*iter)->getPosY());

		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			SAFE_DELETE((*iter));
			iter = backgroundList.erase(iter);
			Sprite* tmpBackground = new Sprite("Resources/Sprites/BG.png");
			tmpBackground->setPos(SCREEN_WIDTH, 0);
			backgroundList.push_back(tmpBackground);
			if (iter == backgroundList.end()) {
				break;
			}
		}
	}
	for (auto iter = bridgeList.begin(); iter != bridgeList.end(); iter++) {
		(*iter)->setPos((*iter)->getPosX() - backgroundDiff, (*iter)->getPosY());

		if ((*iter)->getPosX() < -SCREEN_WIDTH) {
			SAFE_DELETE((*iter));
			iter =bridgeList.erase(iter);
			Sprite* tmpBridge = new Sprite("Resources/Sprites/LoopMap.png");
			tmpBridge->setPos(SCREEN_WIDTH, 350);
			bridgeList.push_back(tmpBridge);

			if (iter == bridgeList.end()) {
				break;
			}
		}
	}
}
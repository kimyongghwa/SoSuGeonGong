#include "stdafx.h"
#include "GameScene.h"
GameScene::GameScene() {
	firstBackground = false;
	scrollSpeed = 500;
	gravity = 0;
	isJump = false;
	doubleJump = false;
	score = 0;
/*
	backgroundList.push_back(new Sprite("Resources/Sprites/Background.png"));
	Sprite* tmpBackground = new Sprite("Resources/Sprites/Background2.png");
	tmpBackground->setPos(SCREEN_WIDTH,0);
	backgroundList.push_back(tmpBackground);

	Sprite* tmpBridge = new Sprite("Resources/Sprites/LoopMap.png");
	tmpBridge->setPos(0, 560);
	bridgeList.push_back(tmpBridge);

	Sprite* tempBridge = new Sprite("Resources/Sprites/LoopMap.png");
	tempBridge->setPos(SCREEN_WIDTH, 560);
	bridgeList.push_back(tempBridge);
	Sprite* tmpCoin = new Sprite("Resources/Sprites/coin-yellow.png");
	tmpCoin->setPos(SCREEN_WIDTH + 70, 400);
	coinList.push_back(tmpCoin);


	Sprite* tmpObstacle = new Sprite("Resources/Sprites/Drop.png");
	tmpObstacle->setPos(SCREEN_WIDTH, 500);
	obstacleList.push_back(tmpObstacle);
	*/
	body = new Sprite("Resources/Sprites/body3.png");
	body->setPos(512-354, 120);
	left_Hand = new Animation(20);
	left_Hand->AddFrame("Resources/Sprites/Hand5.png");
	left_Hand->AddFrame("Resources/Sprites/Hand10.png");
	left_Hand->setPos(512 - 354, 120);
	right_Hand = new Animation(20);
	right_Hand->AddFrame("Resources/Sprites/Hand15.png");
	right_Hand->AddFrame("Resources/Sprites/Hand20.png");
	right_Hand->setPos(512 - 354, 120);
	left_Leg = new Sprite("Resources/Sprites/leg5.png");
	left_Leg->setPos(512 - 354, 120);
	right_Leg = new Sprite("Resources/Sprites/leg10.png");
	right_Leg->setPos(512 - 354, 120);
	player = new Animation(20);
	
	
	
	left_Hand_Button = new Sprite("Resources/Sprites/PowerUp.png");
	left_Hand_Button->setPos(150,300);
	right_Hand_Button = new Sprite("Resources/Sprites/PowerUp.png");
	right_Hand_Button->setPos(1024-150, 300);
	left_Leg_Button = new Sprite("Resources/Sprites/PowerUp.png");
	left_Leg_Button->setPos(200, 500);
	right_Leg_Button = new Sprite("Resources/Sprites/PowerUp.png");
	right_Leg_Button->setPos(1024 - 200,500);
	body_Button = new Sprite("Resources/Sprites/PowerUp.png");
	body_Button->setPos(512 - 37, 150);
	for (int i = 0; i < 4; i++) {
		numArray[i].setPos(0 + 60 * i, 10);
	}
}
GameScene::~GameScene() {

}
void GameScene::Render() {
	/*
	for (auto& background : backgroundList) {
		background->Render();
	}
	for (auto& bridge : bridgeList) {
		bridge->Render();
	}
	for (auto& obstacle : obstacleList) {
		obstacle->Render();
	}
	for (auto& coin : coinList) {
		coin->Render();
	}
	for (int i = 0; i < 4; i++) {
		numArray[i].Render();
	}
	*/
	right_Leg->Render();
	body->Render();
	left_Hand->Render();
	right_Hand->Render();
	left_Leg->Render();
	left_Hand_Button->Render();
	right_Hand_Button->Render();
	left_Leg_Button->Render();
	right_Leg_Button->Render();
	body_Button->Render();
}
void GameScene::Update(float dTime) {
	Scene::Update(dTime);
	left_Hand->Update(dTime);
	right_Hand->Update(dTime);
	int randNum = rand() % 10 + 1;
	if (inputManager->GetKeyState(VK_LBUTTON) == KEY_DOWN) {
		if (body_Button->IsPointInRect(inputManager->GetMousePos())) {
			PostQuitMessage(0);
			return;
		}
	}
	/*
	if ((rand() % 10 + 1) == 1) {
		Sprite* tmpCoin = new Sprite("Resources/Sprites/coin-yellow.png");
		tmpCoin->setPos(SCREEN_WIDTH + 100, 400);
		coinList.push_back(tmpCoin);
	}
	numArray[0].setNum(score / 1000);
	numArray[1].setNum(score / 100 % 10);
	numArray[2].setNum(score / 10 % 10 );
	numArray[3].setNum(score % 10);
	*/
	//player->setPos(player->getPosX(), player->getPosY() + gravity * dTime);
	//if (isJump) {
	//	player->setPos(player->getPosX(), player->getPosY() - 360 * dTime);
	//	if (doubleJump) {
	//		player->setPos(player->getPosX(), player->getPosY() - 300 * dTime);
	//	}
	//	if (inputManager->GetKeyState(VK_UP) == KEY_DOWN || inputManager->GetKeyState(VK_SPACE) == KEY_DOWN) {
	//		doubleJump = true;
	//	}
	//}
	//if (player->getPosY() > 370) {
	//	player->setPos(player->getPosX(), 370);
	//	doubleJump = false;
	//	isJump = false;
	//}
	//if (inputManager->GetKeyState(VK_UP) == KEY_DOWN || inputManager->GetKeyState(VK_SPACE) == KEY_DOWN) {
	//	if (player->getPosY() == 370) {
	//		isJump = true;
	//		gravity = 0;
	//	}
	//}
/*
	player->setPos(inputManager->GetMousePos());

	player->Update(dTime);
	int backgroundDiff = scrollSpeed * dTime;
	scrollSpeed +=0.1f;
	for (auto iter = backgroundList.begin(); iter != backgroundList.end(); iter++ ) {
		(*iter)->setPos((*iter)->getPosX() - backgroundDiff, (*iter)->getPosY());
		if ((*iter)->getPosX() < -SCREEN_WIDTH ) { // 여기서 10은 조절해도댐
			SAFE_DELETE(*iter);
			iter = backgroundList.erase(iter);
			if (firstBackground) {
				Sprite* tmpBackground = new Sprite("Resources/Sprites/Background2.png");
				tmpBackground->setPos(SCREEN_WIDTH, 0);
				backgroundList.push_back(tmpBackground);
				firstBackground = false;
			}
			else {
				Sprite* tmpBackground = new Sprite("Resources/Sprites/Background.png");
				tmpBackground->setPos(SCREEN_WIDTH, 0);
				backgroundList.push_back(tmpBackground);
				firstBackground = true;

			}
			if (iter == backgroundList.end()) {
				break;
			}
		}
	}
	for (auto iter = bridgeList.begin(); iter != bridgeList.end(); iter++) {
		(*iter)->setPos((*iter)->getPosX() - backgroundDiff, (*iter)->getPosY());
		if ((*iter)->getPosX() < -SCREEN_WIDTH) { // 여기서 10은 조절해도댐
			SAFE_DELETE(*iter);
			iter = bridgeList.erase(iter);

			Sprite* tempBridge = new Sprite("Resources/Sprites/LoopMap.png");
			tempBridge->setPos(SCREEN_WIDTH, 560);
			bridgeList.push_back(tempBridge);

			if (iter == bridgeList.end()) {
				break;
			}
		}
	}
	for (auto iter = coinList.begin(); iter != coinList.end(); iter++) {
		(*iter)->setPos((*iter)->getPosX() - backgroundDiff, (*iter)->getPosY());
		if ((*iter)->getPosX() < -SCREEN_WIDTH) { // 여기서 10은 조절해도댐
			SAFE_DELETE(*iter);
			iter = coinList.erase(iter);
			if (iter == coinList.end()) {
				break;
			}
		}
	}
	for (auto iter = coinList.begin(); iter != coinList.end(); iter++) {
		if (player->IsCollisionRect(*iter)) {
			score++;
			SAFE_DELETE(*iter);
			iter = coinList.erase(iter);
			if (iter == coinList.end()) {
				break;
			}
		}
	}

	for (auto iter = obstacleList.begin(); iter != obstacleList.end(); iter++) {
		(*iter)->setPos((*iter)->getPosX() - backgroundDiff, (*iter)->getPosY());
		if (player->IsCollisionRect(*iter)) {
			sceneManager->ChangeScene(new MainScene());
			return;
		}
		if ((*iter)->getPosX() < -SCREEN_WIDTH) { // 여기서 10은 조절해도댐
			SAFE_DELETE(*iter);
			iter = obstacleList.erase(iter);

			Sprite* tmpObstacle = new Sprite("Resources/Sprites/Drop.png");
			tmpObstacle->setPos(SCREEN_WIDTH, 500);
			obstacleList.push_back(tmpObstacle);
			if (iter == obstacleList.end()) {
				break;
			}
		}
	}
	*/

}
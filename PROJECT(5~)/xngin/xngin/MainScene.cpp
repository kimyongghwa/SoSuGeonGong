#include "stdafx.h"
#include "MainScene.h"
MainScene::MainScene() {
	explainButton = nullptr;
	background = new Sprite("Resources/Sprites/Background.png");
	AddObject(background);
	background->setPos(0, 0);

	title = new Sprite("Resources/Sprites/joonsim.png");
	AddObject(title);
	title->setPos(500, 30);

	startButton = new Sprite("Resources/Sprites/start.png");

	AddObject(startButton);
	//startButton->setCenter(300, 120, startButton);
	startButton->setPos(0, 250);

	exitButton = new Sprite("Resources/Sprites/exit.png");
	AddObject(exitButton);
	exitButton->setPos(0, 500);
}
MainScene::~MainScene() {
	// AddObject�� �߰��� ������Ʈ���� �ڵ����� �����
	// ���� AddObject �Ⱦ��� SAFE_DELETE(background)
}
void MainScene::Render() {
	background->Render();
	title->Render();
	startButton->Render();
	exitButton->Render();
}
void MainScene::Update(float dTime) {
	Scene::Update(dTime);
	if (inputManager->GetKeyState(VK_LBUTTON) == KEY_DOWN) {
		if (exitButton->IsPointInRect(inputManager->GetMousePos())) {
			PostQuitMessage(0);
			return;
		}
		if (startButton->IsPointInRect(inputManager->GetMousePos())) {
			sceneManager->ChangeScene(new GameScene());
			return;
		}
	}
}

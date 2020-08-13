#include "stdafx.h"
#include "MainScene.h"

MainScene::MainScene() {
	background = new Sprite("Resurces/Images/BG.png");
	AddObject(background);
	background->setPos(0, 0);
}

MainScene::~MainScene() {
	//SAFE_DELETE(background);         addObject 했으면 안해도돔
}
void MainScene::Render() {
	background->Render();
}
void MainScene::Update(float  dTime) {
	Scene::Update(dTime);
}
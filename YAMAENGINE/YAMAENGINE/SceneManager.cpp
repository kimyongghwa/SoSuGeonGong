#include "stdafx.h"
#include "SceneManager.h"

SceneManager::SceneManager() {
	currentScene = nullptr;
}

SceneManager::~SceneManager() {
	
}

void SceneManager::Render() {

}

void SceneManager::Update(float dTime) {

}

void SceneManager::ChangeScene(Scene* scene) {
	SAFE_DELETE(currentScene);
	currentScene = scene;
}

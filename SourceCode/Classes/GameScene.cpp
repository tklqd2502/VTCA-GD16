#include "GameScene.h"
#include "GamePlayLayer.h"
#include "BackgroundLayer.h"

USING_NS_CC;
GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

Scene * GameScene::createGameScene()
{
	Scene* scene = Scene::createWithPhysics();
	PhysicsWorld* world = scene->getPhysicsWorld();
	// remember to turn off debug when release
	world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	GameScene* node = GameScene::create();
	scene->addChild(node);
	return scene;
}

bool GameScene::init()
{
	if (!Node::init())
	{
		return false;
	}
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("image/game_image.plist",
		"image/game_image.png");

	BackgroundLayer* backgroundLayer = BackgroundLayer::create();
	this->addChild(backgroundLayer);

	GamePlayLayer* gamePlayLayer = GamePlayLayer::create();
	this->addChild(gamePlayLayer);

	return true;
}
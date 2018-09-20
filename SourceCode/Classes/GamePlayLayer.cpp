#include "GamePlayLayer.h"
#include "Bird.h"
#include "Pipe.h"
#include "GameConst.h"

USING_NS_CC;
GamePlayLayer::GamePlayLayer()
{
}

GamePlayLayer::~GamePlayLayer()
{
}

bool GamePlayLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size winSize = Director::getInstance()->getWinSize();
	//
	_bird = Bird::create();
	this->addChild(_bird);
	_bird->setPosition(winSize * 0.5f);
	_bird->playFlyAnimation();

	//
	Pipe* pipe = Pipe::create();
	this->addChild(pipe);
	pipe->setPosition(winSize.width * 0.5f, 0.0f);

	EventListenerKeyboard* listenerKeyboard = EventListenerKeyboard::create();
	listenerKeyboard->onKeyPressed = CC_CALLBACK_2(GamePlayLayer::onKeyPressed, this);
	listenerKeyboard->onKeyReleased = CC_CALLBACK_2(GamePlayLayer::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyboard, this);

	EventListenerPhysicsContact* listenerPhysics = EventListenerPhysicsContact::create();
	listenerPhysics->onContactBegin = CC_CALLBACK_1(GamePlayLayer::onGameContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerPhysics, this);
	return true;
}

void GamePlayLayer::onKeyPressed(cocos2d::EventKeyboard::KeyCode kc, cocos2d::Event * e)
{
	if (kc == EventKeyboard::KeyCode::KEY_SPACE)
	{
		// Jump
		cocos2d::log("Pressed Jump");
		_bird->jump();
	}
}

void GamePlayLayer::onKeyRelease(cocos2d::EventKeyboard::KeyCode kc, cocos2d::Event * e)
{
}

bool GamePlayLayer::onGameContactBegin(PhysicsContact& contact)
{
	PhysicsShape* shapeA = contact.getShapeA();
	PhysicsShape* shapeB = contact.getShapeB();
	Node* nodeA = shapeA->getBody()->getOwner();
	Node* nodeB = shapeB->getBody()->getOwner();

	Bird* bird = nullptr;
	if (nodeA->getTag() == TAG_BIRD) // A la chim
	{
		bird = static_cast<Bird*>(nodeA);
	}
	else if (nodeB->getTag() == TAG_BIRD) // B la chim
	{
		bird = static_cast<Bird*>(nodeB);
	}
	if (bird != nullptr)
	{
		bird->setVisible(false);
	}
	return true;
}

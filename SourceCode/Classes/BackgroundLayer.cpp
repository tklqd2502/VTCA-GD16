#include "BackgroundLayer.h"
USING_NS_CC;
BackgroundLayer::BackgroundLayer()
{
}

BackgroundLayer::~BackgroundLayer()
{
}

bool BackgroundLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size winSize = Director::getInstance()->getWinSize();
	_sprBG = Sprite::create("image/background-day.png");
	_sprBG->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->addChild(_sprBG);
	_sprBG->setPosition(winSize * 0.5f);
	float scaleX = winSize.width / _sprBG->getContentSize().width;
	float scaleY = winSize.height / _sprBG->getContentSize().height;
	_sprBG->setScaleX(scaleX);
	_sprBG->setScaleY(scaleY);

	MoveBy* moveBy = MoveBy::create(1.0f, Vec2(-100.0f, 0.0f));
	_sprBG->runAction(RepeatForever::create(moveBy));

	scheduleUpdate();
	return true;
}

void BackgroundLayer::update(float delta)
{
	cocos2d::log("Calling Update");
}

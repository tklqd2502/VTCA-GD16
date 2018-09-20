#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "MenuScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("image/game_image.plist",
		"image/game_image.png");

	//Sprite* bgSpr = Sprite::createWithSpriteFrameName("background-day.png");
	//this->addChild(bgSpr);
	////bgSpr->setAnchorPoint(Vec2(0.5f, 0.5f)); // cach 1
	//bgSpr->setAnchorPoint(Vec2::ANCHOR_MIDDLE); // cach 2
	//bgSpr->setPosition(Vec2(visibleSize * 0.3f, visibleSize * 0.5f));

	//Sprite* spr = Sprite::createWithSpriteFrameName("bluebird_0.png");
	//bgSpr->addChild(spr);
	//spr->setPosition(Vec2(bgSpr->getContentSize() * 0.5f));
	/*Sprite* bgSpr = Sprite::create("image/background-day.png", Rect(0, 312, 200, 200));
	this->addChild(bgSpr);
	bgSpr->setPosition(visibleSize * 0.5f);*/

	// Generate polygon info automatically.
	//auto pinfo = AutoPolygon::generatePolygon("image/bluebird_0.png");
	//// Create a sprite with polygon info.
	//auto sprite = Sprite::create(pinfo);
	//this->addChild(sprite);
	//sprite->setPosition(visibleSize * 0.5f);

	auto spr = Sprite::create("image/bluebird_00.png");
	this->addChild(spr);
	spr->setPosition(Vec2(200.0f, 300.0f));

	Animation* animation = Animation::create();
	for (int i = 0; i < 3; i++)
	{
		std::string name = StringUtils::format("bluebird_%02d.png", i);
		animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(name));
	}
	animation->setDelayPerUnit(1 / 12.0f);

	Animate* animate = Animate::create(animation);
	spr->runAction(RepeatForever::create(animate));

	EventListenerKeyboard* listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode kc, cocos2d::Event* e)
	{
		if (kc == cocos2d::EventKeyboard::KeyCode::KEY_K)
		{
			Director::getInstance()->replaceScene(MenuScene::create());
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    //Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

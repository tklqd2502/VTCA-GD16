#include "MenuScene.h"
USING_NS_CC;
using namespace cocos2d::ui;

MenuScene::MenuScene()
{
}

MenuScene::~MenuScene()
{
}

bool MenuScene::init()
{
	if (Scene::init() == false)
	{
		return false;
	}
	Size winSize = Director::getInstance()->getWinSize();

	Sprite* spr = Sprite::create("image/background-day.png");
	this->addChild(spr);
	spr->setPosition(winSize * 0.5f);

	// *** LABEL ***
	//Label* lbSystemFont = Label::createWithSystemFont("This is system font", "Arial", 30);
	//this->addChild(lbSystemFont);
	//lbSystemFont->setPosition(Vec2(winSize.width * 0.5f, winSize.height * 0.8f));

	//Label* lbTTF = Label::createWithTTF("This is TTF font 1", "fonts/Oswald-Regular.ttf", 30);
	//this->addChild(lbTTF);
	//lbTTF->setPosition(Vec2(winSize.width * 0.5f, winSize.height * 0.5f));
	//lbTTF->enableOutline(Color4B::ORANGE, 2);

	//Label* lbTTF2 = Label::createWithTTF("This is TTF font 2", "fonts/Oswald-Regular.ttf", 30);
	//this->addChild(lbTTF2);
	//lbTTF2->setPosition(Vec2(winSize.width * 0.5f, winSize.height * 0.3f));
	//lbTTF2->enableShadow(Color4B::BLUE);

	// *** BUTTO ***
	_btnPlay = Button::create("image/button_blue.png", "image/button_red.png", "image/button_yellow.png", Widget::TextureResType::LOCAL);
	this->addChild(_btnPlay);
	_btnPlay->setPosition(winSize * 0.5f);

	_textPlay = Text::create("PLAY", "fonts/Oswald-Regular.ttf", 30);
	_btnPlay->addChild(_textPlay);
	_textPlay->setPosition(_btnPlay->getContentSize() * 0.5f);
	// cach 1 su dung lambda, nen dung khi xu ly ngan gon
	/*btnPlay->addTouchEventListener([=](cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			_textPlay->setString("BEGAN");
			cocos2d::log("BEGAN");
			break;
		case cocos2d::ui::Widget::TouchEventType::MOVED:
			_textPlay->setString("MOVED");
			cocos2d::log("MOVED");
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			_textPlay->setString("ENDED");
			cocos2d::log("ENDED");
			break;
		case cocos2d::ui::Widget::TouchEventType::CANCELED:
			_textPlay->setString("CANCELED");
			cocos2d::log("CANCELED");
			break;
		default:
			break;
		}
	});*/

	// cach 2 su dung callback, nen dung khi xu ly nhieu
	_btnPlay->addTouchEventListener(CC_CALLBACK_2(MenuScene::onTouchBtnPlay, this));


	auto loadingBar = LoadingBar::create("image/button_yellow.png");
	// set the direction of the loading bars progress
	this->addChild(loadingBar);
	loadingBar->setDirection(LoadingBar::Direction::LEFT);
	loadingBar->setPosition(Vec2(winSize.width * 0.3f, winSize.height * 0.6f));

	Text* clickableText = Text::create("PLAY", "fonts/Oswald-Regular.ttf", 30);
	this->addChild(clickableText);
	clickableText->setPosition(Vec2(winSize.width * 0.5f, winSize.height * 0.3f));
	clickableText->setTouchEnabled(true);
	clickableText->addTouchEventListener([=](cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
	{
		if (type == Widget::TouchEventType::ENDED)
		{
			clickableText->setString("CLICKED");
			loadingBar->setPercent(50.0f);
		}
		else
		{
			clickableText->setString("PLAY");
			loadingBar->setPercent(20.0f);
		}
	});

	
	return true;
}

void MenuScene::onTouchBtnPlay(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
	switch (type)
	{
	case cocos2d::ui::Widget::TouchEventType::BEGAN:
		_textPlay->setString("BEGAN");
		cocos2d::log("BEGAN");
		break;
	case cocos2d::ui::Widget::TouchEventType::MOVED:
		_textPlay->setString("MOVED");
		cocos2d::log("MOVED");
		break;
	case cocos2d::ui::Widget::TouchEventType::ENDED:
		_textPlay->setString("ENDED");
		cocos2d::log("ENDED");
		break;
	case cocos2d::ui::Widget::TouchEventType::CANCELED:
		_textPlay->setString("CANCELED");
		cocos2d::log("CANCELED");
		break;
	default:
		break;
	}
}
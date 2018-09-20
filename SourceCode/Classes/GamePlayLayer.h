#ifndef _GAME_PLAY_LAYER
#define _GAME_PLAY_LAYER

#include "cocos2d.h"
class Bird;
class GamePlayLayer : public cocos2d::Layer
{
public:
	GamePlayLayer();
	~GamePlayLayer();

	CREATE_FUNC(GamePlayLayer);
	virtual bool init();

protected:
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode kc, cocos2d::Event* e);
	void onKeyRelease(cocos2d::EventKeyboard::KeyCode kc, cocos2d::Event* e);
private:
	Bird* _bird;
private:
	bool onGameContactBegin(cocos2d::PhysicsContact& contact);
};


#endif // !_GAME_PLAY_LAYER

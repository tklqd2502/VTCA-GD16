#ifndef _BIRD_H_
#define _BIRD_H_

#include "cocos2d.h"

class Bird : public cocos2d::Node
{
public:
	Bird();
	~Bird();
	CREATE_FUNC(Bird);
	virtual bool init();
	void playFlyAnimation();
	void jump();
private:
	cocos2d::Sprite* _sprBird;
};

#endif // !_BIRD_H_

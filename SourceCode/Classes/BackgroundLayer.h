#ifndef _BACKGROUND_LAYER_H
#define _BACKGROUND_LAYER_H
#include "cocos2d.h"
class BackgroundLayer : public cocos2d::Layer
{
public:
	BackgroundLayer();
	~BackgroundLayer();
	CREATE_FUNC(BackgroundLayer);
	virtual bool init();
private:
	void update(float delta);
private:
	cocos2d::Sprite* _sprBG;
};


#endif // !_BACKGROUND_LAYER_H

#ifndef _GAME_SCENE_H
#define _GAME_SCENE_H

#include "cocos2d.h"

class GameScene : public cocos2d::Node
{
public:
	GameScene();
	~GameScene();
	static cocos2d::Scene* createGameScene();

	CREATE_FUNC(GameScene);
	virtual bool init();
private:

};


#endif // !_GAME_SCENE_H

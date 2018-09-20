#ifndef _MENU_SCENE_H
#define _MENU_SCENE_H

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class MenuScene : public cocos2d::Scene
{
public:
	MenuScene();
	~MenuScene();

	CREATE_FUNC(MenuScene);
	virtual bool init();

	void onTouchBtnPlay(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
private:
	cocos2d::ui::Button*	_btnPlay;
	cocos2d::ui::Text*		_textPlay;
};

#endif // !_MENU_SCENE_H

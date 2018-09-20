#ifndef _PIPE_H_
#define _PIPE_H_

#include "cocos2d.h"
#include "GamePlayLayer.h"

class Pipe : public cocos2d::Node
{
public:
	Pipe();
	~Pipe();
	CREATE_FUNC(Pipe);
	virtual bool init();
private:
};

#endif // !_PIPE_H_

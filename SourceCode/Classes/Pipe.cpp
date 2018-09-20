#include "Pipe.h"
#include "GameConst.h"
USING_NS_CC;
Pipe::Pipe()
{
}

Pipe::~Pipe()
{
}

bool Pipe::init()
{
	if (!Node::init())
	{
		return false;
	}
	PhysicsBody* physicsBody = PhysicsBody::createCircle(40,
		PhysicsMaterial(0.1f, 1.0f, 0.0f));
	physicsBody->setDynamic(false);
	physicsBody->setCategoryBitmask(PIPE_CATEGORY_BITMASK); // 0010
	physicsBody->setCollisionBitmask(PIPE_COLLISION_AND_CONTACT_TEST_BITMASK); // 0001
	physicsBody->setContactTestBitmask(PIPE_COLLISION_AND_CONTACT_TEST_BITMASK);
	this->setPhysicsBody(physicsBody);
	return true;
}

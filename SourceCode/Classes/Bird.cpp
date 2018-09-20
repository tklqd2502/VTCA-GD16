#include "Bird.h"
#include "GameConst.h"
USING_NS_CC;
Bird::Bird()
{
}

Bird::~Bird()
{
}

bool Bird::init()
{
	if (!Node::init())
	{
		return false;
	}

	_sprBird = Sprite::create("image/bluebird_00.png");
	this->addChild(_sprBird);
	_sprBird->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->setContentSize(_sprBird->getContentSize());
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	_sprBird->setPosition(this->getContentSize() * 0.5f);
	this->setScale(2.0f);

	PhysicsBody* physicsBody = PhysicsBody::createBox(_sprBird->getContentSize(),
		PhysicsMaterial(0.1f, 0.5f, 0.0f));
	physicsBody->setDynamic(true);
	physicsBody->setCategoryBitmask(BIRD_CATEGORY_BITMASK); // 0001
	physicsBody->setCollisionBitmask(BIRD_COLLISION_AND_CONTACT_TEST_BITMASK); // 0010
	physicsBody->setContactTestBitmask(BIRD_COLLISION_AND_CONTACT_TEST_BITMASK);
	//apply physicsBody to the sprite
	this->addComponent(physicsBody);

	this->setTag(TAG_BIRD);
	return true;
}

void Bird::playFlyAnimation()
{
	Animation* animation = Animation::create();
	for (int i = 0; i < 3; i++)
	{
		std::string name = StringUtils::format("bluebird_%02d.png", i);
		animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(name));
	}
	animation->setDelayPerUnit(1 / 12.0f);

	Animate* animate = Animate::create(animation);
	_sprBird->runAction(RepeatForever::create(animate));
}

void Bird::jump()
{
	JumpBy* jumpAction = JumpBy::create(1.0f, Vec2(0.0f, 45.0f), 20, 3);
	this->runAction(jumpAction);
}

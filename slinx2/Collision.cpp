#include <irrlicht.h>
#include "Collision.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

Collision::Collision(ISceneNode* one, ISceneNode* two)
{
	this->one = one;
	this->two = two;
}


Collision::~Collision()
{
}

bool Collision::checkCollision(ISceneNode* one, ISceneNode* two) {
	aabbox3d<f32> b1, b2;

	b1 = one->getBoundingBox();
	b2 = two->getBoundingBox();

	one->getRelativeTransformation().transformBoxEx(b1);
	two->getRelativeTransformation().transformBoxEx(b2);
	return b1.intersectsWithBox(b2);
}

ISceneNode* Collision::node()
{
	return this->one;
}

ISceneNode* Collision::node2()
{
	return this->two;
}
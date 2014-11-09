#pragma once
#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Collision
{
public:
	Collision(ISceneNode* one, ISceneNode* two);
	bool checkCollision(ISceneNode* one, ISceneNode* two);
	~Collision();

	ISceneNode* node();
	ISceneNode* node2();
private:
	ISceneNode* one;
	ISceneNode* two;
};


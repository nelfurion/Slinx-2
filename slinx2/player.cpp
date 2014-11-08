#include "headers\Player.h"
#include <irrlicht.h>
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

Player::Player(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
Player::~Player() { }

bool Player::load(IVideoDriver* driver, ISceneManager* smgr, float x, float y, float z)
{
	float terrainHeight = 24;
	IAnimatedMesh* oMesh = smgr->getMesh("media/sydney.md2");
	if (!oMesh)
	{
		//deletes device if ^ failed
		return false;
	}
	IAnimatedMeshSceneNode* mNode = smgr->addAnimatedMeshSceneNode(oMesh);

	if (mNode)
	{
		mNode->setMaterialFlag(EMF_LIGHTING, false);
		mNode->setMD2Animation(scene::EMAT_STAND);
		mNode->setMaterialTexture(0, driver->getTexture("media/sydney.bmp"));
		mNode->setPosition(core::vector3df(x, y, z));
	}
	return true;
}
float Player::X()
{
	return this->x;
}
float Player::Y()
{
	return this->y;
}
float Player::Z()
{
	return this->z;
}
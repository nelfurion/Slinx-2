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
<<<<<<< HEAD
	this->oMesh = smgr->getMesh("models/player1.md3");
=======
	IAnimatedMesh* oMesh = smgr->getMesh("models/player1.md3");
>>>>>>> origin/master
	if (!oMesh)
	{
		//deletes device if ^ failed
		return false;
	}
	this->mNode = smgr->addAnimatedMeshSceneNode(oMesh);

	if (mNode)
	{
		mNode->setMaterialFlag(EMF_LIGHTING, false);
		mNode->setMD2Animation(scene::EMAT_STAND);
		mNode->setMaterialTexture(0, driver->getTexture("media/player1skin.jpg"));
		mNode->setPosition(core::vector3df(x, y, z));
		mNode->setDebugDataVisible(scene::EDS_BBOX);
	}
	return true;
}
void Player::run(IVideoDriver* driver, ISceneManager* smgr)
{
	this->oMesh = smgr->getMesh("models/player1.md3");
}
void Player::stand(IVideoDriver* driver, ISceneManager* smgr)
{
	this->oMesh = smgr->getMesh("media/sydney.md2");
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
IAnimatedMeshSceneNode* Player::Node()
{
	return this->mNode;
}

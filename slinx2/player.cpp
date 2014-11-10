#include "headers\Player.h"
#include <irrlicht.h>
#include <string>
#include <iostream>
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
	this->oMesh = smgr->getMesh("media/sydney.md2");
	if (!oMesh)
	{
		//deletes device if ^ failed
		return false;
	}
	this->modPath = "media/sydney.md2";
	this->mNode = smgr->addAnimatedMeshSceneNode(oMesh);

	if (this->mNode)
	{
		this->mNode->setMaterialFlag(EMF_LIGHTING, false);
		this->mNode->setMD2Animation(scene::EMAT_STAND);
		this->mNode->setMaterialTexture(0, driver->getTexture("media/sydney.bmp"));
		this->mNode->setPosition(core::vector3df(x, y, z));
	}
	return true;
}
bool Player::run(IVideoDriver* driver, ISceneManager* smgr)
{
	this->oMesh = smgr->getMesh("models/player1.md3");
	if (!oMesh)
	{
		//deletes device if ^ failed
		return false;
	}
	this->modPath = "models/player1.md3";
	this->mNode->setMesh(this->oMesh);
	if (this->mNode)
	{
		this->mNode->setMaterialFlag(EMF_LIGHTING, false);
		this->mNode->setMD2Animation(scene::EMAT_STAND);
		this->mNode->setMaterialTexture(0, driver->getTexture("media/sydney.bmp"));
		this->mNode->setPosition(core::vector3df(x, y, z));
	}
	return true;
}
bool Player::stand(IVideoDriver* driver, ISceneManager* smgr)
{
	this->oMesh = smgr->getMesh("models/staticvoidplayer.obj");
	if (!oMesh)
	{
		//deletes device if ^ failed

		return false;
	}
	this->modPath = "models/staticvoidplayer.obj";
	this->mNode->setMesh(this->oMesh);
	if (this->mNode)
	{
		this->mNode->setMaterialFlag(EMF_LIGHTING, false);
		this->mNode->setMD2Animation(scene::EMAT_STAND);
		this->mNode->setMaterialTexture(0, driver->getTexture("media/sydney.bmp"));
		this->mNode->setPosition(core::vector3df(x, y, z));
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
IAnimatedMeshSceneNode* Player::Node()
{
	return this->mNode;
}
std::string Player::ModPath()
{
	return this->modPath;
}
void Player::setCamera(ISceneManager* smgr)
{
	ICameraSceneNode *pCamera = smgr->addCameraSceneNodeFPS();
	/*vector3df mPosition = this->Node()->getAbsolutePosition();
	this->head = this->Node();
	this->head->setPosition(vector3df(mPosition.X, mPosition.Y, mPosition.Z));
	std::cout << head->getAbsolutePosition().X << std::endl;
	pCamera->setParent(this->head);*/
}
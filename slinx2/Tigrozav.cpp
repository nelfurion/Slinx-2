#include <irrlicht.h>
#include "headers\Tigrozav.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

Tigrozav::Tigrozav(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
Tigrozav::~Tigrozav() { }

bool Tigrozav::load(IVideoDriver* driver, ISceneManager* smgr, float x, float y, float z)
{
	float terrainHeight = 24;
	IAnimatedMesh* oMesh = smgr->getMesh("models/player1.md3");
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
		mNode->setPosition(core::vector3df(x, y, z));
	}
	return true;
}
float Tigrozav::X()
{
	return this->x;
}
float Tigrozav::Y()
{
	return this->y;
}
float Tigrozav::Z()
{
	return this->z;
}
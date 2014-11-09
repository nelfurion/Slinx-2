#ifndef Camera_H
#define Camera_H
#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Camera
{
public:
	static void setCamera(ISceneManager* smgr, float x, float y, float z)
	{
		ICameraSceneNode *cam = smgr->addCameraSceneNode(0, vector3df(x - 10, y + 100, z - 50), vector3df(0, 0, 0));
	}
	static void updateCamera(ICameraSceneNode *cam, float x, float y, float z)
	{
		cam->setPosition(vector3df(x, y, z));
	}
};
#endif Camera_H
#include <irrlicht.h>
#include <iostream>
#include <vector>
#include "headers\Player.h"
#include "headers\Tigrozav.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
int terrainHeight = 24;
int main()
{

	//this is how we create a window with the openGL driver, with a certain resolution, color per bits and other stuff
	irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_OPENGL, dimension2d<u32>(640, 480), 32,
		false, false, false, 0);

	if (!device)
		return 1;
	//name of the window
	device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");
	//pointers to the stuff
	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();
	//this adds 2D text
	guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",
		rect<s32>(10, 10, 260, 22), true);
	//DELETE HERE
	IAnimatedMesh* wMesh = smgr->getMesh("models/map.obj");
	if (!wMesh)
	{
		//deletes device if ^ failed
		device->drop();
		return 1;
	}
	ISceneNode* wNode = smgr->addAnimatedMeshSceneNode(wMesh);
	if (wNode)
	{
		wNode->setMaterialFlag(EMF_LIGHTING, false);
		//wNode->setMD2Animation(scene::EMAT_STAND);
		wNode->setMaterialTexture(0, driver->getTexture("media/detailmap3.jpg"));
		wNode->setPosition(core::vector3df(0, 0, 0));
	}
	//Player pesho(0, terrainHeight, 0);
	//if (!pesho.load(driver, smgr, pesho.X(), pesho.Y(), pesho.Z()))
	//{
	//	printf("Player failed to load!");
	//	return -1;
	//}

	Tigrozav alpha(0, terrainHeight, 0);
	if (!alpha.load(driver, smgr, alpha.X(), alpha.Y(), alpha.Z()))
	{
		printf("Tigrozavur failed to load!");
		return -1;
	}

	//creates an animation from the mesh
	smgr->addCameraSceneNodeFPS();
	//hide mouse cursor
	device->getCursorControl()->setVisible(false);
	int lastFPS = -1;
	//main loop
	int i = -32000;
	while (device->run())
	{
		if (device->isWindowActive())
		{
			driver->beginScene(true, true, video::SColor(255, 200, 200, 200));

			smgr->drawAll();
			//guienv->drawAll();

			driver->endScene();
			int fps = driver->getFPS();

			if (lastFPS != fps)
			{
				core::stringw str = L"Irrlicht Engine - Quake 3 Map example [";
				str += driver->getName();
				str += "] FPS:";
				str += fps;

				device->setWindowCaption(str.c_str());
				lastFPS = fps;
			}
			else
				device->yield();
		}
		std::cout << i << std::endl;
		i++;
	}
	device->drop();

	std::cin;
	return 0;
}
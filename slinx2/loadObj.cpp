#include <irrlicht.h>
#include <driverChoice.h>
#include <iostream>
#include <vector>
#include "headers\EventReceiver.h"
#include "headers\Tigrozav.h"
#include "headers\Player.h"
#include "headers\Camera.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
int terrainHeight = 24;
int main()
{
	MyEventReceiver receiver;
	//this is how we create a window with the openGL driver, with a certain resolution, color per bits and other stuff
	irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_OPENGL, dimension2d<u32>(640, 480), 32,
		false, false, false, &receiver);

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
		wNode->setMaterialTexture(0, driver->getTexture("models/grass.jpg"));
		wNode->setPosition(core::vector3df(0, 0, 0));
	}
	Player player(0, terrainHeight, 0);
	if (!player.load(driver, smgr, player.X(), player.Y(), player.Z()))
	{
		printf("Player failed to load!");
		return -1;
	}
	player.setCamera(smgr);

	Tigrozav tigur(10, terrainHeight, 10);
	if (!tigur.load(driver, smgr, tigur.X(), tigur.Y(), tigur.Z()))
	{
		printf("Tigrozavur failed to load");
		return -1;
	}

	IAnimatedMeshSceneNode* tNode;
	IAnimatedMesh* tMesh = smgr->getMesh("models/rgbforest.obj");;
	tNode = smgr->addAnimatedMeshSceneNode(tMesh);
	if (tNode)
	{
		tNode->setMaterialFlag(EMF_LIGHTING, false);
		tNode->setMD2Animation(scene::EMAT_STAND);
		//tNode->setMaterialTexture(0, driver->getTexture("media/sydney.bmp"));
		tNode->setPosition(core::vector3df(30,30,30));
	}
	/*vector3df camPos = player.Node()->getAbsolutePosition();
	Camera::setCamera(smgr, camPos.X, camPos.Y, camPos.Z);*/
	
	//hide mouse cursor
	device->getCursorControl()->setVisible(false);
	device->getGUIEnvironment()->addImage(
		driver->getTexture("media/irrlichtlogoalpha2.tga"),
		core::position2d<s32>(10, 20));

	gui::IGUIStaticText* diagnostics = device->getGUIEnvironment()->addStaticText(
		L"", core::rect<s32>(10, 10, 400, 20));
	diagnostics->setOverrideColor(video::SColor(255, 255, 255, 0));
	int lastFPS = -1;

	// In order to do framerate independent movement, we have to know
	// how long it was since the last frame
	u32 then = device->getTimer()->getTime();
	// This is the movemen speed in units per second.
	const f32 MOVEMENT_SPEED = 50.f;
	//main loop
	
	bool wsUp;
	bool adUp;
	while (device->run())
	{
		// Work out a frame delta time.
		const u32 now = device->getTimer()->getTime();
		const f32 frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds
		then = now;
		if (device->isWindowActive())
		{
			wsUp = false;
			adUp = false;
			core::vector3df nodePosition = player.Node()->getPosition();

			if (receiver.IsKeyDown(irr::KEY_KEY_W))
				nodePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;
			else if (receiver.IsKeyDown(irr::KEY_KEY_S))
				nodePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
			else
				wsUp = true;
			if (receiver.IsKeyDown(irr::KEY_KEY_A))
				nodePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
			else if (receiver.IsKeyDown(irr::KEY_KEY_D))
				nodePosition.X += MOVEMENT_SPEED * frameDeltaTime;
			else
				adUp = true;
			if (wsUp && adUp)
			{
				if (player.ModPath() != "models/staticvoidplayer.obj")
				{
					if (!player.stand(driver, smgr))
					{
						printf("Failed to load player standing animation.");
						return -1;
					}
				}
			}
			else
			{
				if (player.ModPath() != "models/player1.md3")
				{
					if (!player.run(driver, smgr))
					{
						printf("Failed to load player running animation.");
						return -1;
					}
				}
			}

			player.Node()->setPosition(nodePosition);

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
		}
		else
		{
			device->yield();
		}
	}
	device->drop();

	std::cin;
	return 0;
}


void moveCamera()
{

}
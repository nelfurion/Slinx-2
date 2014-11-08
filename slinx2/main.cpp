//#include <irrlicht.h>
//#include <iostream>
//using namespace irr;
//using namespace core;
//using namespace scene;
//using namespace video;
//using namespace io;
//using namespace gui;
//
//int main()
//{
//	//this is how we create a window with the openGL driver, with a certain resolution, color per bits and other stuff
//	irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_OPENGL, dimension2d<u32>(640, 480), 16,
//		false, false, false, 0);
//
//	if (!device)
//		return 1;
//	//name of the window
//	device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");
//	//pointers to the stuff
//	IVideoDriver* driver = device->getVideoDriver();
//	ISceneManager* smgr = device->getSceneManager();
//	IGUIEnvironment* guienv = device->getGUIEnvironment();
//	//this adds 2D text
//	guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",
//		rect<s32>(10, 10, 260, 22), true);
//
//	//creates an animation from the mesh
//	IAnimatedMesh* oMesh = smgr->getMesh("media/sydney.md2");
//	if (!oMesh)
//	{
//		//deletes device if ^ failed
//		device->drop();
//		return 1;
//	}
//	IAnimatedMeshSceneNode* mNode = smgr->addAnimatedMeshSceneNode(oMesh);
//
//	if (mNode)
//	{
//		mNode->setMaterialFlag(EMF_LIGHTING, false);
//		mNode->setMD2Animation(scene::EMAT_STAND);
//		mNode->setMaterialTexture(0, driver->getTexture("media/sydney.bmp"));
//	}
//	//we load the Quake 3 map
//	device->getFileSystem()->addFileArchive("media/map-20kdm2.pk3");
//	//sets the camera
//	smgr->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));
//	scene::IAnimatedMesh* mesh = smgr->getMesh("20kdm2.bsp");
//	scene::ISceneNode* node = 0;
//
//	if (mesh)
//		node = smgr->addOctreeSceneNode(mesh->getMesh(0), 0, -1, 1024);
//	//      node = smgr->addMeshSceneNode(mesh->getMesh(0));
//	//set coordinates of the map
//	if (mNode)
//		mNode->setPosition(core::vector3df(-1300, -144, -1249));
//	//create fps camera
//	smgr->addCameraSceneNodeFPS();
//	//hide mouse cursor
//	device->getCursorControl()->setVisible(false);
//	int lastFPS = -1;
//	//main loop
//	while (device->run())
//	{
//		if (device->isWindowActive())
//		{
//			driver->beginScene(true, true, video::SColor(255, 200, 200, 200));
//
//			smgr->drawAll();
//			//guienv->drawAll();
//
//			driver->endScene();
//			int fps = driver->getFPS();
//
//			if (lastFPS != fps)
//			{
//				core::stringw str = L"Irrlicht Engine - Quake 3 Map example [";
//				str += driver->getName();
//				str += "] FPS:";
//				str += fps;
//
//				device->setWindowCaption(str.c_str());
//				lastFPS = fps;
//			}
//			else
//				device->yield();
//		}
//		
//	}
//	device->drop();
//
//	std::cin;
//	return 0;
//}
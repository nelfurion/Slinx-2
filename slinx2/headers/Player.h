#ifndef Player_H
#define Player_H
#include <irrlicht.h>
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
class Player 
{
	public:
		Player(float x, float y, float z);
		~Player();
		bool load(IVideoDriver* driver, ISceneManager* smgr, float x, float y, float z);
		float X();
		float Y();
		float Z();
		void run(IVideoDriver* driver, ISceneManager* smgr);
		void stand(IVideoDriver* driver, ISceneManager* smgr);
		IAnimatedMeshSceneNode* Node();
	private:
		float x;
		float y;
		float z;
		IAnimatedMeshSceneNode* mNode;
		IAnimatedMesh* oMesh;
};
#endif Player_H
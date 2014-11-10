#ifndef Player_H
#define Player_H
#include <irrlicht.h>
#include <string>
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
		std::string ModPath();
		bool run(IVideoDriver* driver, ISceneManager* smgr);
		bool stand(IVideoDriver* driver, ISceneManager* smgr);
		IAnimatedMeshSceneNode* Node();
		void setCamera(ISceneManager* smgr);
	private:
		float x;
		float y;
		float z;
		IAnimatedMeshSceneNode* mNode;
		IAnimatedMesh* oMesh;
		IAnimatedMeshSceneNode* head;
		
		std::string modPath;
};
#endif Player_H
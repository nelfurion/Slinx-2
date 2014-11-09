#ifndef Tigrozav_H
#define Tigrozav_H
#include <irrlicht.h>
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
class Tigrozav
{
public:
	Tigrozav(float x, float y, float z);
	bool load(IVideoDriver* driver, ISceneManager* smgr, float x, float y, float z);
	~Tigrozav();

	float X();
	float Y();
	float Z();
private:
	float x;
	float y;
	float z;

};
#endif Tigrozav_H
#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
public:
	Entity();
	Entity(int coordX, int coordY, int sizeX, int sizeY, int sizeZ);
	~Entity();

	//fields
	virtual int CoordX();
	virtual int CoordY();
	virtual int SizeX();
	virtual int SizeY();
	virtual int SizeZ();
	/*Here are the member functions that are not here. */
	/*virtual int ASD();
	virtual int setCoordX();
	virtual int setCoordY();
	virtual int setSizeX();
	virtual int setSizeY();
	virtual int setSizeZ();*/
	//methods
	/*
	 * void drawSelf(appearance)
	 * { TODO }
	 */
private:
int coordX, coordY;
int sizeX, sizeY, sizeZ;
/*
 * TODO: object sth appearance
 */

};

#endif // ENTITY_H

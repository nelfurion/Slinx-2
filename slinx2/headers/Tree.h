#ifndef TREE_H
#define TREE_H

#include "Entity.h" // Base class: Entity

class Tree : public Entity
{
public:
	Tree(float x, float y, float z);
	~Tree();
private:
	float x;
	float y;
	float z;
};

#endif // TREE_H

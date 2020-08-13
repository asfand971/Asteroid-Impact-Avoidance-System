//NEO Management system
#include "AHeap.h"
class ATnode
{
public:
	Asteroids data;
	ATnode* left, * right;
	ATnode();
	ATnode(Asteroids);
};


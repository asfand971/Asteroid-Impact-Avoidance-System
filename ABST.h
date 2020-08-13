#include "ATnode.h"
class ABST
{
public:
	ATnode* root;
	ABST();
	ABST(Asteroids);
	void insert(ATnode**, Asteroids);
	void delnode(ATnode**, Asteroids);
	bool isEmpty();
	bool Search(ATnode*, int);
	ATnode* getParent(ATnode*, int);
	ATnode* findMin(ATnode*);
	void inorder(ATnode*);
};


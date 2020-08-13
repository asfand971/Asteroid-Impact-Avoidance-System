#include "ATnode.h"
ATnode::ATnode()
{
	left = right = NULL;
}
ATnode::ATnode(Asteroids dat)
{
	data = dat;
}
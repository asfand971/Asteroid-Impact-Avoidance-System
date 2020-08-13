//Asteroid Queue immplementation
#include "AQnode.h"
class AQueue
{
public:
	AQnode* fr, * rr;
	AQueue();
	void A_enqueue(Asteroids);
	void A_dequeue();
	Asteroids front_Asteroids();
	void Display_Aesteroids();
};


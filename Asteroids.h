//BASE class 
#include <iostream>
using namespace std;
class Asteroids
{
private:
	float mass;
	int x, y, z;
	int distance;
	long diameter;
public:
	Asteroids();
	Asteroids(float, int, int, int, int,long);
	
	void setmass(float);
	void setdiameter(long);
	void setdistance(int);
	void setx(int);
	void sety(int);
	void setz(int);
	void setall();

	float getmass();
	int getdistance();
	int getx();
	int gety();
	int getz();
	long getdiameter();
	void getall();

};


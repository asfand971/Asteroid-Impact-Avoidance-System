#include "Asteroids.h"
Asteroids::Asteroids()
{
	mass = 0.0;
	x = y = z = 0;
	diameter = 0;
	distance = 0;
}
Asteroids::Asteroids(float m,int d, int x_input, int y_input, int z_input,long diam)
{
	mass = m;
	diameter = diam;
	x = x_input;
	y = y_input;
	z = z_input;
	distance = d;
}
void Asteroids::setmass(float m)
{
	mass = m;
}
void Asteroids::setdiameter(long dim)
{
	diameter = dim;
}
void Asteroids::setdistance(int d)
{
	distance = d;
}

void Asteroids::setx(int x_input)
{
	x = x_input;
}

void Asteroids::sety(int y_input)
{
	y = y_input;
}

void Asteroids::setz(int z_input)
{
	z = z_input;
}

float Asteroids::getmass()
{
	return mass;
}

int Asteroids::getx()
{
	return x;
}

int Asteroids::gety()
{
	return y;
}

int Asteroids::getz()
{
	return z;
}

int Asteroids::getdistance()
{
	return distance;
}
long Asteroids::getdiameter()
{
	return diameter;
}

void Asteroids::setall()
{
	float mass = 0.0;
	long dia = 0;
	int x, y, z;
	int dist = 0;
	x = y = z = 0;
	cout << "Enter mass of Asteroid" << endl;
	cin >> mass;
	cout << "Enter distance from Earth" << endl;
	cin >> dist;
	cout << "Enter Diameter of Asteroid" << endl;
	cin >> dia;
	cout << "Enter x coordinate" << endl;
	cin >> x;
	cout << "Enter y coordinate" << endl;
	cin >> y;
	cout << "Enter z coordinate" << endl;
	cin >> z;
	setmass(mass);
	setdistance(dist);
	setx(x);
	sety(y);
	setz(z);
	setdiameter(dia);
}

void Asteroids::getall()
{
	if (getmass() == 1.0)
	{
		cout << "Mass = " << getmass() << "  Tonne" << endl;
	}
	else
	{
		cout << "Mass = " << getmass() << " Tonnes" << endl;
	}
	cout << "Diameter of Asteroid = " << getdiameter() << endl;
	cout << "Distance of Asteroid from Earth = " << getdistance() << endl;	
	cout << "X coordinate = " << getx() << endl;
	cout << "Y coordinate = " << gety() << endl;
	cout << "Z coordinate = " << getz() << endl;
}



#include "AQueue.h"
AQueue::AQueue()
{
	fr = NULL;
	rr = NULL;

}

void AQueue::Display_Aesteroids()
{
	AQnode* temp = fr;
	while (temp != NULL)
	{
		temp->bolder.getall(); cout << endl;
		temp = temp->next;
	}

}
void AQueue::A_enqueue(Asteroids val)
{
	AQnode* temp = new AQnode;
	temp->bolder = val;
	temp->next = NULL;
	if (fr == NULL && rr == NULL)
	{
		fr = rr = temp;
		return;
	}
	rr->next = temp;
	rr = temp;
}
void AQueue::A_dequeue()
{
	AQnode* temp = fr;
	if (fr == NULL)
	{
		cout << "Queue is Empty\n";
		return;
	}
	if (fr == rr)
	{
		fr = rr = NULL;
	}
	else
		fr = fr->next;
	delete temp;
}
Asteroids AQueue::front_Asteroids()
{
	if (fr == NULL)
	{
		cout << "No Asteroid in Queue\n";
	
	}
	else
	{
		return fr->bolder;
	}


}

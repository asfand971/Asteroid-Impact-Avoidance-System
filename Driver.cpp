#include "ABST.h"
ABST obt;
void addtree(Asteroids val)
{	
	if (val.getdistance() <= 2000)
	{
		obt.insert(&obt.root,val);
	}
}
void pattern(int wave_height, int wave_length)
{
	int i, j, k, e, n, count, x;
	e = 2;
	x = 1;

	// for loop for height of wave 
	for (i = 0; i < wave_height; i++) {

		for (j = wave_height; j <= wave_height + i; j++)
			cout << " ";

		// for loop for wave length 
		for (count = 1; count <= wave_length; count++) {

			// checking for intermediate spaces 
			for (n = (wave_height + wave_height - 2); n >= x; n--)
				cout << " ";
			for (k = 1; k <= e; k++) {
				if (k == 1)
					cout << "/";
				else if (k == e)
					cout << "\\";
				else
					cout << " ";
			}
		}

		// incrementing counters value by two 
		x = x + 2;
		e = e + 2;
		cout << endl;
	}
}
void wave()
{
	int wave_height = 5;

	// change value to decrease or increase  
	// the length of wave 
	int wave_length = 5;

	pattern(wave_height, wave_length);
	// Function definition 
	
}
void intro()
{
	cout << "    ***************************************************" << endl;
	wave();
	cout << "    ***************************************************" << endl;
	cout << "    *                                                 *" << endl;
	cout << "    *                                                 *" << endl;
	cout << "    *        Asteroid Impact Avoidance                *" << endl;
	cout << "    *                System                           *" << endl;
	cout << "    *                                                 *" << endl;
	cout << "    ***************************************************" << endl;
	wave();
	cout << "    ***************************************************" << endl;
	system("pause");
	system("cls");
}
int selection()
{
	int choie = 0;
	char cho = 'y';
	while(cho=='y'){
	cout << "    ***************************************************" << endl;
	wave();
	cout << "    ***************************************************" << endl;
	cout << "    Enter 1 to ADD a new asteroid:" << endl;
	cout << "    Enter 2 to delete an Asteroid:" << endl;
	cout << "    Enter 3 to display all Near Earth Objects (Distance < 2000):" << endl;
	cout << "    Enter 4 to get best mean of avoidance" << endl;
	cout << "    Enter 5 to Exit" << endl;
	cout << "    ***************************************************" << endl;
	wave();
	cout << "    ***************************************************" << endl;
	cin >> choie;
		switch (choie)
		{
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 3;
			break;
		case 4:
			return 4;
			break;
		case 5:
			return 5;
			break;
		default:
			cerr << "Invalid Selection !" << endl;
			return 0;
			break;
		}
	}
}
void menu()
{
	AQueue obj;
	Asteroids obj1;
	//int size = 0;
	char ch = ' ';
	
	AHeap hpobj(1);
	intro();
	string count = "y";
	while (count == "y")
	{
	switch (selection())
	{
	case 1:
		system("cls");
		cout << "Enter Asteroid in QUEUE" << endl; //First input 
		obj1.setall();
		obj.A_enqueue(obj1);
		hpobj.insertKey((int)obj1.getmass());	//inserted in heap
		addtree(obj1);
		break;
	case 2:
		system("cls");
		cout << "Asteroid Deleted from QUEUE" << endl;
		obt.delnode(&obt.root, obj.front_Asteroids());
		hpobj.deleteKey(obj.front_Asteroids().getmass());
		obj.A_dequeue();
		break;
	case 3:
		system("cls");
		cout << "Do you want to Display Near Earth Object details or Only Asteroids mass! (a / m)" << endl;
		cin >> ch;
		if (ch == 'a')
		{
			cout << "Near Earth Objects :" << endl;
			obt.inorder(obt.root);
		}
		else
		{
			hpobj.display();
		}
		break;
	case 4:
		system("cls");
		cout << "Best mean of avoidance GRAPH DSA" << endl;
		break;
	case 5:
		system("cls");
		//return;
		break;
	default:
		system("cls");
		cout << "LOL NOT possible!" << endl;
	}
	cout << "Do you want to Countinue (y/n)" << endl;
	cin >> count;
}
}

int main()
{
	
		menu();
	
	
	system("pause");
	return 0;
}
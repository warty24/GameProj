#include "Source.h"

using namespace std;



void main()
{

	srand(time(0));

	cout << "P1 warriors:" << endl;
	fillUnitArr(p1);
	outUnitTypes(p1);


	cout << "P2 warriors:" << endl;
	fillUnitArr(p2);
	outUnitTypes(p2);
			change(p1[0], p2[0]);
			
	for (int k{}; k < 3; k++)
	{
		cout << "___________ROUND "<<k+1 <<"________FIGHT!" << endl;
		/*
		for (int i{}; i < 3; i++)
		{
			p1[i]->dealDgm(p1[i]->setTarget(p2));
			if (p2[i]->getHp() <= 0)
			{
				p2[i]->setIsLive(false);
			}
		}
		for (int i{}; i < 3; i++)
		{
			p2[i]->dealDgm(p1[rand() % 3]);
			if (p2[i]->getHp() <= 0)
			{
				p2[i]->setIsLive(false);
			}
		}
		*/
		for (int i = 0; i < ARMY_QUANTITY; i++)
		{
			p1[i]->setTargetAndDD(p2);
			p2[i]->setTargetAndDD(p1);
		}
	}
			

	// Uncoment to crush
	//god.kill(p1[2],some1);

	outUnitTypes(p1);
	cout << "P2" ;
	outUnitTypes(p2);

	system("pause");
}
void fillUnitArr(Soldier **sol)
{
	for (int i = 0; i < ARMY_QUANTITY; i++)
	{
		switch (rand() % 3)
		{
		case 0:
		{
			sol[i] = new Archer;
			break;
		}
		case 1:
		{
			sol[i] = new Swordman;
			break;
		}
		case 2:
		{
			sol[i] = new Wizard;
			break;
		}
		default:
		{
			cout << "Somthing went wrong in Unit creation =(" << endl;
			break;
		}
		}
	}
}
void outUnitTypes(Soldier **sol) 
{
	cout << endl;
	
	for (int i = 0; i < ARMY_QUANTITY; i++)
	{
		if (sol[i]->getIsLive())
		{
			cout << sol[i]->getType() << "Hp: " <<sol[i]-> getHp()  <<endl;
		}
	}
	cout << endl;
}
void change(Soldier *a, Soldier *b)
{
	Soldier *asdad;
	asdad = a;
	a = b;
	b = asdad;
}


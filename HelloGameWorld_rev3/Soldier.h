#pragma 
#ifndef Soldier_HEADER
#define Soldier_HEADER


#include <string>
#include <iostream>

using namespace std;

 class Soldier 
{
public:
	Soldier();
	~Soldier();
	
	void setHp(int hp)
	{
		this->hp = hp;
	}
	void setDmg(int dmg)
	{
		this->dmg = dmg;
	}
	void setDodge(int dodge)
	{
		this->dodge = dodge;
	}
	void setType(string type)
	{
		this->type = type;
	}
	void setIsLive(bool isLive)
	{
		this->isLive = isLive;
	}

	void dealDgm(Soldier *s)
	{	
		if (isLive)
		{
			if (!isDodged(*s)) 
			{
				s->setHp(s->getHp()-getDmg());
			}
			if((s->getHp()) <= 0)
			{
				setIsLive(false);
			}
		}
		
		
	}
	bool isDodged(Soldier s)
	{
		if (rand() % 101 > s.dodge)
		{
			cout << getType() << " Mised at " <<s.getType() << endl;
			return true;
		}
		else
		{
			cout <<getType() << " Damage dealed! " <<s.getType() << endl;
			return false;
		}
	}
	/*
	void kill(Soldier *s, int &some)
	{
		some--;
	}
	*/

	int getHp()
	{
		return hp;
	}
	int getDmg()
	{
		return dmg;
	}
	int getDodge()
	{
		return dodge;
	}
	string getType()
	{
		return type;
	}
	bool getIsLive() {
		return isLive;
	}
	
	void setTargetAndDD(Soldier **sol)
	{
		bool cont = true;
		for (int i = 0; i < 3; i++)
		{
			if (getType() == sol[i]->getType() && sol[i]->getIsLive())
			{
				dealDgm(sol[i]);
				cont = false;
				break;
				//return sol[i];
			}
		}
		if (cont)
		{
			for (int i = 0; i < 3; i++)
			{
				if (sol[i]->getHp() > 0)
				{
					dealDgm(sol[i]);
					cont = false;
					break;
				}
			}
		}
		else
		{
			cout << "There`s no target selected" << endl;
		}

	}

private:
	bool isLive;
	int hp;
	int dmg;
	int dodge;
	string type;
	Soldier &target;
};


#endif // !Soldier_HEADER

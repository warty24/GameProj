#pragma once
#ifndef Source_HEADER
#define Source_HEADER
#include <iostream>
#include <string>
#include <ctime>

#include "Soldier.h"
#include "Archer.h"
#include "Swordman.h"
#include "Wizard.h"


 const int ARMY_QUANTITY = 3;


Soldier *p1[ARMY_QUANTITY];

Soldier *p2[ARMY_QUANTITY];
Soldier god;

void fillUnitArr(Soldier **sol);
void outUnitTypes(Soldier **sol);
void change(Soldier *a, Soldier *b);


#endif
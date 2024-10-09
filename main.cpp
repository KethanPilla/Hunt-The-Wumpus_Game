// ---------------------------------------------------------------------------
// Name: Kethan Pilla
// Course-Section: CS 255- 01
// Assignment: Project #6
// Date due: 10/27/2023
// Description: Hunt the Wumpus is a text-based game where players
// navigate a network of chambers, facing dangers such as a 
// bottomless pit, bats, and a Wumpus. The objective is to eliminate 
// the Wumpus with limited arrows while avoiding hazards.
// ---------------------------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifndef Incl_Hunt
#define Incl_Hunt
#include "Hunt.h"
#endif // Incl_Hunt

#ifndef Incl_Chamber
#define Incl_Chamber
#include "Chamber.h"
#endif // Incl_Chamber

int main()
{
	srand(time(0));
	Hunt gameInstance;
	gameInstance.play();
	return 0;
}

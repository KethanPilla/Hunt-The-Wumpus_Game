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
#ifndef HUNT_H
#define HUNT_H
#include "Chamber.h"

class Hunt
{
	private:
		Chamber* player;
		Chamber* bats;
		Chamber* wumpus;
		Chamber* pit;
		bool gameOver;
		int numArrows;

	public:
		Hunt();
		void play();
		void reportPosition();
		void movePlayer(int);
		void randomFlight();
		void killPlayer(int);
		int fire(int door);
		void moveWumpus();

};
#endif // HUNT_H
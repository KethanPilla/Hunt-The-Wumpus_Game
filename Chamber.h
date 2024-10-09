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
#ifndef CHAMBER_H
#define CHAMBER_H

class Chamber
{
	private:
		int chamberID;
		Chamber *door1;
		Chamber *door2;
		Chamber *door3;

	public:
		Chamber(int id, Chamber *d1, Chamber *d2, Chamber *d3);
		void setPtrs(Chamber *d1, Chamber *d2, Chamber *d3);
		int getID();
		int getDoor1ID();
		int getDoor2ID();
		int getDoor3ID();
		Chamber *getDoor1Ptr();
		Chamber *getDoor2Ptr();
		Chamber *getDoor3Ptr();
};
#endif
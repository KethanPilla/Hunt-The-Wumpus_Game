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
using namespace std;

#include "Chamber.h"

// The Chamber constructor initializes a chamber 
// with a unique ID and connects it to three other chambers via doors.
Chamber::Chamber(int id, Chamber* d1, Chamber* d2, Chamber* d3)
{
	chamberID = id;
	door1 = d1;
	door2 = d2;
	door3 = d3;
}
// The setPtrs method sets the pointers to three 
// neighboring chambers, effectively connecting the current chamber to others.
void Chamber::setPtrs(Chamber* d1, Chamber* d2, Chamber* d3)
{
	door1 = d1;
	door2 = d2;
	door3 = d3;
}

// The getID method returns the unique identifier (ID) of the chamber.
int Chamber::getID()
{
	return chamberID;
}
// The getDoor1ID method returns the ID of the chamber 
// connected through door 1 or -1 if there's no connection.
int Chamber::getDoor1ID()
{
	return door1 ? door1->getID() : -1;
}
// The getDoor2ID method returns the ID of the 
// chamber connected through door 2 or -1 if there's no connection.
int Chamber::getDoor2ID()
{
	return door2 ? door2->getID() : -1;
}
// The getDoor3ID method returns the ID of the chamber 
// connected through door 3 or -1 if there's no connection.
int Chamber::getDoor3ID()
{
	return door3 ? door3->getID() : -1;
}
// The getDoor1Ptr method returns a pointer to the chamber connected through door 1.
Chamber* Chamber::getDoor1Ptr()
{
	return door1;
}
// The getDoor2Ptr method returns a pointer to the chamber connected through door 2.
Chamber* Chamber::getDoor2Ptr()
{
	return door2;
}
// The getDoor3Ptr method returns a pointer to the chamber connected through door 3.
Chamber* Chamber::getDoor3Ptr()
{
	return door3;
}

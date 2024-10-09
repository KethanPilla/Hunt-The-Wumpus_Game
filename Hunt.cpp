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
#include "Hunt.h"
#include <iostream>
#include <cstdlib>	// Headers to generate random numbers
#include <ctime>

using namespace std;
//---------------------------------------------------------------------------
/* Hunt() Initializes the game environment, chambers, hazards, 
*  and player state for Hunt the Wumpus
*  INCOMING DATA: none
*  OUTGOING DATA: none*/
Hunt::Hunt()
{
	//constructor given in the question (unchanged)
	int rtemp;
	//Create a temporary array of Chamber pointers
//(this array has a local scope and will be deleted)
	Chamber* ptrArray[20];
	//Dynamically allocate 20 Chamber objects, each pointed to by a pointer in the array
	for(int i=0; i<20; i++)
	{
		ptrArray[i] = new Chamber(i+1, nullptr, nullptr, nullptr);
	}
	//Set the Chambers to point to one another to build your game map
	//The map is based on an icosahedron (d-20), see class discussion
	ptrArray[0]->setPtrs(ptrArray[6], ptrArray[18], ptrArray[12]);
	ptrArray[1]->setPtrs(ptrArray[11], ptrArray[17], ptrArray[19]);
	ptrArray[2]->setPtrs(ptrArray[16], ptrArray[15], ptrArray[18]);
	ptrArray[3]->setPtrs(ptrArray[17], ptrArray[10], ptrArray[13]);
	ptrArray[4]->setPtrs(ptrArray[17], ptrArray[14], ptrArray[13]);
	ptrArray[5]->setPtrs(ptrArray[8], ptrArray[15], ptrArray[13]);
	ptrArray[6]->setPtrs(ptrArray[16], ptrArray[0], ptrArray[14]);
	ptrArray[7]->setPtrs(ptrArray[9], ptrArray[19], ptrArray[15]);
	ptrArray[8]->setPtrs(ptrArray[5], ptrArray[10], ptrArray[18]);
	ptrArray[9]->setPtrs(ptrArray[16], ptrArray[11], ptrArray[7]);
	ptrArray[10]->setPtrs(ptrArray[8], ptrArray[3], ptrArray[12]);
	ptrArray[11]->setPtrs(ptrArray[9], ptrArray[14], ptrArray[1]);
	ptrArray[12]->setPtrs(ptrArray[10], ptrArray[4], ptrArray[0]);
	ptrArray[13]->setPtrs(ptrArray[3], ptrArray[5], ptrArray[19]);
	ptrArray[14]->setPtrs(ptrArray[4], ptrArray[11], ptrArray[6]);
	ptrArray[15]->setPtrs(ptrArray[5], ptrArray[2], ptrArray[7]);
	ptrArray[16]->setPtrs(ptrArray[9], ptrArray[2], ptrArray[6]);
	ptrArray[17]->setPtrs(ptrArray[4], ptrArray[3], ptrArray[1]);
	ptrArray[18]->setPtrs(ptrArray[2], ptrArray[8], ptrArray[0]);
	ptrArray[19]->setPtrs(ptrArray[1], ptrArray[13], ptrArray[7]);

	//set gameOver bool to false
	gameOver = false;

	//set the player to begin in the first chamber
	player = ptrArray[0];

	//give the bats, the pit, and the wumpus a random starting chamber (not chamber 1)
	rtemp = rand()%18+1; //random values between 1 and 19, exclude 0
	wumpus = ptrArray[rtemp];
	cout<<"CHEATING: Wumpus Location: "<<wumpus->getID()<<endl;
	rtemp = rand()%18+1; //random values between 1 and 19, exclude 0
	bats = ptrArray[rtemp];
	cout<<"CHEATING: Bats Location: "<<bats->getID()<<endl;
	rtemp = rand()%18+1; //random values between 1 and 19, exclude 0
	pit = ptrArray[rtemp];
	cout<<"CHEATING: Pit Location: "<<pit->getID()<<endl;

	//set the number of arrows
	numArrows=5;
}
//---------------------------------------------------------------------------
/* play() Manages the main game loop, allowing the player to move, 
*  shoot arrows, and responds to player's actions while checking 
*  game-ending conditions
*  INCOMING DATA: none
*  OUTGOING DATA: none*/
void Hunt::play()
{
	while (!gameOver)
	{
		// Reports the player's current chamber and nearby hazards
		reportPosition();

		int choice;
		cout << "Make a door selection: 1, 2, or 3, or press 4 to fire an arrow." << endl;
		cin >> choice;

		if (choice >= 1 && choice <= 3)
		{
			// Updates the player's chamber based on the user's choice of door
			movePlayer(choice);

			if (player == wumpus)
			{
				killPlayer(1); // Player and Wumpus in the same chamber
			}
			else if (player == pit)
			{
				killPlayer(2); // Player and Pit in the same chamber
			}
			else if (player == bats)
			{
				randomFlight(); // Player and Bats in the same chamber
			}
		}
		else if (choice == 4)
		{
			// Fire an arrow
			int door;
			cout << "Choose a door to fire your arrow into (1, 2, or 3): ";
			cin >> door;

			int result = fire(door);
			if (result == 1)
			{
				cout << "Congratulations! You've killed the Wumpus! You win!" << endl;
				gameOver = true;
			}
			else if (result == 0)
			{
				numArrows--;
				cout << "Your shot flew harmlessly into the darkness. The sound spooked the Wumpus." << endl;
				cout << "You have " << numArrows << " arrows remaining." << endl;
				moveWumpus(); // Randomly moves the Wumpus to an adjacent chamber
			}
		}
		else
		{
			cout << "Invalid Selection!!" << endl;
		}

		// Check if the player has enough arrows
		if (numArrows <= 0)
		{
			cout << "You are out of arrows." << endl;
			gameOver = true;
		}
	}
}
//---------------------------------------------------------------------------
/* fire() Fires an arrow into a selected door and checks if the 
*  Wumpus is hit, returning a result code (1 if hit, 0 if missed)
*  INCOMING DATA: int door
*  OUTGOING DATA: int */
int Hunt::fire(int door)
{
	if (numArrows <= 0)
	{
		cout << "You are out of arrows." << endl;
		return -1;
	}

	// if the Wumpus was in the selected chamber returns 1
	if ((door == 1 && player->getDoor1Ptr() == wumpus) ||
	        (door == 2 && player->getDoor2Ptr() == wumpus) ||
	        (door == 3 && player->getDoor3Ptr() == wumpus))
	{
		return 1;
	}

	return 0; // return 0 if wrong guess
}
//---------------------------------------------------------------------------
/* killPlayer() Ends the game with a specified game-over condition 
*  and displays a corresponding message
*  INCOMING DATA: int condition
*  OUTGOING DATA: none */
void Hunt::killPlayer(int condition)
{
	gameOver = true;

	// Determines and displays the game-ending message based on the given condition
	switch (condition)
	{
		case 1:
			cout << "The Wumpus consumes you! Game over." << endl;
			break;
		case 2:
			cout << "You fall into a bottomless pit! Game over." << endl;
			break;
		default:
			cout << "You meet an unfortunate end. Game over." << endl;
	}
}
//---------------------------------------------------------------------------
/* randomFlight() Simulates a random flight of the player caused by bats, 
*  moving them to different chambers and checking for hazards
*  INCOMING DATA: none
*  OUTGOING DATA: none */
void Hunt::randomFlight()
{
	int flightTimes = rand() % 5 + 3; // Generates a random value between 3 and 7

	for (int i = 0; i < flightTimes; i++)
	{
		// Randomly select a door from the current chamber
		int randomDoor = rand() % 3 + 1;

		movePlayer(randomDoor);

		// Check if the player has landed on a hazard
		if (player == pit || player == wumpus)
		{
			killPlayer(2); // Player landed on a hazard
			return;
		}
	}
}
//---------------------------------------------------------------------------
/* reportPosition() Reports the player's current chamber, 
*  nearby hazards, and available door connections
*  INCOMING DATA: none
*  OUTGOING DATA: none */
void Hunt::reportPosition()
{
	// Tell the player what chamber they are in
	cout << "You are in Chamber " << player->getID() << ":" << endl;

	// Report nearby hazards
	if (player->getDoor1Ptr() == bats || player->getDoor2Ptr() == bats
	        || player->getDoor3Ptr() == bats)
	{
		cout << "You hear flapping wings and rushing wind." << endl;
	}

	// Report door connections
	cout << "	Door 1 leads to Chamber " << player->getDoor1ID() << endl;
	cout << "	Door 2 leads to Chamber " << player->getDoor2ID() << endl;
	cout << "	Door 3 leads to Chamber " << player->getDoor3ID() << endl;
}
//---------------------------------------------------------------------------
/* movePlayer() Updates the player's position by moving them
*  through a selected door.
*  INCOMING DATA: int doorChoice
*  OUTGOING DATA: none */
void Hunt::movePlayer(int doorChoice)
{
	// Update the player's position based on the chosen door
	if (doorChoice == 1)
	{
		player = player->getDoor1Ptr();
	}
	else if (doorChoice == 2)
	{
		player = player->getDoor2Ptr();
	}
	else if (doorChoice == 3)
	{
		player = player->getDoor3Ptr();
	}
}
//---------------------------------------------------------------------------
/* moveWumpus() Randomly moves the Wumpus to a neighboring chamber and 
*  provides a CHEATING output of its location
*  INCOMING DATA: none
*  OUTGOING DATA: none */
void Hunt::moveWumpus()
{
	// Randomly select a door to move the Wumpus
	int randomDoor = rand() % 3 + 1;

	// Move the Wumpus to the chamber connected by the randomly selected door
	wumpus = wumpus->getDoor1Ptr(); // Default to Door 1
	if (randomDoor == 2)
	{
		wumpus = wumpus->getDoor2Ptr(); // Move to Door 2
	}
	else if (randomDoor == 3)
	{
		wumpus = wumpus->getDoor3Ptr(); // Move to Door 3
	}

	// CHEATING output: Report Wumpus location
	cout << "CHEATING: Wumpus in Chamber " << wumpus->getID() << endl;
}
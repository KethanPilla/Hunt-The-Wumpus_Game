# Hunt-The-Wumpus (Text based game)
## THE PROBLEM:
In Hunt the Wumpus, a player moves through a series of interconnected chambers, attempting to evade a series of obstacles and (hopefully) successfully hunt the Wumpus; an odious, smelly creature that is going to otherwise eat you.  Each chamber is connected to three (3) other chambers through three doors.  There are 20 chambers arranged in the shape of an icosahedron (D-20).  All together there are three (3) total hazards:
1. A bottomless pit (you will feel a breeze nearby when you are adjacent to it).
2. A colony of bats that will pick you up and drop you in a random chamber--including potentially deadly chambers (you will hear flapping wings and rushing wind when you are adjacent to them).
3. A fearsome, hungry, and unbathed Wumpus (you will smell it nearby when it is in an adjacent chamber).
The starting location of the bottomless pit, the bats, and the Wumpus are all random, but never begin in the first chamber.  The bottomless pit and bats cannot move, the Wumpus can move but only under specific well-defined conditions (see below).

The game proceeds as the player moves from chamber to chamber.  If you enter a chamber with either the Wumpus, or the bottomless pit you are instantly killed and the game is over.  If you enter a chamber with the bats you are teleported to a random chamber.
Instead of moving, you may choose to fire an arrow into an adjacent chamber.  If your arrow strikes the Wumpus in an adjacent chamber you win.  You have 5 arrows.  If you fire an arrow and miss, the sound will spook the Wumpus and cause him to randomly move to a chamber adjacent to his current location.
The Wumpus is too heavy to be lifted by bats.  The Wumpus is covered in suckers; he won't fall down the bottomless pit.  The Wumpus will consume you before you fall in the bottomless pit if they are both in the same chamber with you.  Likewise, the Wumpus is faster than the bats and will consume you before the bats can lift you should you, the bats, and the Wumpus all be simultaneously in the same chamber.  The bats will not save you from the bottomless pit.

## Overview
The Hunt the Wumpus project is a C++ application where players explore a dungeon's chambers to hunt for treasures while avoiding various traps. This project implements a simulation of the dungeon exploration process, where the chambers are interconnected and contain various obstacles and rewards. The main focus is on creating an interactive environment where players can traverse through different chambers, collect treasures, and experience dynamic events like traps or surprises.

## Purpose
The purpose of this project is to:
  - Simulate a dungeon treasure hunt, where users explore different chambers.
  - Enable interactions between players and the environment (chambers), such as        collecting treasure, avoiding traps, and making choices that affect their          progress.
  - Use data structures to manage the chambers and the hunt process, ensuring          efficient navigation and interaction.

## Underlying Data Structures & Principles
### 1. Object-Oriented Programming (OOP):
- Encapsulation: Each chamber and hunt event is encapsulated in respective classes (Chamber, Hunt) that manage their own state and behavior.
- Modularity: The code is divided into different modules like Chamber, Hunt, and main, ensuring maintainability and scalability.
  
### 2. Data Structures:
- Chambers as Nodes: Each chamber is treated as a node in a graph-like structure. The chambers are connected and can be traversed from one to another.
- Events Management: The player's interactions with chambers (e.g., finding treasure, encountering traps) are handled using state variables within the classes.

### 3. Game Design Principles:
- Randomization: Certain events (treasures, traps) are randomized, ensuring that each run of the dungeon exploration is different, making the gameplay experience more dynamic.
- Player Decision Making: Players can make decisions, like choosing which chamber to explore next, affecting the flow of the hunt.
  
## Implementation
- Chamber Class (Chamber.cpp, Chamber.h):
  - Represents an individual chamber in the dungeon.
  - Contains attributes like chamber ID, treasure, trap status, and connections to other chambers.
  - Provides methods to check for treasure, trigger traps, and navigate between chambers.
- Hunt Class (Hunt.cpp, Hunt.h):
  - Manages the entire treasure hunt process, orchestrating the player's exploration through the dungeon.
  - Keeps track of visited chambers, treasures collected, and overall progress.
  - Handles the logic of the player's actions and game events.
- Main Program (main.cpp):
  - Acts as the entry point for the program.
  - It initializes the dungeon, creates chambers, and triggers the treasure hunt based on user inputs.
  - Allows players to explore the chambers, encounter events, and track their progress.
    
## Files
1. `Chamber.cpp` and `Chamber.h`: Define the chamber structure and the possible actions within a chamber (e.g., treasure, traps, navigation).
2. `Hunt.cpp` and `Hunt.h`: Manages the treasure hunt, player's progression, and interaction with chambers.
3. `main.cpp`: The main control flow of the application where users interact with the dungeon and initiate the treasure hunt.

## Example Test Cases
### Test Case 1: Treasure in a Chamber
**Operation**:
- The player enters a chamber that contains treasure.
  
**Expected Outcome**:
```  
The player collects the treasure, and the total treasure count is updated.
```
### Test Case 2: Trap Encounter
**Operation**:
- The player enters a chamber with a hidden trap.
  
**Expected Outcome**:
```  
The trap is triggered, and the player loses health or progress depending on the trap type.
```
### Test Case 3: Chamber Navigation
**Operation**:
-The player moves from one chamber to another.

**Expected Outcome**:
```
The player successfully navigates to the next chamber, and the new chamber's details (treasure, trap) are revealed.
```
### Test Case 4: Exploring the Entire Dungeon
**Operation**:
- The player explores all chambers in the dungeon.
  
**Expected Outcome**:
```  
All chambers are visited, treasures are collected, and traps are triggered based on the player's decisions.
```
## Use Case
### Use Case: Interactive Dungeon Exploration Game
A user who enjoys role-playing or adventure games can explore a dungeon with interconnected chambers filled with traps and treasures. The player can:
- Explore multiple chambers by navigating through different paths.
- Encounter random events like finding treasure or falling into traps.
- Keep track of their progress and treasure collection, making decisions that affect their success or failure.
  
This use case offers a fun and engaging way to experience dungeon exploration, with random events keeping the gameplay exciting and unpredictable.

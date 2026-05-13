// CSC 134
// M6HW - Text Adventure Game
// Jordane
// 5/4/2025


#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Direction { NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3, NUM_DIRECTIONS = 4 };
const string DIRECTION_NAMES[NUM_DIRECTIONS] = { "north", "east", "south", "west" };

// Room definitions for the School
enum Room { 
    ENTRANCE = 0, 
    HALLWAY = 1, 
    CLASSROOM = 2, 
    LIBRARY = 3, 
    CAFETERIA = 4, 
    GYM = 5, 
    OFFICE = 6, 
    INFIRMARY = 7, 
    GATE = 8, 
    NUM_ROOMS = 9 
};

int main() {
    string roomNames[NUM_ROOMS] = { 
        "Entrance Hall", "Main Hallway", "Math Classroom", "Dusty Library", 
        "Cafeteria", "Gymnasium", "Principal's Office", "Infirmary", "The Front Gate" 
    };
    
    string roomDescriptions[NUM_ROOMS] = {
        "Dust motes dance in the light. A note on the wall reads: 'The gates are mag-locked. Only the Principal's Keycard can open them.'",
        "A long, echoing hallway. Lockers line the walls, some hanging off their hinges.",
        "Desks are overturned. Chalkboard drawings of geometry still remain.",
        "Smells of rotting paper. The silence here is heavy.",
        "Smells of sour milk. The kitchen door is jammed shut.",
        "A massive, dark room. Your footsteps echo loudly on the hardwood floor.",
        "A plush chair sits behind a mahogany desk. Something plastic glints on the desk.",
        "Rows of empty cots. It feels clinical and creepy.",
        "The tall iron bars of the school's exit. Beyond it lies freedom!" 
    };

    int connections[NUM_ROOMS][NUM_DIRECTIONS];
    for (int i = 0; i < NUM_ROOMS; i++)
        for (int j = 0; j < NUM_DIRECTIONS; j++) connections[i][j] = -1;

    // --- School Map Layout ---
    connections[ENTRANCE][NORTH] = HALLWAY;
    connections[ENTRANCE][SOUTH] = GATE;      // The Locked Exit (Gold Requirement)

    connections[HALLWAY][SOUTH] = ENTRANCE;
    connections[HALLWAY][NORTH] = CAFETERIA;
    connections[HALLWAY][EAST]  = CLASSROOM;
    connections[HALLWAY][WEST]  = LIBRARY;

    connections[CLASSROOM][WEST] = HALLWAY;
    connections[CLASSROOM][SOUTH] = OFFICE;   // Leads to the Keycard

    connections[LIBRARY][EAST] = HALLWAY;
    connections[LIBRARY][SOUTH] = INFIRMARY;

    connections[CAFETERIA][SOUTH] = HALLWAY;
    connections[CAFETERIA][EAST]  = GYM;

    connections[GYM][WEST] = CAFETERIA;

    connections[OFFICE][NORTH] = CLASSROOM;

    connections[INFIRMARY][NORTH] = LIBRARY;

    // Game state
    int currentRoom = ENTRANCE;
    bool gameRunning = true;
    bool hasKeycard = false; 
    bool keycardAvailable = true;

    cout << "--- ESCAPE FROM ST. JUDE'S ABANDONED SCHOOL ---\n";

    while (gameRunning) {
        cout << "\n[" << roomNames[currentRoom] << "]" << endl;
        cout << roomDescriptions[currentRoom] << endl;

        // Silver: Interaction (Item Pickup)
        if (currentRoom == OFFICE && keycardAvailable) {
            cout << "You see a BLUE MASTER KEYCARD on the desk." << endl;
        }

        cout << "Exits: ";
        for (int dir = 0; dir < NUM_DIRECTIONS; dir++) {
            if (connections[currentRoom][dir] != -1) cout << DIRECTION_NAMES[dir] << " ";
        }
        cout << "\nCommands: north, south, east, west, take, quit" << endl;

        string command;
        cout << "> ";
        cin >> command;

        int nextRoom = -1;
        if (command == "north" || command == "n") nextRoom = connections[currentRoom][NORTH];
        else if (command == "east" || command == "e") nextRoom = connections[currentRoom][EAST];
        else if (command == "south" || command == "s") nextRoom = connections[currentRoom][SOUTH];
        else if (command == "west" || command == "w") nextRoom = connections[currentRoom][WEST];
        
        // Gold: Lock and Key Situation
        if (nextRoom != -1) {
            if (nextRoom == GATE && !hasKeycard) {
                cout << "\n*** The Front Gate is locked by an electronic pad. 'INSERT KEYCARD' ***" << endl;
            } else {
                currentRoom = nextRoom;
                // Gold: The Ending
                if (currentRoom == GATE) {
                    cout << "\n[" << roomNames[GATE] << "]" << endl;
                    cout << "The light on the reader turns green. The gate swings open with a heavy groan." << endl;
                    cout << "You run out into the night. YOU ARE FREE!" << endl;
                    gameRunning = false;
                }
            }
        } 
        else if (command == "take") {
            if (currentRoom == OFFICE && keycardAvailable) {
                cout << "You pocket the MASTER KEYCARD. This should get you out of here!" << endl;
                hasKeycard = true;
                keycardAvailable = false;
            } else {
                cout << "There is nothing useful to take here." << endl;
            }
        }
        else if (command == "quit" || command == "q") {
            gameRunning = false;
        } else if (nextRoom == -1 && command != "take") {
            cout << "You walk into a wall. Try a different direction." << endl;
        }
    }

    cout << "\nGame Over. Thanks for playing!" << endl;
    return 0;
}
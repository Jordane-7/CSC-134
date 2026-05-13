// CSC 134
// M7HW1
// Jordane
// 5/13/2026
                                                                        
// ┌───────────┐              ┌─────────────┐                                      
// │ Gymnasium ◄──────────────┤  Cafeteria  │                                      
// └───────────┘              └──────┬──────┘                                      
//                                   │                                             
//                                   │                                             
//                                   │                                             
//  ┌─────────┐               ┌──────┴─────┐          ┌─────────┐                  
//  │ Library ◄───────────────┼Main Hallway┼──────────►Classroom│                  
//  └────┬────┘               └─────┬──────┘          └────┬────┘                  
//       │                          │                      │                       
//       │                          │                      │                       
//       │                          │                      │                       
// ┌─────┴─────┐                ┌───┴────┐            ┌────┴───┐                   
// │ Infirmary │                │Entrance│            │ Office │                   
// └───────────┘                └────┬───┘            └┌─────────┐                 
//                                   │                 │Key Card │                 
//                                   │                 └─────────┘                 
//                 ─                 │                                             
//                                   │                                             
//                                ┌──┴─┐                                           
//                                │Gate│                                           
//                                └────┘                                           
/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

// --- STEP 1: DEFINE COLORS ---
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

enum Direction { NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3, NUM_DIRECTIONS = 4 };
const string DIRECTION_NAMES[NUM_DIRECTIONS] = { "north", "east", "south", "west" };

enum Room { 
    ENTRANCE = 0, HALLWAY = 1, CLASSROOM = 2, LIBRARY = 3, 
    CAFETERIA = 4, GYM = 5, OFFICE = 6, INFIRMARY = 7, 
    GATE = 8, NUM_ROOMS = 9 
};

// --- STEP 2: ASCII ART FUNCTIONS ---
void drawTitle() {
    cout << RED << BOLD << R"(
    =========================================
      ESCAPE FROM ST. JUDE'S ABANDONED SCHOOL
    =========================================
    )" << RESET << endl;
}

void drawKeycard() {
    cout << BLUE << R"(
          __________
         |  ______  |
         | | KEY  | |
         | |__134_| |
         |__________|
    )" << RESET << endl;
}

void drawGate(bool locked) {
    if (locked) {
        cout << RED << R"(
          ||  ||  ||  ||  ||
          ||__||__||__||__||
          [    LOCKED      ]
          ||  ||  ||  ||  ||
        )" << RESET << endl;
    } else {
        cout << GREEN << R"(
          \ \  \ \    / /  / /
           \ \  \ \  / /  / /
           [     OPEN      ]
           / /  / /  \ \  \ \
        )" << RESET << endl;
    }
}

int main() {
    string roomNames[NUM_ROOMS] = { 
        "Entrance Hall", "Main Hallway", "Math Classroom", "Dusty Library", 
        "Cafeteria", "Gymnasium", "Principal's Office", "Infirmary", "The Front Gate" 
    };
    
    string roomDescriptions[NUM_ROOMS] = {
        "Dust motes dance in the light. A note reads: 'The gates are mag-locked.'",
        "A long, echoing hallway. Lockers line the walls.",
        "Desks are overturned. Geometry drawings remain on the chalkboard.",
        "Smells of rotting paper. The silence here is heavy.",
        "Smells of sour milk. The kitchen door is jammed shut.",
        "A massive, dark room. Your footsteps echo loudly.",
        "A plush chair sits behind a mahogany desk. Something glints here.",
        "Rows of empty cots. It feels clinical and creepy.",
        "The tall iron bars of the school's exit." 
    };

    int connections[NUM_ROOMS][NUM_DIRECTIONS];
    for (int i = 0; i < NUM_ROOMS; i++)
        for (int j = 0; j < NUM_DIRECTIONS; j++) connections[i][j] = -1;

    connections[ENTRANCE][NORTH] = HALLWAY;
    connections[ENTRANCE][SOUTH] = GATE;
    connections[HALLWAY][SOUTH] = ENTRANCE;
    connections[HALLWAY][NORTH] = CAFETERIA;
    connections[HALLWAY][EAST]  = CLASSROOM;
    connections[HALLWAY][WEST]  = LIBRARY;
    connections[CLASSROOM][WEST] = HALLWAY;
    connections[CLASSROOM][SOUTH] = OFFICE;
    connections[LIBRARY][EAST] = HALLWAY;
    connections[LIBRARY][SOUTH] = INFIRMARY;
    connections[CAFETERIA][SOUTH] = HALLWAY;
    connections[CAFETERIA][EAST]  = GYM;
    connections[GYM][WEST] = CAFETERIA;
    connections[OFFICE][NORTH] = CLASSROOM;
    connections[INFIRMARY][NORTH] = LIBRARY;

    int currentRoom = ENTRANCE;
    bool gameRunning = true;
    bool hasKeycard = false; 
    bool keycardAvailable = true;

    drawTitle();

    while (gameRunning) {
        // Show Graphics based on room
        if (currentRoom == GATE) drawGate(!hasKeycard);
        if (currentRoom == OFFICE && keycardAvailable) drawKeycard();

        cout << "\n" << BOLD << MAGENTA << "[" << roomNames[currentRoom] << "]" << RESET << endl;
        cout << YELLOW << roomDescriptions[currentRoom] << RESET << endl;

        if (currentRoom == OFFICE && keycardAvailable) {
            cout << BOLD << BLUE << "A BLUE MASTER KEYCARD is on the desk." << RESET << endl;
        }

        cout << CYAN << "Exits: ";
        for (int dir = 0; dir < NUM_DIRECTIONS; dir++) {
            if (connections[currentRoom][dir] != -1) cout << DIRECTION_NAMES[dir] << " ";
        }
        cout << "\n(north, south, east, west, take, quit)" << RESET << endl;

        string command;
        cout << "> ";
        cin >> command;

        int nextRoom = -1;
        if (command == "north" || command == "n") nextRoom = connections[currentRoom][NORTH];
        else if (command == "east" || command == "e") nextRoom = connections[currentRoom][EAST];
        else if (command == "south" || command == "s") nextRoom = connections[currentRoom][SOUTH];
        else if (command == "west" || command == "w") nextRoom = connections[currentRoom][WEST];
        
        if (nextRoom != -1) {
            if (nextRoom == GATE && !hasKeycard) {
                cout << RED << "\a\n*** The Gate is locked! INSERT KEYCARD ***" << RESET << endl;
            } else {
                currentRoom = nextRoom;
                if (currentRoom == GATE) {
                    drawGate(false);
                    cout << GREEN << BOLD << "\nYOU ARE FREE! YOU ESCAPED!" << RESET << endl;
                    gameRunning = false;
                }
            }
        } 
        else if (command == "take") {
            if (currentRoom == OFFICE && keycardAvailable) {
                cout << GREEN << "You pocket the MASTER KEYCARD!" << RESET << endl;
                hasKeycard = true;
                keycardAvailable = false;
            } else {
                cout << "Nothing to take here." << endl;
            }
        }
        else if (command == "quit" || command == "q") {
            gameRunning = false;
        } else {
            cout << RED << "You can't go that way." << RESET << endl;
        }
    }

    cout << BOLD << "\nGame Over." << RESET << endl;
    return 0;
}
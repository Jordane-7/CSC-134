// CSC 134
// M6T1
// Jordane
// 4/13/2026


#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Define constants for directions
enum Direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3,
    NUM_DIRECTIONS = 4
};

// Direction strings for output
const string DIRECTION_NAMES[NUM_DIRECTIONS] = {
    "north", "east", "south", "west"
};

// Define constants for rooms
enum Room {
    TOWN = 0,
    BLACKSMITH = 1,
    FOREST = 2,
    LAKE = 3,
    RUINS = 4,
    CAVE = 5,
    HILLS = 6,
    DUNGEON = 7,
    CRYPT = 8,
    NUM_ROOMS = 9
};

int main() {
    // Room names array
    string roomNames[NUM_ROOMS] = {
        "Town",
        "Blacksmith",
        "Forest",
        "Lake",
        "Ruins",
        "Cave",
        "Hills",
        "Dungeon",
        "Crypt"
    };
    
    // Room descriptions array
    string roomDescriptions[NUM_ROOMS] = {
        "You stand in the town square. The area feels safe, but the road ahead looks dangerous.",
        "The blacksmith's forge burns bright. Weapons and armor line the walls. You might improve your gear here.",
        "Tall trees surround you in the forest. You hear rustling nearby, like something is watching you.",
        "A quiet lake reflects the sky. The calm water hides unknown depths.",   
        "Crumbling stone ruins lie here. The remains of an ancient civilization... and something still moves among them.",       
        "A dark cave stretches before you. The air is cold, and distant sounds echo from within.",       
        "Rolling hills extend into the distance. It's quiet here, almost too quiet."        
        "You enter a deep dungeon. The air is heavy, and danger feels close. This is no ordinary place.",       
        "An ancient crypt filled with bones and decay. A powerful presence lingers in the darkness."
    };
    
    // Adjacency list using a 2D array
    // connections[from_room][direction] = to_room or -1 if no connection
    int connections[NUM_ROOMS][NUM_DIRECTIONS];
    
    // Initialize all connections to -1 (no connection)
    for (int i = 0; i < NUM_ROOMS; i++) {
        for (int j = 0; j < NUM_DIRECTIONS; j++) {
            connections[i][j] = -1;
        }
    }
    
    // TOWN connections
    // TOWN
    connections[TOWN][NORTH] = FOREST;
    connections[TOWN][WEST] = LAKE;
    connections[TOWN][EAST] = BLACKSMITH;
    connections[TOWN][SOUTH] = CAVE;

    // BLACKSMITH
    connections[BLACKSMITH][WEST] = TOWN;
    connections[BLACKSMITH][SOUTH] = HILLS;

    // FOREST
    connections[FOREST][SOUTH] = TOWN;

    // LAKE
    connections[LAKE][EAST] = TOWN;
    connections[LAKE][SOUTH] = RUINS;

    // RUINS
    connections[RUINS][NORTH] = LAKE;
    connections[RUINS][SOUTH] = DUNGEON;

    // CAVE
    connections[CAVE][NORTH] = TOWN;
    connections[CAVE][SOUTH] = CRYPT;

    // HILLS
    connections[HILLS][NORTH] = BLACKSMITH;

    // DUNGEON
    connections[DUNGEON][NORTH] = RUINS;
    connections[DUNGEON][EAST] = CRYPT;

    // CRYPT
    connections[CRYPT][NORTH] = CAVE;
    connections[CRYPT][WEST] = DUNGEON;


    // Game state
    int currentRoom = TOWN; // Start in the Town
    bool gameRunning = true;
    
    // Game loop
    while (gameRunning) {
        // Display current room information
        cout << "\nYou are in the " << roomNames[currentRoom] << endl;
        cout << roomDescriptions[currentRoom] << endl;
        
        // Show available exits
        cout << "Exits: ";
        bool hasExits = false;
        for (int dir = 0; dir < NUM_DIRECTIONS; dir++) {
            if (connections[currentRoom][dir] != -1) {
                cout << DIRECTION_NAMES[dir] << " ";
                hasExits = true;
            }
        }
        if (!hasExits) {
            cout << "none";
        }
        cout << endl;
        
        // Get player input
        string command;
        cout << "\nWhat would you like to do? ";
        cin >> command;
        
        // Process movement commands
        if (command == "north" || command == "n") {
            if (connections[currentRoom][NORTH] != -1) {
                currentRoom = connections[currentRoom][NORTH];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "east" || command == "e") {
            if (connections[currentRoom][EAST] != -1) {
                currentRoom = connections[currentRoom][EAST];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "south" || command == "s") {
            if (connections[currentRoom][SOUTH] != -1) {
                currentRoom = connections[currentRoom][SOUTH];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "west" || command == "w") {
            if (connections[currentRoom][WEST] != -1) {
                currentRoom = connections[currentRoom][WEST];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "quit" || command == "q") {
            gameRunning = false;
        } else {
            cout << "I don't understand that command." << endl;
        }
    }
    
    cout << "Thanks for playing!" << endl;
    return 0;
}
// CSC 134
// M7Lab1
// Jordane
// 5/11/2025



#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

// Direction constants and bitmask flags
enum Direction {
    NORTH = 1,
    SOUTH = 2,
    EAST  = 4,
    WEST  = 8
};

// Mapping of direction to cell offset {col, row}
const std::pair<int, int> DIRECTION_OFFSETS[] = {
    {0, 0},   // 0
    {0, -1},  // 1: NORTH
    {0, 1},   // 2: SOUTH
    {0, 0},   // 3
    {1, 0},   // 4: EAST
    {0, 0}, {0, 0}, {0, 0},
    {-1, 0}   // 8: WEST
};

// Mapping of directions to their opposites
const Direction OPPOSITES[] = {
    (Direction)0, SOUTH, NORTH, (Direction)0, WEST, 
    (Direction)0, (Direction)0, (Direction)0, EAST
};

class Cell {
private:
    int row, col;
    int links; 

public:
    Cell(int r, int c) : row(r), col(c), links(0) {}
    int getRow() const { return row; }
    int getCol() const { return col; }
    bool linked(Direction direction) const { return (links & direction) != 0; }
    void link(Direction direction) { links |= direction; }
};

class Grid {
private:
    int rows, cols;
    std::vector<std::vector<Cell>> cells;
    std::mt19937 rng;

public:
    Grid(int rows, int cols) : rows(rows), cols(cols) {
        rng.seed(static_cast<unsigned int>(std::time(nullptr)));
        for (int r = 0; r < rows; r++) {
            cells.emplace_back();
            for (int c = 0; c < cols; c++) {
                cells[r].emplace_back(r, c);
            }
        }
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }
    bool isValid(int r, int c) const { return r >= 0 && r < rows && c >= 0 && c < cols; }

    Cell& at(int r, int c) { return cells[r][c]; }
    const Cell& at(int r, int c) const { return cells[r][c]; }

    int random(int min, int max) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }

    void linkCells(int r1, int c1, Direction dir) {
        int r2 = r1 + DIRECTION_OFFSETS[dir].second;
        int c2 = c1 + DIRECTION_OFFSETS[dir].first;
        if (isValid(r1, c1) && isValid(r2, c2)) {
            at(r1, c1).link(dir);
            at(r2, c2).link(OPPOSITES[dir]);
        }
    }

    void display() const {
        for (int c = 0; c < cols; c++) cout << "+---";
        cout << "+" << endl;

        for (int r = 0; r < rows; r++) {
            string top = "|";
            string bottom = "+";
            for (int c = 0; c < cols; c++) {
                top += "   "; 
                top += (at(r, c).linked(EAST)) ? " " : "|";
                bottom += (at(r, c).linked(SOUTH)) ? "   +" : "---+";
            }
            cout << top << endl << bottom << endl;
        }
    }
};

// --- ALGORITHM 1: Binary Tree ---
class BinaryTreeMaze {
public:
    static void generate(Grid& grid) {
        for (int r = 0; r < grid.getRows(); r++) {
            for (int c = 0; c < grid.getCols(); c++) {
                std::vector<Direction> neighbors;
                if (r > 0) neighbors.push_back(NORTH);
                if (c < grid.getCols() - 1) neighbors.push_back(EAST);

                if (!neighbors.empty()) {
                    Direction dir = neighbors[grid.random(0, neighbors.size() - 1)];
                    grid.linkCells(r, c, dir);
                }
            }
        }
    }
};

// --- ALGORITHM 2: Recursive Backtracker (The New Feature) ---
class RecursiveBacktracker {
public:
    static void generate(Grid& grid) {
        std::stack<pair<int, int>> stack;
        std::vector<std::vector<bool>> visited(grid.getRows(), std::vector<bool>(grid.getCols(), false));

        int startR = grid.random(0, grid.getRows() - 1);
        int startC = grid.random(0, grid.getCols() - 1);

        stack.push({startR, startC});
        visited[startR][startC] = true;

        while (!stack.empty()) {
            pair<int, int> current = stack.top();
            int r = current.first;
            int c = current.second;

            std::vector<Direction> neighbors;
            if (r > 0 && !visited[r - 1][c]) neighbors.push_back(NORTH);
            if (r < grid.getRows() - 1 && !visited[r + 1][c]) neighbors.push_back(SOUTH);
            if (c < grid.getCols() - 1 && !visited[r][c + 1]) neighbors.push_back(EAST);
            if (c > 0 && !visited[r][c - 1]) neighbors.push_back(WEST);

            if (neighbors.empty()) {
                stack.pop();
            } else {
                Direction dir = neighbors[grid.random(0, neighbors.size() - 1)];
                grid.linkCells(r, c, dir);
                int nextR = r + DIRECTION_OFFSETS[dir].second;
                int nextC = c + DIRECTION_OFFSETS[dir].first;
                visited[nextR][nextC] = true;
                stack.push({nextR, nextC});
            }
        }
    }
};

void print_help(const char* prog) {
    cout << "Usage: " << prog << " [rows] [cols] [option]\n"
         << "Options:\n"
         << "  --bt    Use Binary Tree algorithm (default)\n"
         << "  --rb    Use Recursive Backtracker algorithm (more complex mazes)\n"
         << "  -h      Show help\n";
}

int main(int argc, char* argv[]) {
    int rows = 10, cols = 10;
    bool useRB = false;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help(argv[0]);
            return 0;
        }
        if (strcmp(argv[i], "--rb") == 0) useRB = true;
    }

    if (argc > 1 && argv[1][0] != '-') rows = atoi(argv[1]);
    if (argc > 2 && argv[2][0] != '-') cols = atoi(argv[2]);

    Grid grid(rows, cols);

    if (useRB) {
        RecursiveBacktracker::generate(grid);
    } else {
        BinaryTreeMaze::generate(grid);
    }

    grid.display();
    return 0;
}
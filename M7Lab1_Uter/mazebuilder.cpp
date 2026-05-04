#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
#include <cstdlib>

using namespace std;

// ================= DIRECTIONS =================
enum Direction { NORTH, SOUTH, EAST, WEST };

const pair<int,int> OFFSETS[] = {
    {0,-1},   // NORTH
    {0,1},    // SOUTH
    {1,0},    // EAST
    {-1,0}    // WEST
};

// ================= CELL =================
class Cell {
    int r, c;
    vector<Direction> links;

public:
    Cell(int r=0, int c=0) : r(r), c(c) {}

    int getRow() const { return r; }
    int getCol() const { return c; }

    void link(Direction d) {
        if (!linked(d)) links.push_back(d);
    }

    bool linked(Direction d) const {
        return find(links.begin(), links.end(), d) != links.end();
    }

    const vector<Direction>& getLinks() const {
        return links;
    }
};

// ================= GRID =================
class Grid {
    int rows, cols;
    vector<vector<Cell>> cells;

public:
    Grid(int r, int c) : rows(r), cols(c) {
        cells.resize(rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cells[i].emplace_back(i, j);
            }
        }
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    bool valid(int r, int c) const {
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }

    Cell& at(int r, int c) {
        return cells[r][c];
    }

    const Cell& at(int r, int c) const {
        return cells[r][c];
    }

    // ================= SOLID DISPLAY =================
    void display() const {
        cout << "┏";
        for (int c = 0; c < cols; c++) cout << "━━━┳";
        cout << "\n";

        for (int r = 0; r < rows; r++) {

            cout << "┃";
            for (int c = 0; c < cols; c++) {
                cout << "   ";
                if (c < cols - 1 && at(r,c).linked(EAST))
                    cout << " ";
                else
                    cout << "┃";
            }
            cout << "\n";

            if (r < rows - 1) {
                cout << "┣";
                for (int c = 0; c < cols; c++) {
                    if (at(r,c).linked(SOUTH))
                        cout << "   ┼";
                    else
                        cout << "━━━┼";
                }
                cout << "\n";
            }
        }

        cout << "┗";
        for (int c = 0; c < cols; c++) cout << "━━━┻";
        cout << "\n";
    }
};

// ================= SIMPLE MAZE =================
class BinaryTreeMaze {
public:
    static void on(Grid& g) {
        srand(time(NULL));

        for (int r = 0; r < g.getRows(); r++) {
            for (int c = 0; c < g.getCols(); c++) {

                vector<Direction> opts;

                if (g.valid(r, c + 1)) opts.push_back(EAST);
                if (g.valid(r + 1, c)) opts.push_back(SOUTH);

                if (!opts.empty()) {
                    Direction d = opts[rand() % opts.size()];

                    Cell& cell = g.at(r,c);

                    int nr = r + OFFSETS[d].second;
                    int nc = c + OFFSETS[d].first;

                    Cell& n = g.at(nr,nc);

                    cell.link(d);

                    if (d == EAST) n.link(WEST);
                    if (d == SOUTH) n.link(NORTH);
                }
            }
        }
    }
};

// ================= DISTANCE GRID =================
class Distances {
    vector<vector<int>> dist;

public:
    Distances(int r, int c) {
        dist.assign(r, vector<int>(c, numeric_limits<int>::max()));
    }

    int get(int r, int c) const {
        return dist[r][c];
    }

    void set(int r, int c, int v) {
        dist[r][c] = v;
    }
};

// ================= DIJKSTRA =================
class Dijkstra {
public:
    static Distances run(Grid& g, Cell& start) {

        Distances d(g.getRows(), g.getCols());

        using Node = pair<int, Cell*>;
        priority_queue<Node, vector<Node>, greater<Node>> pq;

        d.set(start.getRow(), start.getCol(), 0);
        pq.push({0, &start});

        while (!pq.empty()) {

            auto [dist, cell] = pq.top();
            pq.pop();

            int r = cell->getRow();
            int c = cell->getCol();

            if (dist > d.get(r,c)) continue;

            for (Direction dir : cell->getLinks()) {

                int nr = r + OFFSETS[dir].second;
                int nc = c + OFFSETS[dir].first;

                if (!g.valid(nr,nc)) continue;

                int nd = dist + 1;

                if (nd < d.get(nr,nc)) {
                    d.set(nr,nc,nd);
                    pq.push({nd, &g.at(nr,nc)});
                }
            }
        }

        return d;
    }

    static vector<Cell*> path(Grid& g, Cell& start, Cell& end) {

        Distances d = run(g, start);

        if (d.get(end.getRow(), end.getCol()) == numeric_limits<int>::max())
            return {};

        vector<Cell*> p;
        Cell* cur = &end;

        while (cur != &start) {

            p.push_back(cur);

            int r = cur->getRow();
            int c = cur->getCol();

            Cell* next = nullptr;
            int best = d.get(r,c);

            for (Direction dir : cur->getLinks()) {

                int nr = r + OFFSETS[dir].second;
                int nc = c + OFFSETS[dir].first;

                if (!g.valid(nr,nc)) continue;

                int val = d.get(nr,nc);

                if (val < best) {
                    best = val;
                    next = &g.at(nr,nc);
                }
            }

            if (!next) break;
            cur = next;
        }

        p.push_back(&start);
        reverse(p.begin(), p.end());
        return p;
    }
};

// ================= PATH DISPLAY =================
void showPath(Grid& g, vector<Cell*> path) {

    auto isPath = [&](Cell* c) {
        return find(path.begin(), path.end(), c) != path.end();
    };

    cout << "┏";
    for (int c = 0; c < g.getCols(); c++) cout << "━━━┳";
    cout << "\n";

    for (int r = 0; r < g.getRows(); r++) {

        cout << "┃";

        for (int c = 0; c < g.getCols(); c++) {

            if (isPath(&g.at(r,c))) cout << " X ";
            else cout << "   ";

            if (c < g.getCols()-1 && g.at(r,c).linked(EAST))
                cout << " ";
            else
                cout << "┃";
        }

        cout << "\n";

        if (r < g.getRows()-1) {
            cout << "┣";
            for (int c = 0; c < g.getCols(); c++) {
                if (g.at(r,c).linked(SOUTH))
                    cout << "   ┼";
                else
                    cout << "━━━┼";
            }
            cout << "\n";
        }
    }

    cout << "┗";
    for (int c = 0; c < g.getCols(); c++) cout << "━━━┻";
    cout << "\n";
}

// ================= MAIN =================
int main(int argc, char* argv[]) {

    int r = 10, c = 10;

    if (argc > 1) r = atoi(argv[1]);
    if (argc > 2) c = atoi(argv[2]);

    Grid g(r,c);
    BinaryTreeMaze::on(g);

    cout << "MAZE:\n";
    g.display();

    auto p = Dijkstra::path(g, g.at(0,0), g.at(r-1,c-1));

    cout << "\nSOLUTION:\n";
    showPath(g, p);

    cout << "\nPath length: " << p.size() << "\n";
}
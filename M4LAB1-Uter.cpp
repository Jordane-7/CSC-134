// CSC 134
// M4T1
// Jordane
// 3/6/2026

#include <iostream>
using namespace std;


int main() {
    int height = 5;
    int width = 5;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
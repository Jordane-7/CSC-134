// Jordane
// M5T2 - Functions
// 3/23/26

#include <iostream>
using namespace std;
#include "M5T2.U.h"

int main()
{
    cout << "Num \tSquare" << endl;
    int start = 1;
    int finish = 10;
    for (int i=start; i <= finish; i++) {
        int sq = square (i);
        print_tabele_line(1,sq);
    }

    return 0;



}

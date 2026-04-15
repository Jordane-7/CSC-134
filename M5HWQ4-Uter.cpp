// CSC 134
// M5HW1 Q4 - Gold
// Jordane
// 4/1/2026

#include <iostream>
using namespace std;

int choice;
double radius, area_cir, area_rec, area_tri, length_rec, width_rec, base_tri,height_tri ;

int main (){
    cout << " Welcome to the Geometry Calculator choose an option \n 
        1. Calculate the Area of a Circle \n
        2. Calculate the Area of a Rectangle\n
        3. Calculate the Area of a Triangle\n
        4. Quit" << endl;
    
    cin >> choice;

    if (chocie == 1){
        cout << "Please enter the radius of the circle" << endl;
        cin >> radius;

        area_cir = (radius * radius) * 3.14159
        cout << "The area of the circle is " << area_cir << endl;

    }
    else if ( choice == 2){
         cout << "Please enter length of the rectangle " << endl;
        cin >> length_rec;

         cout << "Please enter width of the rectangle " << endl;
        cin >> width_rec;

        area_rec = width_rec * length_rec
        cout << "The area of the rectangle is " << area_rec << endl;

    }
    else if (choice == 3){
         cout << "Please enter length of the traingle's base " << endl;
        cin >> base_tri;

         cout << "Please enter width of the trianlge's height " << endl;
        cin >> height_tri;

        area_tri = base_tri * height_tri * .5
        cout << "The area of the triangle is " << area_tri << endl;

    }

    
return 0;
}
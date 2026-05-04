// CSC 134
// M7T1 - restaurant reviews
// Jordane
// 1/21/2025


#include <iostream>
using namespace std;

class Restaurant {
private:
    string name;
    double rating;

public:
    Restaurant(string n, double r) {
        name = n;
        rating = r;
    }

    void setName(string n) {
        name = n;
    }

    void setRating(double r) {
        rating = r;
    }

    string getName() const {
        return name;
    }

    double getRating() const {
        return rating;
    }

    void display() const {
        cout << name << ": ";
        
        int fullStars = static_cast<int>(rating); 
        bool hasHalfStar = (rating - fullStars) >= 0.5;

        for (int i = 0; i < fullStars; i++) {
            cout << "⭐";
        }

        if (hasHalfStar) {
            cout << "✨";
        }

        cout << " (" << rating << "/5)" << endl;
    }
};

int main() {

    cout << "Restaurant Reviews" << endl;

    // Create THREE restaurants with your own values
    Restaurant rest1("Miyabi Japanese Steak & Seafood House", 4.4);
    Restaurant rest2("Olive Garden", 3.8);
    Restaurant rest3("Chick-fil-A", 4.7);

    // Display all three
    rest1.display();
    rest2.display();
    rest3.display();

    return 0;
}
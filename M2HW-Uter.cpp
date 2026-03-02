// CSC 134
// M3HW1 - Gold
// Jordane Uter
// 3/2/2026

#include <iostream>
using namespace std;

int main() {
    // Question 1
    cout << "Question 1" << endl;

    cout << "Hello, I'm a C++ program!" << endl;
    cout << "How are you today? Please type happy, sad, tired, excited, or something else." << endl;

    string user_feeling;
    getline(cin, user_feeling); // Reads the full line, including spaces

    if (user_feeling == "happy"|| user_feeling == "Happy") {
        cout << "That's great to hear! Keep up the positive vibes!" << endl;
    } 
    else if (user_feeling == "sad"|| user_feeling == "Sad") {
        cout << "I'm sorry to hear that. I hope your day gets better!" << endl;
    }
    else if (user_feeling == "tired" || user_feeling == "Tired") {
        cout << "I'm sorry to hear that. I hope you get some rest soon!" << endl;
    } 
    else if (user_feeling == "excited" || user_feeling == "Excited") {
        cout << "That's exciting! I hope you enjoy your excitement!" << endl;
    }
    else if (user_feeling == "something else"|| user_feeling == "Something else") {
        cout << "I see, thanks for sharing. I hope your day improves!" << endl;
    } 
    else {
        cout << "I didn't understand that. Please type happy, sad, tired, excited, or something else." << endl;
    }

    cout << "Thanks for sharing! I hope your day goes well." << endl;

    return 0;

}
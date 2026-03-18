#include <iostream>

using namespace std;

// Jordane Uter
// 3/18/2026
// M5T1 ; Simple Functions

// Declare our Functions
void say_hello();
int get_answer();
int double_a_num (int number);

// Write Main ()
int main()
{
    say_hello();
    cout << "The answer is : " << get_answer() << endl;
    cout << "Type in an integer: ";
    int num;
    cin>> num;
    int answer = double_a_num(num);
    cout << "Double that number is: " << answer << endl;
    return 0;
}

void say_hello (){
    cout << "Hello world!" << endl;

}

int get_answer (){
    return 42;
}

int double_a_num (int number) {
    int answer = number * 2;
    return answer;
}

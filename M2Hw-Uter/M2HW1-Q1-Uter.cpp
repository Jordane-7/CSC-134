// CSC 134
// M2HW1 - Gold
// Jordane
// 2/11/2026

#include <iostream>
using namespace std;

int main (){

    string name;
    double acc_balance, amount_depo, amount_with, final_balance;

    // Inputs
    cout << "Hello wat is your name? ";
    cin >> name;
    cout << "What is the current account balance? $";
    cin >> acc_balance;
    cout << "How much would you like to deposit? $";
    cin >> amount_depo;
    cout << "How much would you like to withdrawl? $";
    cin >> amount_with;

 // Calculations

if (amount_depo > 0 && amount_with > 0) {
    final_balance = acc_balance + amount_depo - amount_with;
}
else if (amount_depo > 0) {
    final_balance = acc_balance + amount_depo;
}
else if (amount_with > 0) {
    final_balance = acc_balance - amount_with;
}
else {
    final_balance = acc_balance;
}
    // Final
    cout << "\n========= RECEIPT =========\n";
    cout << "Hello " << name << "\n" << endl;
    cout << "Account number: 5839201746"  << "\n" <<  endl;
    cout << "Account balance: $" << final_balance << "\n" << endl;
    cout << "===========================\n";
    return 0;

}
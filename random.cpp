#include <iostream>
#include <ctime> 
#include <cstdlib> 
using namespace std;

int main() {
    int chances = 5;
    int userChoice;
    cout << "Guess the number between 0 to 100: " << endl;
    srand(time(0));
    int num = (rand() % 100) + 1;

    bool flag = true;
    int i = 0;
    while (i < chances) {
        cin >> userChoice;

        if (userChoice >= 0 && userChoice <= 100) {
            if (userChoice == num) {
                cout << "You guessed the correct number! The correct number is: " << num << endl;
                break;
            } else if (userChoice < num) {
                cout << "Your number is too low, please enter a larger number." << endl;
            } else {
                cout << "Your number is too high, please enter a smaller number." << endl;
            }
            i++;
        } 
        else {
            cout << "Invalid number!" << endl;
        }

        if (i == chances) {
            cout << "You've used all your chances. The correct number was: " << num << endl;
        }
    }

    return 0;
}

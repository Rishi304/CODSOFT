#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{

    srand(time(0));

    int numberToGuess = rand() % 100 + 1;
    int userGuess = 0;
    int numberOfTries = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have a Number Between 1 to 100" << endl;
    cout << "Can you guess what it is?" << endl;

    while (userGuess != numberToGuess)
    {
        cout << "Please Enter your guess: ";
        cin >> userGuess;
        numberOfTries++;

        if (abs(userGuess - numberToGuess) <= 5 && userGuess != numberToGuess)
        {
            cout << "You Are Very close!!!" << endl;
        }

        if (userGuess > numberToGuess)
        {
            cout << "Too high! Try Guessing a Smaller Number." << endl;
        }
        else if (userGuess < numberToGuess)
        {
            cout << "Too low! Try Guessing a Bigger Number." << endl;
        }
        else
        {
            cout << "Congratulations! I Knew You Are the Chosen One!! " << endl;
            cout << "Number Of Attempts ->" << numberOfTries << endl;
        }
    }

    return 0;
}

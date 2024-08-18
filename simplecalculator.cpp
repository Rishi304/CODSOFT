#include <iostream>
#include <cmath>
#include <limits>
#include <math.h>

using namespace std;

void displayMenu()
{
    cout << "\nWhat would you like to do today?" << endl;
    cout << "1. Add (a + b)" << endl;
    cout << "2. Subtract (a - b)" << endl;
    cout << "3. Multiply (a * b)" << endl;
    cout << "4. Divide (a / b)" << endl;
    cout << "5. Power (a^b)" << endl;
    cout << "6. Modulus (a % b)" << endl;
    cout << "7. Exit" << endl;
    cout << "Please enter the number to perform the operation of your choice: ";
}

void getNumbers(double &a, double &b)
{
    cout << "Please enter the first number: ";
    while (!(cin >> a))
    {
        cout << "Oops! That doesn't look like a number. Please try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Great! Now enter the second number: ";
    while (!(cin >> b))
    {
        cout << "Hmm, that's not a valid number. Let's try that again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void calculate(int choice)
{
    double a = 0, b = 0;
    getNumbers(a, b);

    switch (choice)
    {
    case 1:
        cout << "Alright, let's add " << a << " and " << b << ". The result is: " << (a + b) << endl;
        break;
    case 2:
        cout << "Subtracting " << b << " from " << a << ". The result is: " << (a - b) << endl;
        break;
    case 3:
        cout << "Multiplying " << a << " and " << b << ". The result is: " << (a * b) << endl;
        break;
    case 4:
        if (b != 0)
            cout << "Dividing " << a << " by " << b << ". The result is: " << (a / b) << endl;
        else
            cout << "Oops! Division by zero is not allowed. Let's try something else." << endl;
        break;
    case 5:
        cout << "Raising " << a << " to the power of " << b << ". The result is: " << pow(a, b) << endl;
        break;
    case 6:
        if (static_cast<int>(b) != 0)
            cout << "Finding modulus of " << a << " by " << b << ". The result is: " << static_cast<int>(a) % static_cast<int>(b) << endl;
        else
            cout << "Division by zero is not allowed in modulus. Let's try again." << endl;
        break;
    default:
        cout << "That option doesn't seem to exist. Let's pick a valid one!" << endl;
    }
}

int main()
{
    cout << "Hello! Welcome to your friendly calculator." << endl;
    int choice = 0;

    while (choice != 7)
    {
        displayMenu();
        while (!(cin >> choice))
        {
            cout << "That doesn't seem right. Please enter a valid number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (choice == 7)
        {
            cout << "Thank you for using the calculator. Have a great day!" << endl;
            break;
        }

        calculate(choice);
    }

    return 0;
}

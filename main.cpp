#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Main loop to keep the program running until user exits
    while (true)
    {
        // Declare variables for numbers and operation choice
        double firstNumber, secondNumber;
        int userChoice;

        // Display menu for operations
        cout << "\nSelect an operation:\n";
        cout << "1: Addition\n2: Subtraction\n3: Multiplication\n4: Division\n5: Square Root\n6: EXIT\n";

        // Prompt user for operation choice
        cout << "-> ";
        cin >> userChoice;

        // If user doesn't choose to exit
        if (userChoice != 6) {
            // Prompt for first number
            cout << "\nEnter the first number:\n";
            cout << "-> ";
            cin >> firstNumber;

            // Calculate square root if chosen
            if (userChoice == 5) {
                cout << "\nResult: " << sqrt(firstNumber) << endl;
            }
            else {
                // Prompt for second number for other operations
                cout << "\nEnter the second number:\n";
                cout << "-> ";
                cin >> secondNumber;

                // Perform selected operation
                switch (userChoice) {
                    case 1:
                        cout << "\nResult: " << firstNumber + secondNumber << endl; // Addition
                        break;
                    case 2:
                        cout << "\nResult: " << firstNumber - secondNumber << endl; // Subtraction
                        break;
                    case 3:
                        cout << "\nResult: " << firstNumber * secondNumber << endl; // Multiplication
                        break;
                    case 4:
                        if (secondNumber != 0)
                            cout << "\nResult: " << firstNumber / secondNumber << endl; // Division (check for division by zero)
                        else
                            cout << "\nCannot divide by zero!\n";
                        break;
                    default:
                        cout << "\nInvalid operation.\n";
                        break;
                }
            }
        }
        else {
            // Exit the program if user chooses
            cout << "Exiting the program. Goodbye!\n";
            return 0;
        }
    }
}

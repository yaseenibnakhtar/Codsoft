#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class NumberGuessingGame {
private:
    int playerPoints;

public:
    NumberGuessingGame() : playerPoints(0) {}

    void start() {
        int choice;
        srand(time(0));

        cout << "*** Welcome to the Number Guessing Game ***\n";
        cout << "You will have 5 attempts to guess the number between 1 and 100.\n";

        int randomNumber = generateRandomNumber();

        for (int attempts = 0; attempts < 5; ++attempts) {
            cout << "Attempt " << attempts + 1 << ": Enter your guess: ";
            int guess;
            cin >> guess;

            if (guess == randomNumber) {
                cout << "Congratulations! You guessed the correct number!\n";
                playerPoints += 10;
                break;
            } else if (guess < randomNumber) {
                cout << "Too low! Try again.\n";
            } else {
                cout << "Too high! Try again.\n";
            }
        }

        if (playerPoints == 0) {
            cout << "Sorry, you've used all your attempts. The correct number was: " << randomNumber << endl;
        }

        cout << "Total Points: " << playerPoints << endl;
    }

private:
    int generateRandomNumber() {
        return rand() % 100 + 1;
    }
};

int main() {
    NumberGuessingGame game;
    game.start();
    return 0;
}


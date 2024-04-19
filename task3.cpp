#include <iostream>
#include <cstring>
using namespace std;

// Function prototype for checking game state
short checkGame(char& a1, char& a2, char& a3, char& b1, char& b2, char& b3, char& c1, char& c2, char& c3, short turncount);

int main() {
    char player1Name[30], player2Name[30];
    char a1='?', a2='?', a3='?', b1='?', b2='?', b3='?', c1='?', c2='?', c3='?';
    char position[10];
    short currentPlayer=1, gameState=0, turnCount=0;

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Please enter the name for Player 1 (X): ";
    cin.getline(player1Name, 30);

    cout << "Please enter the name for Player 2 (O): ";
    cin.getline(player2Name, 30);

    while (gameState == 0) {
        // Display current game board
        cout << " " << a1 << " | " << a2 << " | " << a3 << endl;
        cout << "-----------" << endl;
        cout << " " << b1 << " | " << b2 << " | " << b3 << endl;
        cout << "-----------" << endl;
        cout << " " << c1 << " | " << c2 << " | " << c3 << endl;

        turnCount++;
        cout << "Turn " << turnCount << ": ";

        // Determine current player and prompt for input
        if (currentPlayer == 1) {
            cout << player1Name << ", enter your move (row,column): ";
        } else {
            cout << player2Name << ", enter your move (row,column): ";
        }

        cin >> position;

        // Process player move based on input
        char playerSymbol = (currentPlayer == 1) ? 'X' : 'O';
        if (strcmp(position, "1,1") == 0 && a1 == '?') a1 = playerSymbol;
        else if (strcmp(position, "1,2") == 0 && a2 == '?') a2 = playerSymbol;
        else if (strcmp(position, "1,3") == 0 && a3 == '?') a3 = playerSymbol;
        else if (strcmp(position, "2,1") == 0 && b1 == '?') b1 = playerSymbol;
        else if (strcmp(position, "2,2") == 0 && b2 == '?') b2 = playerSymbol;
        else if (strcmp(position, "2,3") == 0 && b3 == '?') b3 = playerSymbol;
        else if (strcmp(position, "3,1") == 0 && c1 == '?') c1 = playerSymbol;
        else if (strcmp(position, "3,2") == 0 && c2 == '?') c2 = playerSymbol;
        else if (strcmp(position, "3,3") == 0 && c3 == '?') c3 = playerSymbol;
        else {
            cout << "Invalid move! Please try again." << endl;
            continue;  // Skip to next iteration of the loop
        }

        // Switch to the next player
        currentPlayer = (currentPlayer == 1) ? 2 : 1;

        // Check game state after each move
        gameState = checkGame(a1, a2, a3, b1, b2, b3, c1, c2, c3, turnCount);
    }

    // Display final game board
    cout << "Final board:" << endl;
    cout << " " << a1 << " | " << a2 << " | " << a3 << endl;
    cout << "-----------" << endl;
    cout << " " << b1 << " | " << b2 << " | " << b3 << endl;
    cout << "-----------" << endl;
    cout << " " << c1 << " | " << c2 << " | " << c3 << endl;

    // Determine game outcome
    if (gameState == 1) {
        cout << "Congratulations, " << player1Name << "! You win!" << endl;
    } else if (gameState == 2) {
        cout << "Congratulations, " << player2Name << "! You win!" << endl;
    } else {
        cout << "It's a draw! Well played, both players." << endl;
    }

    return 0;
}

// Function to check game state
short checkGame(char& a1, char& a2, char& a3, char& b1, char& b2, char& b3, char& c1, char& c2, char& c3, short turncount) {
    // Winning conditions for 'X'
    if ((a1 == a2 && a2 == a3 && a1 == 'X') ||
        (b1 == b2 && b2 == b3 && b1 == 'X') ||
        (c1 == c2 && c2 == c3 && c1 == 'X') ||
        (a1 == b1 && b1 == c1 && a1 == 'X') ||
        (a2 == b2 && b2 == c2 && a2 == 'X') ||
        (a3 == b3 && b3 == c3 && a3 == 'X') ||
        (a1 == b2 && b2 == c3 && a1 == 'X') ||
        (a3 == b2 && b2 == c1 && a3 == 'X')) {
        return 1;  // Player X wins
    }

    // Winning conditions for 'O'
    if ((a1 == a2 && a2 == a3 && a1 == 'O') ||
        (b1 == b2 && b2 == b3 && b1 == 'O') ||
        (c1 == c2 && c2 == c3 && c1 == 'O') ||
        (a1 == b1 && b1 == c1 && a1 == 'O') ||
        (a2 == b2 && b2 == c2 && a2 == 'O') ||
        (a3 == b3 && b3 == c3 && a3 == 'O') ||
        (a1 == b2 && b2 == c3 && a1 == 'O') ||
        (a3 == b2 && b2 == c1 && a3 == 'O')) {
        return 2;  // Player O wins
    }

    // Check for draw
    if (turncount == 9) {
        return -1;  // Draw
    }

    return 0;  // Game still ongoing
}

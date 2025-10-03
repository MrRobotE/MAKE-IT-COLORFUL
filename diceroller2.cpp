#include <iostream>
#include <windows.h> // For Windows console functions

// A struct to hold the roll result and its status
struct RollResult {
    int roll;
    std::string status;
};

// Function to roll a 20-sided die and determine the outcome
RollResult roll_d20() {
    RollResult result;
    // Generate a random number between 1 and 20
    result.roll = rand() % 20 + 1;
    
    // Set the status based on the roll
    if (result.roll == 1) {
        result.status = "Critical Failure";
    } else if (result.roll == 20) {
        result.status = "Critical Success";
    } else {
        result.status = "";
    }
    
    return result;
}

int main() {
    // Get a handle to the console output
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    // Seed the random number generator
    srand(time(0));
    
    // --- Get Player Names ---
    std::string player1_name;
    std::string player2_name;

    std::cout << "Enter a name for Player 1: ";
    std::getline(std::cin, player1_name);
    
    std::cout << "Enter a name for Player 2: ";
    std::getline(std::cin, player2_name);
    
    std::cout << "\nRolling a 20-sided die for " << player1_name << " and " << player2_name << "..." << std::endl;
    
    // --- Perform the Rolls ---
    RollResult player1_result = roll_d20();
    RollResult player2_result = roll_d20();
    
    // --- Display Results ---
    std::cout << "\n--- Results ---" << std::endl;
    std::cout << player1_name << " rolled: " << player1_result.roll << std::endl;
    if (!player1_result.status.empty()) {
        // Set color for the outcome
        if (player1_result.status == "Critical Failure") {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        } else if (player1_result.status == "Critical Success") {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        }
        std::cout << "Outcome: " << player1_result.status << std::endl;
        // Reset color to default white
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    
    std::cout << "\n" << player2_name << " rolled: " << player2_result.roll << std::endl;
    if (!player2_result.status.empty()) {
        // Set color for the outcome
        if (player2_result.status == "Critical Failure") {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        } else if (player2_result.status == "Critical Success") {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        }
        std::cout << "Outcome: " << player2_result.status << std::endl;
        // Reset color to default white
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    std::cout << "---" << std::endl;
    
    // --- Determine the Winner ---
    std::cout << "\n--- The Winner Is ---" << std::endl;
    if (player1_result.roll > player2_result.roll) {
        std::cout << player1_name << "!" << std::endl;
    } else if (player2_result.roll > player1_result.roll) {
        std::cout << player2_name << "!" << std::endl;
    } else {
        std::cout << "Evenly Matched!" << std::endl;
    }
    std::cout << "---" << std::endl;
    
    return 0;
}

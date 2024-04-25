#include <iostream>
#include <string>

using namespace std;

bool isCardValid(int digits[], int size) {
    int sum1 = 0, sum2 = 0;

    // Step 1: Sum every other digit starting from the rightmost
    for (int i = size - 1; i >= 0; i -= 2) {
        sum1 += digits[i];
    }

    // Step 2: Double every other digit and add the digits of the result
    for (int i = size - 2; i >= 0; i -= 2) {
        int doubled = digits[i] * 2;
        while (doubled > 0) {
            sum2 += doubled % 10;
            doubled /= 10;
        }
    }

    // Step 3: Add the sums of the two preceding steps
    int totalSum = sum1 + sum2;

    // Check if the last digit of the total sum is 0
    return (totalSum % 10 == 0);
}

bool isNumeric(string s) {
    for (char c : s) {
        if (c < '0' || c > '9') {
            return false;
        }
    }
    return true;
}

bool isCorrectLength(string s) {
    return (s.length() == 16);
}

int main() {
    string input;
    while (true) {
        cout << "Enter 16-digit credit card # or Q to quit: ";
        cin >> input;

        // Check if the user wants to quit
        if (input == "Q" || input == "q") {
            break;
        }

        // Check if input is numeric
        if (!isNumeric(input)) {
            cout << "Error - card number must contain only digits." << endl;
            continue;
        }

        // Check if input length is correct
        if (!isCorrectLength(input)) {
            cout << "Error - card number must contain 16 digits." << endl;
            continue;
        }

        // Convert input string to integer array
        int digits[16];
        for (int i = 0; i < 16; i++) {
            digits[i] = input[i] - '0'; // Convert character to integer
        }

        // Check if the card number is valid and print result
        if (isCardValid(digits, 16)) {
            cout << "Card is valid." << endl;
        }
        else {
            cout << "Card is not valid." << endl;
        }
    }
    return 0;
}


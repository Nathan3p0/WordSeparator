#include <iostream>

using namespace std;

// Function Declaration
void getUserInput(char[], int, int&);
void separateCharacters(char[], char[]);

int main()
{
    // Declare variables
    const int LENGTH = 100;
    int numOfUpperCaseLetters = 0;
    char sentenceWithoutSpaces[LENGTH];
    char *sentenceWithSpaces;

    cout << "This program separates all of the words in a sentence that start with an uppercase letter. \n";
    cout << "Enter a string containing no spaces and each word beginning with an uppercase letter: ";

    getUserInput(sentenceWithoutSpaces, LENGTH, numOfUpperCaseLetters);

    // Initialize Dynamic Char Array based on the amount of extra spaces needed.
    sentenceWithSpaces = new char[LENGTH + numOfUpperCaseLetters];

    separateCharacters(sentenceWithoutSpaces, sentenceWithSpaces);

    // Print separated sentence to user
    cout << "\n\nThe word separated string is:\n" << sentenceWithSpaces << endl;

    return 0;
}

void separateCharacters(char withoutSpaces[], char withSpaces[]) {
    int i = 0;
    int j = 0;

    // Loop through the withoutSpaces char array until null character is located
    while (withoutSpaces[i] != '\0') {
        // If the char is uppercase and not the first word then add a space before and set to lowercase
        if (isupper(withoutSpaces[i]) && i != 0) {
            withSpaces[j++] = ' ';
            withSpaces[j] = tolower(withoutSpaces[i]);
        }
        // Else add the char to withSpaces char array
        else {
            withSpaces[j] = withoutSpaces[i];
        }

        j++;
        i++;
    }

    // Add ending null character
    withSpaces[j] = 0;
}

void getUserInput(char string[], int length, int& numOfUpperCaseLetters) {
    char ch;

    ch = cin.get();

    int i = 0;

    // Accept user input until the enter key is pressed
    while (ch != '\n') {
        // Assign char input to index in char array
        string[i] = ch;

        // If the character is uppercase then increment the numOfUpperCaseLetters counter
        if (isupper(ch)) {
            numOfUpperCaseLetters++;
        }

        // If we have reached the length of the char array then break out of loop
        if (i == length - 2) {
            i++;
            break;
        }

        i++;
        ch = cin.get();
    }

    // Add ending null character
    string[i] = 0;
}
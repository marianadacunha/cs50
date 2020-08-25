#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

bool validInput(string x);

int main(int argc, string argv[])
{
    if (argc != 2 || !validInput(argv[1])) // Doesn't allor more than 2 commands or
    {
        printf("Usage: ./caesar key\n"); // Error message
        return 1; // Asks again for input
    }

    int key = atoi(argv[1]); // Converts the command line argument into an integer

    string userInput = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(userInput); i++)
    {
        char textInput = userInput[i];
        if (isalpha(textInput))
        {
            char ASCII = 'A';
            if (islower(textInput))
            {
                ASCII = 'a';
            }
            printf("%c", (textInput - ASCII + key) % 26 + ASCII); // Changing the user input to ASCII and then turning it again to letters
        }
        else
        {
            printf("%c", textInput); // This doesn't modify '!', '/', ' ', '.', '-', etc.
        }
    }
    printf("\n");
}

bool validInput(string x)
{
    for (int j = 0; j < strlen(x); j++)
    {
        if (!isdigit(x[j])) // If the input is not a digit, it's gonna return as false.
        {
            return false;
        }
        else
        {
            return true;   
        }
    }
}
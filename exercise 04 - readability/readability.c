#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string userInput = get_string("Text: "); 
    int letters = 0; // Starting from zero
    int words = 1; // Starting with one because we're counting spaces. So, if there's 1 space, there's 2 words. Hence the +1.
    int sentences = 0; // Starting from zero

    for (int i = 0; i < strlen(userInput); i++) // Running a loop through the length of the user input
    {
        if (isalpha(userInput[i]))
        {
            letters += 1; // If is a letter, let's add one
        }
        if (isspace(userInput[i]))
        {
            words += 1; // If there's a space, let's add one
        }
        if (userInput[i] == '.' || userInput[i] == '!' || userInput[i] == '?')
        {
            sentences += 1; // If there's punctuation, let's add one
        }
    }

    float L = (letters / (float) words) * 100; // Calculating letters per 100 words
    float S = (sentences / (float) words) * 100; // Calculating sentences per 100 words

    int grade = round(0.0588 * L - 0.296 * S - 15.8); // Coleman-Liau index
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }   
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }    
    else
    {
        printf("Grade %i\n", grade);
    }
}
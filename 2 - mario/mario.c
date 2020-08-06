#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int userInput;
    do 
    {
        userInput = get_int("Height: ");
    }
    while (userInput < 1 || userInput > 8); // Accepts input only between 1 and 8

    for (int newLine = 0; newLine < userInput; newLine++)
    {
        for (int hashtag = 0; hashtag < userInput; hashtag++)
        {
            if (newLine + hashtag < userInput - 1)
            {
            printf(" ");
            }
            else
            {
            printf("#");
            }
        }
        printf("\n");
    }
}
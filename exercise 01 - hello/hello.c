#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name?\n"); // Prints on the screen "What's your name?"
    printf("Hello, %s", name); // Gets the user input and prints on the screen as "Hello + input"
}
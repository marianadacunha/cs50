// In this version I'm using division instead of addition

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;

    do
    {
        dollars = get_float("How many dollars do you need in change?"); // Float is used to handle both dollars and cents
    }
    while (dollars < 0); // Doesn't accept negative numbers

    int cents = round(dollars * 100); // Turns the user input into cents instead of dollas (1 dollars is 100 cents)
    int coins = 0; // Let's begin with 0 coins

    coins += cents / 25;
    cents %= 25;
    
    coins += cents / 10;
    cents %= 10;
    
    coins += cents / 5;
    cents %= 5;
    
    coins += cents / 1;
    cents %= 1;
    
    printf("I'm going to give you %i coins\n", coins);
}
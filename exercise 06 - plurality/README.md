# Plurality

Implement a program that runs a plurality election, per the below.
```
 $ ./plurality Alice Bob Charlie
 Number of voters: 4
 Vote: Alice
 Vote: Bob
 Vote: Charlie
 Vote: Alice
 Alice
```
# Understanding

Let’s now take a look at *plurality.c* and read through the distribution code that’s been provided to you.

The line ```#define MAX 9``` is some syntax used here to mean that MAX is a constant (equal to 9) that can be used throughout the program. Here, it represents the maximum number of candidates an election can have.

The file then defines a struct called a candidate. Each candidate has two fields: a string called name representing the candidate’s name, and an int called votes representing the number of votes the candidate has. Next, the file defines a global array of candidates, where each element is itself a candidate.

Now, take a look at the main function itself. See if you can find where the program sets a global variable candidate_count representing the number of candidates in the election, copies command-line arguments into the array candidates, and asks the user to type in the number of voters. Then, the program lets every voter type in a vote (see how?), calling the vote function on each candidate voted for. Finally, main makes a call to the print_winner function to print out the winner (or winners) of the election.

If you look further down in the file, though, you’ll notice that the vote and print_winner functions have been left blank. This part is up to you to complete!

import sys
import csv
import re
import numpy as np


def main():
    # Verifying the number of arguments the user inputs
    if len(sys.argv) != 3:
        print("Missing command-line argument")
        print("Try: python dna.py data.csv sequence.txt")
        sys.exit()

    # Lists to save the database and STRs count
    headerCSV = []
    individualDnaInfo = []
    strCount = []

    # Assinging a name to the database argument and opening the file
    database = sys.argv[1]
    with open(database, "r") as csvfile:
        reader = csv.reader(csvfile)
        line = 0
        for row in reader:
            if line == 0:
                headerCSV = row
                line += 1
            else:
                # Saving row info into the individualDnaInfo list
                individualDnaInfo.append(row)

    # Assinging a name to the sequence argument and opening the file
    sequence = sys.argv[2]
    with open(sequence, "r") as txtfile:
        textReader = txtfile.read()

    # Loop to count each DNA STR and to save it in a list (starting at 1 to avoid 'names')
    for i in range(1, len(headerCSV)):

        # Calling the count function
        strCount.append(count(headerCSV[i], textReader))

    # Working with an array
    strCount = np.array(strCount)

    # Loop to compare DNA STR count with sequences
    for i in range(len(individualDnaInfo)):

        # Skipping the person's name and going straight to the DNA info
        temp = np.array(individualDnaInfo[i][1:])

        # The all() function returns True if all items in an list are true, otherwise it returns False
        if (temp == strCount).all():

            # Getting the individual's name and storing into a variable
            name = individualDnaInfo[i][0]
            break
        else:
            name = "No match"
    print(f"{name}")

# Function to count each pattern in a sequence


def count(givenSequence, individualSequence):
    # Making a raw f-string literal
    p = rf'({givenSequence})\1*'
    pattern = re.compile(p)
    match = [match for match in pattern.finditer(individualSequence)]
    maxSequence = 0
    for i in range(len(match)):
        # Update max count if current repeat steak is greater than max
        repeat = 0
        repeat = match[i].group().count(givenSequence)
        if repeat > maxSequence:
            maxSequence = repeat
    return str(maxSequence)

main()
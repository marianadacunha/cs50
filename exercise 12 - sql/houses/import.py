from cs50 import SQL
import sys
import csv

# Storing the database in a variable to reuse later
db = SQL("sqlite:///students.db")

# Making a function to split the full name into First Name + Middle Name + Last Name
def split_name(nameInput):
    fullName = nameInput.split()
    # All names now will have 3 arguments [0][1][2]
    if len(fullName) == 3:
        return fullName
    else:
        return [fullName[0], None, fullName[1]]

def main():
    # Verifying the number of arguments the user inputs
    if len(sys.argv) != 2:
        print("Incorrect number of command-line arguments")
        print("Try: python import.py characters.csv")
        sys.exit()

    # Assinging a name to the database argument and opening the file
    charactersDatabase = sys.argv[1]
    with open(charactersDatabase, "r") as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            # Splitting the full name
            names = split_name(row["name"])
             # Inserting all infos in the database
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", names[0], names[1], names[2], row["house"], row["birth"])

main()
from cs50 import SQL
import sys

# Storing the database in a variable to reuse later
db = SQL("sqlite:///students.db")

# Verifying the number of arguments the user inputs
if len(sys.argv) != 2:
    print("Incorrect number of command-line arguments")
    print("Try: python roster.py Gryffindor")
    sys.exit()

# Storing the argument the user provided in a variable to reuse later
givenHouse = sys.argv[1]
# Selecting the house the user wants
rows = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", givenHouse)

for row in rows:
    firstName = row["first"]
    middleName = row["middle"]
    lastName = row["last"]
    birthYear = row["birth"]

    # Formatting the program's output
    if middleName != None:
        print(f"{firstName} {middleName} {lastName}, born {birthYear}")
    else:
        print(f"{firstName} {lastName}, born {birthYear}")
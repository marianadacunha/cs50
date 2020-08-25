from cs50 import get_int

def main():
    # Asks user for input until it receives a valid one
    while True:
        height = get_int("Height: ")
        if height < 9 and height > 0:
            break

    for row in range(height):
        for column in range(height):
            if row + column >= height - 1:
                print("#", end="")
            else:
                print(" ", end="")
        print()
main()
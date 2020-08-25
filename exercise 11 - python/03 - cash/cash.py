from cs50 import get_float


def main():
    while True:
        # Float is used to handle both dollars and cents
        dollars = get_float("How many dollars do you need in change? ")
        if dollars > 0:
            break

    # Turns the user input into cents instead of dollars (1 dollar is equal to 100 cents)
    cents = dollars * 100
    # Let's begin with 0 coins
    coins = 0

    while cents >= 25:
        # Cents = Cents - 25
        cents -= 25
        # Incrementing the total coins
        coins += 1

    while cents >= 10:
        cents -= 10
        coins += 1

    while cents >= 5:
        cents -= 5
        coins += 1

    while cents >= 1:
        cents -= 1
        coins += 1

    print(f"I'm going to give you {coins} coins")


main()
from cs50 import get_float
import numpy as np


# Receive input from the user
while True:
    usd = get_float("change owed: ")
# break the loop if the given input is valid
    if usd >= 0:
        break

# convert the given input(usd) to cents
cents = usd * 100
cents = round(cents, 2)

# creating a variable for counting
coins = 0

# creating an array for quarter, dime, nickel, penny
divider = np.array([25, 10, 5, 1])

# substracting the cents by the array and count the coins
for i in range(len(divider)):
    while cents >= divider[i]:
        cents -= divider[i]
        coins += 1
print("", coins)
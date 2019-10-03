"""
Russian Peasant Multiplication (RPM) Algorithm Implemented In Python
RPM is a method of mutiplication of any 2 numbers using only multiplication
and division by 2.
The basics are that you divide the second number by 2 (integer division) until
it equals 1, every time you divide the second number by 2, you also multiply
the first number by 2. After the second number hits 1, you then remove all right
side values that are even. Finally you add all of the left side values that are
left.

EXAMPLE:
10*5:
10      5     <== We add left side value (10) to total
10*2=20 5/2=2 <== We don't use this line since int(5/2) is an even number
20*2=40 2/2=1 <== We add left side value (40) to total

10 + 40 = 50
10 * 5  = 50
"""

import sys

def RPMult(x, y):
    # Create an empty list to store values of each mult/div by 2
    # Set total value to 0
    total = 0
    val_list =[]
    count = 0
    # If y is already equal to 1, return the value of x as total
    if y != 1:
        # Loop through calculations until y is equal to 1
        while y >= 1:
            # Add values of x and y to list
            val_list.append((x, y))
            # Division and multiplication by 2 on each side of equation
            y = int(y/2)
            x = x*2
    else:
        total = x
    # Loop through list to calculate result of multiplication
    for val in val_list:
        # If the mod of val[1] returns anything other than 0, we add val[0] to 
        # the total result of the multiplication
        if val[1]%2 >= 1:
            total += val[0]
    return total

def main():
    arguments = len(sys.argv) - 1
    if arguments != 2:
        print("Error please pass two integer values!")
        print("Usage: python RussianPeasantMult.py <int1> <int2>")
    else:
        try:
            x = int(sys.argv[1])
            y = int(sys.argv[2])
        except ValueError:
            print("Error: You can only pass integer values to program")
            return
        print(RPMult(x, y))

if __name__ == "__main__":
    main()
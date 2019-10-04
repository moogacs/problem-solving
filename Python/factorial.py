"""
Factorial of a number n is product of all positive non-zero numbers less than or equal to n. 
The factorial of n is denoted by n!. The (!) symbol is used to denote a factorial. 
Factorial of any number can be represented as product of the number and factorial of a number less than it by one. 
It can be written as, n! = n × (n−1)!
"""


import doctest


def factorial(n: int) -> int:
    """

    >>> factorial(5)
    120

    >>> factorial(6)
    720

    :param n:
    :return: factorial of n
    """
    if n <= 2:
        return n

    return n * factorial(n - 1)


if __name__ == '__main__':
    doctest.testmod()

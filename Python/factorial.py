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

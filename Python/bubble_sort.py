"""
Bubble sort, sometimes referred to as sinking sort, is a simple sorting algorithm that repeatedly 
steps through the list, compares adjacent elements and swaps them if they are in the wrong order. 
The pass through the list is repeated until the list is sorted.
"""

import doctest


def bubble_sort(seq):
    """

    >>> bubble_sort([3, 2, 1])
    [1, 2, 3]

    >>> bubble_sort([5, 4, 8, 8, 54, 64, 1, 5, 61, 6, 51, 8, 1, 1, 6, 5])
    [1, 1, 1, 4, 5, 5, 5, 6, 6, 8, 8, 8, 51, 54, 61, 64]

    :param seq:
    :return:
    """
    length = len(seq)
    for i in range(length):
        swapped = False

        for j in range(length - i - 1):
            if seq[j] > seq[j + 1]:
                seq[j + 1], seq[j] = seq[j], seq[j + 1]
                swapped = True

        if not swapped:  # already sorted
            break

    # for doctest, because of in place sorting
    print(seq)


if __name__ == '__main__':
    doctest.testmod()

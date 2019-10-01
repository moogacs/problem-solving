"""
This is an implementation of the binary search problem that allows
for searching at a O(log n) complexity, just to be warned the array
that is being searched does need to be ordered

Some information: https://en.wikipedia.org/wiki/Binary_search_algorithm
"""

import math


def binary_search(arr, left, right, x):
    # Check base case
    if right >= left:
        mid = math.floor(left + (right - left)/2)
        # If element is present at the middle itself
        if arr[mid] == x:
            return mid
        # If element is smaller than mid, then it
        # can only be present in left subarray
        elif arr[mid] > x:
            return binary_search(arr, left, mid-1, x)
        # Else the element can only be present
        # in right subarray
        else:
            return binary_search(arr, mid + 1, right, x)
    else:
        # Element is not present in the array
        return -1



def main():
    # Test array§
    arr = [ 2, 3, 4, 10, 40 ]
    x = 4

    # Function call
    result = binary_search(arr, 0, len(arr)-1, x)
    if result != -1:
        print(f'Element found at index {result}')
    else:
        print("Element is not present in array")

if __name__ == "__main__":
    main()

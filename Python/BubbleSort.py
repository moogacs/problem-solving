# Python implementation of Bubble Sort


def bubbleSort(arr):
    k = len(arr)
    # Traverse through all elements
    for i in range(k):
        # Last i elements are already in correct place
        for j in range(0, k - i - 1):
            # Swap if element is greater than next element
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


# example array
intergerArr = [20, 345, 215, 112, 2, 33, 29]

bubbleSort(intergerArr)

print("Sorted array: " + str(intergerArr))

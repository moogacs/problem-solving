# This question asks us to find the kth largest element of a list.
# A naive approach would be to just sort the list and get the kth largest element directly,
# but that would have a time complexity of O(log n) on average where n is the size of the list.
#
# If you know how the quicksort sorting algorithm works, you might see that we can modify it
# to generate our answer with a better approach.
#
# Quicksort: 
# The quicksort algorithm consists of positioning a pivot number of our list in such a way that
# every number on its left will be smaller than the pivot, and every number on its right will be 
# greater than pivot. Once we do that, we have the pivot in the correct position in the list, and
# we continuosly run our quicksort algorithm in these two partitions created around our pivot.
# 
# Solution:
# One of the main aspects of our quicksort algorithm is that once we move all elements smaller 
# than our pivot to its left, and all elements greater to its right, we now have the correct
# position of our pivot. What if our pivot is actually sitting where the kth largest would be?
# Then we would have found our answer and wouldn't need to sort the rest of our list.
# We can't expect to find our kth largest element on the first try, but if we know the position of
# our pivot, if the pivot is in a smaller position, we know our answer will be by its right 
# partition, and the same goes in the case our pivot is in a bigger position, where our answer 
# would lie on its left partition. That way, we would run our sorting algorithm optimally to find
# one particular element and would decrease our time complexity to O(n). 

def kthLargest(arr, k, left, right):
    # This is the first part of our quicksort algorithm, selecting a pivot and moving
    # every element smaller to its left and every element greater to its right.
    value = arr[right - 1]
    i = left - 1
    for j in range(left, right - 1):
        if arr[j] <= value:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    # For our last step in our partial quicksort, we move our pivot to the middle.
    arr[i + 1], arr[right - 1] = arr[right - 1], arr[i + 1]

    # The kth largest element has its k starting from the end of our list.
    # To have our index starting from 0, we just need to have len(arr) - k.
    m = len(arr) - k

    # If our pivot is in the position we are seeking, we have found our answer
    if i + 1 == m:
        return arr[i + 1]
    # If our pivot is in a bigger position than we expected, then our element
    # is in the left partition.
    elif m < i + 1:
        return kthLargest(arr, k, left, i + 1)
    # Otherwise, it will be on the right partition.
    else:
        return kthLargest(arr, k, i + 1, right)

def findKthLargest(nums, k):
    return kthLargest(nums, k, 0, len(nums))

print(findKthLargest([3, 5, 2, 4, 6, 8], 3))
# 5

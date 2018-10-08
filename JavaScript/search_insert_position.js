/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:
Input: [1,3,5,6], 5
Output: 2

Example 2:
Input: [1,3,5,6], 2
Output: 1

Example 3:
Input: [1,3,5,6], 7
Output: 4

Example 4:
Input: [1,3,5,6], 0
Output: 0

*/

// performs binary search to obtain position
const searchInsert = (arr, k) => {
    let n = arr.length;
    let low = 0, high = n - 1;

    while (low <= high) {

        // get middle element
        let mid = Math.floor((low + high) / 2);
        // console.log(arr[mid], " ", mid);

        // compare and restructure boundaries
        if(arr[mid] == k) return mid;
        else if(arr[mid] < k) low = mid + 1;
        else high = mid - 1;
    }

    // if it reached here then element has not been found
    return ~low;
}

/*

    explanation for ~low

    binary search does two things
    1. if the element is found, gives us actual location via mid
    2. if the element is not found, gives us expected location via low

    hence we return low instead of -1 when the item isn't found

    but to differentiate between cases of found and not found, we try to return (-1 * low)

    however if we do that then 0 becomes an edge case, hence we return -1 * (low - 1)

    which is (-low + 1)

    also called two's complement, the ~low

*/


const searchInsertHelper = (arr, k) => {
    let x = searchInsert(arr, k);
    if(x < 0) console.log("Element not found. Will appear at " + (-1 - x));
    else console.log("Element found at " + x);
}
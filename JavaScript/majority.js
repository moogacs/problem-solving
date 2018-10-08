/*

Given an array of length n, find an element that occurs more than n / 2 times

Input : {3, 3, 4, 2, 4, 4, 2, 4, 4}
Output : 4 

Input : {3, 3, 4, 2, 4, 4, 2, 4}
Output : -1

*/

const getMajority = arr => {

	// map holds key value pairs, the value for each key is the frequency of occurence
	let count = new Map();
	let n = arr.length;

	// iterating through the array
	for(let x of arr) {

		// if the element has not been seen before, set its occurences to 1
		if(!count.has(x)) count.set(x, 1);

		// otherwise increment
		else count.set(x, count.get(x) + 1);

		// if it becomes a majority element return it
		if(count.get(x) > n / 2) return x;
	}

	// if it reaches here then a majority element was not found and hence return -1
	return -1;
}

export { getMajority };
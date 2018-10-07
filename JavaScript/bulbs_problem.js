/*

N light bulbs are connected by a wire. Each bulb has a switch associated with it, however due to faulty wiring, a switch also changes the state of all the bulbs to the right of current bulb. Given an initial state of all bulbs, find the minimum number of switches you have to press to turn on all the bulbs. You can press the same switch multiple times.

Note : 0 represents the bulb is off and 1 represents the bulb is on.

Example:

Input : [0 1 0 1]
Return : 4

Explanation :
	press switch 0 : [1 0 1 0]
	press switch 1 : [1 1 0 1]
	press switch 2 : [1 1 1 0]
	press switch 3 : [1 1 1 1]

*/

const goodCount = arr => {

	// counts the number of switches toggled
	let switchCount = 0;

	// iterates from start to end of switch array
	let i = 0;

	while(i < arr.length) {

		// if the switch is off
		if(!arr[i]) {

			// turn it on and increment count
			switchCount++;
			arr[i] = 1;

			// toggle everything to the right
			for(let j = i + 1; j < arr.length; j++) {
				arr[j] = 1 - arr[j];
			}
		}

		i++;
	}

	return switchCount;
}

const betterCount = arr => {

	// counts the number of switches toggled
	let switchCount = 0;

	// iterates from start to end of switch array
	let i = 0;

	while (true) {
		let offBulb = arr.indexOf(0);

		// if all bulbs are on
		if(offBulb < 0) return switchCount;

		// otherwise toggle everything and increment count
		switchCount++;	
		for(let j = offBulb; j < arr.length; j++) {
			arr[j] = 1 - arr[j];
		}
	}
}

const bestCount = arr => {

	let switchCount = 0;

	let flipped = false;

	for(let i = 0; i < arr.length; i++) {

		// shorthand for xnor
		if(flipped == arr[i]) {
			switchCount++;
			flipped = !flipped;
		}

		else continue;
	}

	return switchCount;
}

export default { goodCount, betterCount, bestCount };
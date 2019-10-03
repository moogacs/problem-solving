//mod to wrap around to work with negative numbers as well
const mod = (n, amount) => ((n % amount) + amount) % amount;

const caesar = (text, decode = false) => {
	//shift only letters
	return text.replace(/[a-zA-Z]/g, m => {
		//check if it is uppercase
		if (/[A-Z]/.test(m)) {
			//turns the letter to ascii code and remove enough to turn to a count from 1-26
			//then add or remove 3 depending if you want to encode or decode
			//then modulo 26 in cases of last few letters of the alphabet to wrap back to first letters
			//and finally add the subtracted amount and turn it into letters again
			return String.fromCharCode(mod(((m.charCodeAt(0) - 64) + (decode ? (-3) : 3)), 26) + 64);
		} else {
			return String.fromCharCode(mod(((m.charCodeAt(0) - 96) + (decode ? (-3) : 3)), 26) + 96);
		}
	});
};

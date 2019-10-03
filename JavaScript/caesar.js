/*
* is a type of substitution cipher in which each letter in the plaintext is 'shifted' a certain number of places down the alphabet.
* For example, with a shift of 1, A would be replaced by B, B would become C, and so on.
* plaintext:  defend the east wall of the castle
* ciphertext: efgfoe uif fbtu xbmm pg uif dbtumf
* Formula: c[i] = (p[i] + key) % 26;
* c: ciphertext
* p: plaintext
* */


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

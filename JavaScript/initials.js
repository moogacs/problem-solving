/*
* Given a name in a string, display its initials.
* INPUT : "Welcome To Apple"
* OUTPUT : "WTA"
* */

const initials = text => {
	//split by space, then replace every word for the first character, and join it all up
	return text.split(" ").map(w => w[0]).join("");
};
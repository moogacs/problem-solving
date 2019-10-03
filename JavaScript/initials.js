const initials = text => {
	//split by space, then replace every word for the first character, and join it all up
	return text.split(" ").map(w => w[0]).join("");
};
**To contribuite to that repo. you have to follow this guidline**

**First**
try to find a problem in one of the following websites

* [Hackerrank](https://www.hackerrank.com/)
* [Firecode.io](https://www.firecode.io/)
* [Codechef](https://www.codechef.com/)
* [Leetcode](https://leetcode.com/)
* [Codeforces](http://codeforces.com/)
* [HackerEarth](https://www.hackerearth.com/)
* [TopCoder](https://www.topcoder.com/)


**Second**

On the source code of your solution try to follow that example:

**comment the problem description with input/output example in the first lines**
> Given 2 non negative integers m and n, find gcd(m, n)
GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.
Both m and n fit in a 32 bit signed integer.
Example
m : 6
n : 9
GCD(m, n) : 3 


----------------------
**add your solution**

> const gcd = (a, b) => {
	if(b) return gcd(b, a % b);
	else return a;
}
export { gcd };
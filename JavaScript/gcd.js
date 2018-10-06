//Given 2 non negative integers m and n, find gcd(m, n)
//
//GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.
//Both m and n fit in a 32 bit signed integer.
//
//Example
//
//m : 6
//n : 9
//
//GCD(m, n) : 3 


module.exports = { 
	//param A : integer
	//param B : integer
	//return an integer
	gcd : function(A, B){
	    if(A==B){
	        return A
	    }
	    if(A==0)return B
	    if(B==0)return A
	    
	    var greater = A
	    var smaller = B
	    if(B>A){
	        greater = B
	        smaller = A
	    }
        if(greater%smaller==0){
            return smaller
        }
        return this.gcd(greater%smaller, smaller)
	}
};

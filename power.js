//Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.
//
//Example
//
//Input : 4
//Output : True  
//as 2^2 = 4. 


// A^P => P > 1 , A > 0
function  findPower(x){
    var i=0;
    var P = 2
    var A = 1
    while(i>0){
        if(Math.pow(A, P) == x){
            return 
        }
        A++
        if(Math.pow(A, P) == x){
            return 
        }
        P++
        if(Math.pow(A, P) == x){
            return 
        }        
        i++
    }
}
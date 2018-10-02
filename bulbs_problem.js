//N light bulbs are connected by a wire. Each bulb has a switch associated with it, however due to faulty wiring, a switch also changes the state of all the bulbs to the right of current bulb. Given an initial state of all bulbs, find the minimum number of switches you have to press to turn on all the bulbs. You can press the same switch multiple times.
//
//Note : 0 represents the bulb is off and 1 represents the bulb is on.
//
//Example:
//
//Input : [0 1 0 1]
//Return : 4
//
//Explanation :
//	press switch 0 : [1 0 1 0]
//	press switch 1 : [1 1 0 1]
//	press switch 2 : [1 1 1 0]
//	press switch 3 : [1 1 1 1]

module.exports = { 
	//param A : array of integers
	//return an integer
	bulbs : function(A){
	    var switch_count = 0
	    var i=0
	      while(i<A.length){
	        if(A[i] == 0){
	            switch_count++
                A[i] = -1 * (A[i]-1)
                for(var j=i+1;j<A.length;j++){
                    A[j] =  -1 * (A[j]-1)
                }
	        }
	        
	        i++
	    }
        return switch_count
	}
};



//better

 while(A.indexOf(0)>-1){
	        switch_count++
	        for(var j=A.indexOf(0);j<A.length;j++){
                A[j] =  -1 * (A[j]-1)
            }
	    }
	   



best 
module.exports = { 
	//param A : array of integers
	//return an integer
	bulbs : function(A){
	    var switch_count = 0
	    var flipped = false; 
        for (var i = 0; i < A.length; i++) {
            if (!flipped && A[i] == 0 || flipped && A[i] == 1) {
                switch_count++;
                flipped = !flipped;
            } else {
                continue;
            }
        }
        return switch_count
	}
};

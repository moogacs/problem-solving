module.exports = { 
	//param A : array of integers
	//return an integer
	majorityElement : function(A){
	    var majority = Math.floor(A.length/2)
	    var arr_counts = []
	    var arr_num = []
	    var greatest = 0
	    if(A.length == 1){
	        return A[0]
	    }
	   
        for(var i =0;A.length;i++){
            if(arr_num.indexOf(A[i]) < 0){
                arr_num.push(A[i])
                arr_counts.push(arr_counts[i]++)
            }else {
                arr_counts[arr_num.indexOf(A[i])] +=1
                if(arr_counts[arr_num.indexOf(A[i])] > majority){
                    greatest = arr_num.indexOf(A[i])
                }
            }
            
        }
        return greatest
	}
};
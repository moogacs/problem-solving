//Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.
//
//You may assume that the array is non-empty and the majority element always exist in the array.
//
//Example :
//
//Input : [2, 1, 2]
//Return  : 2 which occurs 2 times which is greater than 3/2. 
//

public class Solution {
	public int majorityElement(final List<Integer> A) {
	    
	    if (A == null)
	        return -1;
	        
	    int maj = A.get(0);
	    int count = 1;
	    int n = A.size();
	    
	    for (int i = 1; i < n; i++) {
	        if (A.get(i) == maj) {
	            count++;
	        } else if (count == 1) {
	            maj = A.get(i);
	        } else {
	            count--;
	        }
	    }
	    
	    count = 0;
	    
	    for (int i = 0; i < n; i++) {
	        if (A.get(i) == maj)
	            count++;
	    }
	    
	    if (count > n / 2)
	        return maj;
	        
	    return -1;
	    
	    
	}
}
//Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
//
//If the last word does not exist, return 0.
//
//Note: A word is defined as a character sequence consists of non-space characters only.
//
//Example:
//
//Given s = "Hello World",
//
//return 5 as length("World") = 5.
//
//Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.

public class Solution {
	public int lengthOfLastWord(final String a) {
	    int count = 0;
	    boolean foundSpace = false;
	    if(a.length() == 1){
	       if(a.charAt(0) != ' '){
	           count++;
	       } 
	    }else {
    	     for(int i=a.length()-1; i >=0;i--){
    	        if(a.charAt(i) != ' '){
    	            count++;
    	        }else if(a.charAt(i) == ' '&& count == 0){
    	            foundSpace = true;
    	            continue;
    	        }else if(foundSpace || count >0){
    	            break;
    	        }
    	    }   
	    }
	    return count;
	}
}


public class Solution {
	public int lengthOfLastWord(final String A) {
	    int i;
	    
	    if (A.length() == 0)
	        return 0;
	        
	    int n = A.length();
	    int lastWordIndex = n;
	    int endIndex = n;
	    
	    i = n - 1;
	    
	    while (i >= 0 && A.charAt(i) == ' ')
	        i--;
	        
	    endIndex = i;
	    
	    for (; i >= 0; i--) {
	        
	        if (A.charAt(i) == ' ') {
	            break;
	        }
	        
	        lastWordIndex = i;	        
	        
	    }
	    
	    return Math.max(0, endIndex - lastWordIndex + 1);
	    
	}
}

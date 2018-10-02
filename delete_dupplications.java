//**
// * Definition for singly-linked list.
// * class ListNode {
// *     public int val;
// *     public ListNode next;
// *     ListNode(int x) { val = x; next = null; }
// * }
// */ it's java Solution
public class Solution {
	public ListNode deleteDuplicates(ListNode A) {
	    
	    if (A == null)
	        return A;
	    
	    ListNode next;
	    ListNode prevNode;
	    int prev = A.val;
	    
	    next = A.next;
	    prevNode = A;
	    
	    while (next != null) {
	        if (next.val == prev) {
	            prevNode.next = next.next;
	        } else {
	            prevNode = next;
	            prev = next.val;
	        }
	        
	        next = next.next;
	    }
	    
	    return A;
	}
}

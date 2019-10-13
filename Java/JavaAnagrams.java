import java.util.Scanner;

public class Solution {

    static boolean isAnagram(String a, String b) {
        // Complete the function
        if(a.length()!=b.length()){return false;}
        a= a.toLowerCase();
        b=b.toLowerCase();
        
        char[] aa = a.toCharArray();
        char[] bb = b.toCharArray();
        int c=0;
        for(int i=0;i<aa.length;i++){
            for(int j=0;j<bb.length;j++){
                if(aa[i]==bb[j]){
                    bb[j]=0;
                    c++;
                    break;
                }
            }
        }
        if(c==bb.length){return true;}
        return false;
    }

    public static void main(String[] args) {
    
        Scanner scan = new Scanner(System.in);
        String a = scan.next();
        String b = scan.next();
        scan.close();
        boolean ret = isAnagram(a, b);
        System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );
    }
}
// Problem Link : https://www.hackerrank.com/challenges/encryption/problem
/* 
An English text needs to be encrypted using the following encryption scheme.
First, the spaces are removed from the text. Let be the length of this text. 

For example, the sentence 
        "s = if man was meant to stay on the ground god would have given us roots"
after removing spaces is characters long. is between and,
so it is written in the form of a grid with 7 rows and 8 columns. 

	ifmanwas  
	meanttos          
	tayonthe  
	groundgo  
	dwouldha  
	vegivenu  
	sroots

Sample Input  0 : have a nice day
Sample Output 0 : hae and via ecy

Sample Input  1 : feed the dog
Sample Output 1 : fto ehg ee dd

*/

import java.lang.*;

public class SimpleEncryption {
    static String encryption(String s) {
		int length = s.length();
		double sqrt = Math.sqrt(length);
		double floor = Math.floor(sqrt);
		double ceil = Math.ceil(sqrt);
		
		while(!((floor * ceil) >= length)) {
			if(floor > ceil) {
				ceil++;
			} else {
				floor++;
			}
		}
		
		int row = (int) floor;
		int col = (int) ceil;
		
		char[] chr = s.toCharArray();
		char[][] arr = new char[row][col];
		int k = 0;
		for(int i=0;i<row;i++) {
			for(int j=0;j<col;j++) {
				if(!(k >= length)) {
					arr[i][j] = chr[k++];
				} else {
					continue;
				}
			}
		}
		
		int total = (row+1)*(col+1);
        char[] fnl = new char[total];
        k = 0;
        for(int j=0;j<col;j++) {
            for(int i=0;i<row;i++){
                if(! (arr[i][j] == '\0')) {
                    if (!(k == total)) {
                        fnl[k++] = arr[i][j];
                    }                    
                }
            }
            if(! (k==total)) {
                fnl[k++] = ' ';
            }            
        }
		
		for(int i=0;i<total;i++) {
            if(fnl[i] == '\0') {
                fnl[i] = ' ';
            }
        }
        String res = new String(fnl);
        res = res.trim();
        
        return res;
    }
    public static void main(String[] args) {
		System.out.println(encryption("feedthedog"));
		System.out.println(encryption("haveaniceday"));
    }
}


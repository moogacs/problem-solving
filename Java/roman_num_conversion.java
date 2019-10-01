/* Roman numeral conversion:
 * Given a Roman number (I, II, III, IV, ...) in input, convert and print it into arabic numeral system (1, 2, 3, ...)
 * Example:
 *  Input: MMXIX
 *  Output: 2019
*/

public class Main {

    private static int decodeSingle(char letter) {
        switch (letter) {
            case 'M':
                return 1000;
            case 'D':
                return 500;
            case 'C':
                return 100;
            case 'L':
                return 50;
            case 'X':
                return 10;
            case 'V':
                return 5;
            case 'I':
                return 1;
            default:
                return 0;
        }
    }

    public static int decode(String roman) {
        int result = 0;
        String uRoman = roman.toUpperCase(); //case-insensitive
        for (int i = 0; i < uRoman.length() - 1; i++) {//loop over all but the last character
            if (decodeSingle(uRoman.charAt(i)) < decodeSingle(uRoman.charAt(i + 1))) {
                result -= decodeSingle(uRoman.charAt(i));
            } else {
                result += decodeSingle(uRoman.charAt(i));
            }
        }
        result += decodeSingle(uRoman.charAt(uRoman.length() - 1));
        return result;
    }

    public static void main(String[] args) {
        String value1 = args[0];
        System.out.println(decode(value1)); 
        
    }
}
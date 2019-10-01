/* Roman numeral conversion:
 * Given a Roman number (I, II, III, IV, ...) in input, convert and print it into arabic numeral system (1, 2, 3, ...)
 * Example:
 *  Input: MMXIX
 *  Output: 2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char value1[128]; 

    strcpy(value1, argv[1]);    // in this sample code the input is given by terminal (argv[1])

    int convd[strlen(value1)];  // used to convert the roman number to arabic, keeping the order

    // conversion to int
    for(int i = 0; i < strlen(value1); i++){
        switch (value1[i]) {
            case 'I':
                convd[i] = 1;
                break;
            case 'V':
                convd[i] = 5;
                break;
            case 'X':
                convd[i] = 10;
                break;
            case 'L':
                convd[i] = 50;
                break;
            case 'C':
                convd[i] = 100;
                break;
            case 'D':
                convd[i] = 500;
                break;
            case 'M':
                convd[i] = 1000;
                break;
            default:
                break;
        }
    }

    // calculating the sum of the array "convd"

    int sum = 0;

    for(int i = 0; i < strlen(value1); i++){
        if (i == strlen(value1) - 1){
            sum += convd[i];
            break;
        }
        if(convd[i] >= convd[i + 1]){
            sum += convd[i];
        } else {
            sum -= convd[i];
        }
    }

    // now print the result
    printf("%d", sum);
}

/* Bonus exercise: from arabic numeral to Roman numeral */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "major1.h"

#define INT2BIN(p1) intToBin(p1, malloc(33))

int main() {
    int choice, num;

    while (1) {
        // Displaying the menu
        printf("\nMenu:\n");
        printf("0.  Create a Palindrome\n");
        printf("1.  Power\n");
        printf("2.  Reverse\n");
        printf("3.  Replace\n");
        printf("4.  Palindrome\n");
        printf("5.  Exit\n");
        
        // Reading user's choice
        choice = getNumber("Enter your choice: ", 5);
        num    = getNumber("Enter a number: ", 2000000000);

        // Handling user's choice
        switch (choice) {
            case 0:     createPalindrome(num);  break;
            case 1:     power(num);             break;
            case 2:     reverse(num);           break;
            case 3:     replace(num);           break;
            case 4:     palindrome(num);        break;
            case 5:                             return 0;
            default:    printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

int getNumber(char *prompt, int max) {
    int     num;
    char    input[30];

    while (1) {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);
        num = atoi(input);
        if (num >= 0 && num <= max) {
            return num;
        }
    }
}

char *intToBin(int v, char *str) {
    int i;
    for (i = 31; i >= 0; i--)
        str[31-i] = ('0' + ((v >> i) & 1));
    str[32] = 0;
    return str;
}

void createPalindrome(int num) {
    char    str[33];
    int     pal = reverse(num) | num;
    printf("%6d %10u\n       %s\n", num, pal, INT2BIN(pal));
}

void power(int num) {
    int moreThan1 = 0;          //  is there more than one bit?
    int firstBit  = 0;          //  find the highest order bit
    for (int b = 31; b >= 1; b-- ) {
        if (num & (1 << b)) {
            if (! firstBit) firstBit = b;
            if( ++moreThan1 > 1)    
                break;          //  if there are more than 1 bits set it is not a power of 2
        }
    }
    printf("%d is %sa power of 2. next higher power of 2^%d is %.0f\n", 
            num, moreThan1>1?"not ":"", firstBit, pow(2,(firstBit+1)));
}

int reverse(int num) {
    char    str1[32], str2[32];
    int newNum = 0;

    for (int b = 0; b < 32; b++) {
        newNum <<= 1;
        newNum |= ((num & (1 << b)) != 0);
    }
    printf("newNum %s\noldNum %s\n", INT2BIN(newNum), INT2BIN(num));
    return newNum;
}

void replace(int num) {
    int mask, bit, maskBit, newNum;
    bit  = getNumber("Enter a bit:  ", 31);
    mask = getNumber("Enter a mask: ", 2000000000);
    bit = 1 << bit;             //  shift the 1 bit to the desired location in the mask
    maskBit = bit & mask;       //  this will hold the bit to be changed in the position desired
    if (maskBit == 0) 
        newNum = num & ~bit;    //  reverse all the bits in the bit so only the masked bit is 0
    else
        newNum = num | bit;     //  just OR in the bit in the desired position
    printf("%s %8d\n%s %08d\n%s %8d\n", INT2BIN(num), num, INT2BIN(bit), num, INT2BIN(newNum), num);
}

void palindrome(int num) {
    printf("%d\n%s\nis %sa palindrome\n", num, INT2BIN(num), num == reverse(num) ? "": "not ");
    //  1073741826      2147581953  2181136448
    int bPalindrome = 1;
    printf ("%08x %u\n", num, num);
    for (int b = 0; b < 16; b++ ) {
        printf ("%d", (num & (1 << b)) > 0 );
        if ((num & (1 << b)) != 0 ^ (num & (1 << (31 - b))) != 0) {
            bPalindrome = 0;
            break;
        }
    }
    printf("\n%08x %s is %sa palindrome", num, INT2BIN(num), bPalindrome ? "": "not ");
}

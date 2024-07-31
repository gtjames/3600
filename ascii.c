#include <stdio.h>

void details(char ch) {
    char bin[9];
    for (int b = 7; b >= 0; b--) {
        bin[7-b] =     ((ch & (1 << b)) > 0) ? '1' : '0';
    }
    // Print the character, its hex value, and its octal value
    printf("Ch: %c  Dec: %03d  Hex: %02x  Bin: %s\n", ch, ch, ch , bin);
}
int main() {
    char str[100], ch;
    int i;

    // Prompt the user for input
    printf("Enter a char: ");
    scanf("%c", &ch);  // Limit input to 99 characters to avoid buffer overflow
    scanf("%c", &str[0]);  // Limit input to 99 characters to avoid buffer overflow
    details(ch);

    printf("\nEnter a string: ");
    fgets(str, sizeof(str), stdin);
    // Loop through each character in the string
    for (i = 0; str[i] > ' '; i++) {
        details(str[i]);
    }

    int     int1, int2;
    printf("\nEnter a #: ");
    scanf("%d", &int1);
    printf("Enter a #: ");
    scanf("%d", &int2);
    int1 ^= int2;
    int2 ^= int1;
    int1 ^= int2;
    printf("%d %d", int1, int2);
    return 0;
}
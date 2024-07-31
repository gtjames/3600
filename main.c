#include <stdio.h>
#include <math.h>

// Function declarations
int countBits(int num);

int main() {
    int choice;

    while (1) {
        // Displaying the menu
        printf("\nMenu:\n");
        printf("1. Option 1: Power\n");
        printf("2. Option 2: Reverse\n");
        printf("3. Option 3\n");
        printf("4. Option 4\n");
        printf("5. Option 5: Palindrome\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        // Reading user's choice
        scanf("%d", &choice);

        // Handling user's choice
        switch (choice) {
            case 1: power();            break;
            case 2: reverse();          break;
            case 3: option3();          break;
            case 4: option4();          break;
            case 5: palindrome();       break;
            case 6: printf("Exiting the program.\n");   return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Function definitions
void power() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int bitCount = countBits(num);
}

int countBits(int num) {
    int numberOfBits = 0;
    int firstBit = 0;
    for (int b = 31; b >= 1; b-- ) {
        if (num & (1 << b)) {
            numberOfBits++;
            if (! firstBit) firstBit = b;
        }
    }
    printf("%d %d is %sa power of 2. next hight power of 2 is %.0f", 
            num, firstBit, numberOfBits>1?"not ":"", pow(2,(firstBit+1)));
    return numberOfBits;
}

void reverse() {
    printf("You selected Option 2.\n");
    // Add functionality for Option 2 here
}

void option3() {
    printf("You selected Option 3.\n");
    // Add functionality for Option 3 here
}

void option4() {
    printf("You selected Option 4.\n");
    // Add functionality for Option 4 here
}

void palindrome() {
    printf("You selected Option 5.\n");
    // Add functionality for Option 5 here
}

/*
(“Power of 2”, “Reverse Bits”, “Replace Bit Position from Mask”, and “Palindrome”)
along with a positive integer less than 2 billion, and then perform that operation on that
integer (based on possible additional input) to produce the result. More details about the
operations are found below. The twist in this assignment is that each operation must be
performed using bitwise operators rather than the traditional operations. That said,
relational operators and the like can be used in branching and loops, but data
manipulation must be done using bitwise operators.
This project will be organized in a header file called major1.h, a source code file called
major1.c, which will contain the main() function, and four individual source code files
called power.c, reverse.c, replace.c, and palindrome.c that will contain the
function definition for their respective arithmetic operations. The entire group will be
responsible in general for non-operation specific functionality in the major1.h and
major1.c source code files while each individual group member is responsible for
his/her own “functional operation” in the appropriate files (including the function
declaration in the header file and the function call inside the main() function).
In particular, you are expected to have the following functionality for each file:
• major1.h
This file is the overall header file for the project and will contain any preprocessor
directives, such as include and define directives, and function prototypes.
While the include directives are general for the team, each member is
expected to add their own function prototype (i.e., function declaration) for the
operation that he/she is responsible for.
• major1.c
This is the code file with the main() function that will do the following: (1) display
the menu, (2) read in the user’s response for the menu selection, (3) prompt for
and read in a positive integer less than two billion, and then, based on the menu
selection, (4) call the appropriate function call for the specified operation, passing
the integer operand as a parameter to that function. This functionality will be
contained in a loop that will continue to iterate until the user selects the option to
end the program. If the user enters a valid outside of the 1 – 5 range, you will
print a meaningful error message and re-display the menu. Additionally, you will
continue to prompt for and read in the integer operand until the user enters an
acceptable value (no error message is needed here). While the code to display
the menu as well as prompt for and read in the integer operand are considered to
be part of the group component, each group member is expected to add the
function call for the operation he/she is responsible for.
• reverse.c
This code will contain a single function that accepts a single positive integer less
than two billion (and the include directive to your header file) to perform the
following functionality: reverse the bits (all 32 of them) and then print out the
decimal value of the new integer (i.e., the one with the bits reversed). For
example, if the user enters the positive integer 2 (which is 00...0010), this
function would reverse the digits to 0100...00, which is 1073741824. The
operations to reverse the bits must be done using bitwise operators. One team
member, and only one team member, will be responsible for the source code in
this file in GitLab, though collaboration with other group members may be done if
needed.
• replace.c
This code will contain a single function that accepts a single positive integer less
than two billion (and the include directive to your header file) to perform the
following functionality: (1) prompt for and read in a positive integer “mask” less
than three billion and continue to prompt for and read in the positive integer mask
until the user enters and acceptable value (no error message is needed here), (2)
prompt for and read in the bit replacement position from the mask and continue
to prompt for and read in the bit replacement position from the mask until the
user enters an acceptable value (no error message is needed here, but note that
since we are working with 32-bit unsigned integers, the value should be between
0 and 31, inclusively), and finally (3) replace the single bit in the original positive
integer less than two billion passed to the function with the single bit from the
positive integer mask specified by the user (i.e., in the bit replacement position
from the mask). For example, if the user initially enters 7 (in binary, 00...00111)
as the positive integer less than two billion, then enters 8 (in binary, 00...01000)
for the positive integer mask and 3 for the bit replacement position, you will
replace the third bit from the positive integer 7 (a 0) with the third bit from the
positive integer mask (a 1), resulting in the new value 15 (in binary, 00...01111).
The operations to replace the bit must be done using bitwise operators.
Additionally, no loops may be used (except in error checking when prompting for
and reading in the positive integer mask and bit replacement position from the
mask) to achieve this functionality. One team member, and only one team
member, will be responsible for the source code in this file in GitLab, though
collaboration with other group members may be done if needed.
• palindrome.c
This code will contain a single function that accepts a single positive integer less
than two billion (and the include directive to your header file) to perform the
following functionality: print out the binary representation of the positive integer
and then determine if the positive integer is a palindrome (based on all 32-bits).
For example, if the user enters 1073741826 (in binary, 0100...0010), it is a
palindrome. Check that 1073741826 is not a palindrome. The operations to
determine whether or not the positive integer less than two billion is a palindrome
must be done using bitwise operators. As a hint, you may use an array, but
remember that the significant logic to determine whether or not the positive
integer is a palindrome must be done using bitwise operators. One team
member, and only one team member, will be responsible for the source code in
this file in GitLab, though collaboration with other group members may be done if
needed.
Note that the expectation for this assignment assumes that a group contains 4 students,
but if, for some reason, a team has only 3 students, then only 3 of the operations would
need to be supported. This means that each group member is responsible for one and
only one operation (plus the group component of the assignment). If you have any
questions on what is acceptable, please discuss this with your instructor.
SAMPLE OUTPUT (user input shown in bold):
*/
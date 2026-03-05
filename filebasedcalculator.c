/*
*   this program reads an input file that contains an equation on each line
*   each line needs to be interpreted as its own equation
*   each line will contain at least one operator and at least two numbers 
*   it will need to be able to accommodate more operators and numbers, but is not required to follow the order of operations
*   it needs to be able to handle cases where multiple spaces were used, or where new lines contain no new information
*   the numbers and operators will need to have a way to be interpreted separately - since operators are between numbers, they will need to be skipped somehow
*   it needs to display the equation followed by the solution in a new output file

*   process (simple):
    1. open the input file in read mode and the output file in write mode
    2. read each line from the input file
    3. using spaces as delimiters, numbers and operators are translated into tokens
    4. operations are performed left-to-right 
    5. write the expression and its solution to the output file and print them to the command line
    6. end the processes and close all files
    7. display notification of completion, and open the output file to display the results

    process (less simple)
    1. recognize all values as characters to later translate
    2. understand whether a number has a positive or negative value 
    3. create an index to temporarily hold the current value so that it can be read, similar to a cursor
    4. convert number characters into integer values
    5. create a way for the operator to be skipped, allowing the numbers to be handled first
    6. have the input file ready to be read, and the output file ready to be written to
    7. examine the input file by reading it line-by-line
    8. store the line to display in the output file, while also storing the solution to the calculation
    9. find a way for the program to determine if a new line exists, or to remove empty lines
    10. identify and store the first number in the line
    11. identify and store the second (or third, fourth, etc.) number in the line
    12. identify the operator to apply the operation
    13. with the operation applied, the solution can be found
    14. the line will be displayed alongside the solution in the output file
    15. the read-only input file and the write-only output file are both closed
    16. notification of successful completion is sent
    17. output file is opened in notepad to display the input expressions with their respective solutions
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int convstore(const char* str) { // convert and store. this will change the number in the .txt file to a readable character for the program
    int num = 0; // temporary holding value for an integer
    int up_down = 1; // determines positive or negative values
    int i = 0; // index that acts as a keyboard cursor when parsing to identify the current number 
    if (str[0] == '-') { // if the string has a negative value,
        up_down = -1; // set the value to contain the '-' sign, indicating that the value is negative
        i++; // increase value of index by incrementing to move to the next character in the string
    }
    while (str[i] >= '0' && str[i] <= '9') { // converts characters recognized as digits into integer values
        num = num * 10 + (str[i] - '0'); // uses the value currently held by the index 
        // converts each character to its numeric value to create the full number
        // to skip the operator when reading the string, the string interprets '1+2' as '12' 
        i++; // increase value of index by incrementing to move to the next character in the string
    }
    return num * up_down; // returns the final integer with its matching positive or negative value
}

int main() {
    char mathIn[] = "math.txt"; // input file name
    char mathOut[] = "math_output.txt"; // output file name
    char line_storage[100]; // buffer to store a line from the input file
    FILE* in; // input file pointer
    FILE* out; // output file pointer

    fopen_s(&in, mathIn, "r"); // opens the input file in read mode, noted by "r"
    if (in == NULL) { // if the input file cannot be found
        printf("Error. Cannot open the input file.\n"); // error message prints
        return 1; // ends the program with an error indication
    }

    fopen_s(&out, mathOut, "w"); // opens the output file in write mode, noted by "w"
    if (out == NULL) { // if the output file cannot be found 
        printf("Error opening output file.\n"); // error message prints
        fclose(in); // closes input file to free up resources
        return 1; // ends the program with an error indication
    }

    while (fgets(line_storage, sizeof(line_storage), in) != NULL) { // uses the buffer to read a line from the file
        // if null, that means there is nothing left to read from the file, or some sort of error
        int result = 0; // stores the solution of the current calculation
        size_t len = strlen(line_storage); // creates a variable to store the length of the string found within the line

        if (len > 0 && line_storage[len - 1] == '\n') { // if there is a new line, find the last character in the string
        // uses \n to determine if a new line has started and > 0 to check that the line isn't empty
            line_storage[len - 1] = '\0'; // if there is a final new line, but it contains nothing, it will be removed to clean up the processing
        }

        char inputLine[100]; // buffer to store the original line for output
        strcpy_s(inputLine, sizeof(inputLine), line_storage); // copies the line for later use

        char* tok = strtok(line_storage, " "); // using spaces as delimiters, the string is broken down into tokens
        // the token has a pointer that indicates for it to store the first strtok value, which is assumed to be a number value
        if (tok != NULL) { // if the token does not exist, or if there are no further valid tokens
            result = convstore(tok); // converts the first token, a number value, from the string into an integer value
        }

        while (tok != NULL) { // so long as there are valid tokens
        // since the first number has been processed and stored already, this will continue the process with operator signs and other numbers
            char* opTok = strtok(NULL, " "); // new token to store and interpret operator signs
            if (opTok == NULL) break; // if there are no more tokens, the operator cannot be used, so the loop will end

            char* newTok = strtok(NULL, " "); // new token to store and interpret any other number values
            if (newTok == NULL) break; // if there are no more tokens, there is no next number to find, so the loop will end

            int number = convstore(newTok); // converts the string into an integer to store in the number variable
            char operator = *opTok; // retrieves and stores the operator sign by dereferencing the token pointer
            // with the operator sign stored as a token, it will need to be defined by its operation
                if (operator == '+') {      // if the operator sign is for addition
                    result += number;      // add the number
                }
                else if (operator == '-') { // if the operator sign is for subtraction
                    result -= number;      // subtract the number
                }
                else if (operator == '*') { // if the operator sign is for multiplication
                    result *= number;      // multiply the number
                }
                else if (operator == '/') { // if the operator sign is for division
                    result /= number;      // divide the number
                }
                // the operator is applied sequentially from left to right to match the values identified by the result
                // the first number is combined with the second number using the operator, completing what was done with the first token
                // the process continues with subsequent numbers and operators in the order they appear
        }

        fprintf(out, "%s = %d\n", inputLine, result); // writes the original line from the input, followed by the result
                                                     // this is done to make the output file easy to verify with what was inputted
        printf("%s = %d\n", inputLine, result);     // prints the result to the command line
    }

    fclose(in); // closes the input file
    fclose(out); // closes the output file
    printf("Finished! Solutions sent to output file: %s\n", mathOut); // notification of completion
    system("notepad math_output.txt"); // opens the output file in notepad
    return 0; // ends the program successfully
}
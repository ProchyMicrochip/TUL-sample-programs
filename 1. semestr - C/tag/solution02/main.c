/*
 * WORD LENGTH FINDER
 * Štěpán Rydval 2021
 * FM TUL
 */

// Includes
#include <stdio.h>
#include <string.h>

// Main function
int main() {

    char input[1024] = "Kdyz ma slovo v textu pet pismen tak bude ohraniceno tagem";   // Input text string
    char output[1024] = "";                                                            // Output text string
    const int wordLength = 5;                                                          // How long words should be tagged
    printf("Vstup: %s\n", input);                                                      // Prints out user input

    char *token;
    token = strtok(input, " ");                                                        // Holds first substring of input
    strcat(output, token);                                                             // Puts first word into output string
    while( token != NULL ) {                                                           // Splits input string into tokens
        token = strtok(NULL, " ");
        if(token == NULL){
            break;
        }
        if (strlen(token) == wordLength){                                              // If length of the word matches add tag
            strcat(output," <b>");
            strcat(output, token);
            strcat(output, "</b>");
        }
        else{
            strcat(output, " ");                                                       // If length doesn't match add space
            strcat(output, token);
        }
    }
    printf("Vystup: %s\n", output);                                                    // Prints out output
}

/*
 * STRING IN STRING FINDER
 * We were banned to use string.h!
 * Štěpán Rydval 2021
 * FM TUL
 */

//Includes
#include <stdio.h>

//Main function
int main(){

    char input[] = "Na strane 123 v 5-tem odstavci najdete 123 oddelenych slov"; //Input string
    char srch[64] = { 0 }; //String that stores user input
    int occurrence = 0; //Stores which occurrence of chars to find
    int occurrenceCount = 0; //Number of occurrences of given char
    int position = 0; //Stores position of found character
    int srchLen = 0; //Length of searched string
    int matchingChar = 0; //Number of found matching chars

    printf("Vstupní data:\n");
    printf("%s\n",input); //Prints out input string

    printf("Zadejte string, který chcete hledat:\n"); //Asks user to input chars whose position should be found
    scanf("%s", &srch); //Scans console for input chars

    //Calculates length of the srch string
    for (int i = 0; i < 64; ++i) {
        if (srch[i] != 0){
            srchLen++;
        }
    }

    printf("Délka zadaného stringu je %d.\n", srchLen); //Prints out lenght of the string

    printf("Zadejte, kolikátý výskyt chcete najít:\n"); //Asks user to input chars whose position should be found
    scanf("%d", &occurrence); //Scans console for input chars

    //Goes through string and compares them
    for (int i = 0; i < 256;++i) {
        matchingChar = 0;
        for (int j = 0; j < srchLen; ++j) {
            if (input[i+j] == srch[j]){
                matchingChar++;
            }
        }
        if (matchingChar == srchLen){
            occurrenceCount++;
        }
        if (occurrenceCount == occurrence){
            position = i;
            break;
        }
    }
    if (occurrenceCount == 0){
        printf("Char ve stringu není! (-1)");
        return 0;
    }
    printf("Vámi hledaný výskyt znaku je ve stringu na pozici:\n");
    printf("%d", position); //Prints out position of the char

    return 0;
}

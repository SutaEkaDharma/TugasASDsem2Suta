#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 2024
#define MIN_LENGTH 1945

void lessThanRequired (int *length){
    printf("The length of your text is less than specified, please update your text\n");
    printf("Length Before : %d", *length);
    *length = MAX_LENGTH;
}

void equalThanRequired (int *length){
    printf("Thank you, Your text length is correct\n");
}

void moreThanRequired (int *length){
    printf("Your text is too long, please reduce the text\n");
    printf("Length Before : %d", *length);
    *length = MAX_LENGTH;
}

int checkLengthRequirement(char* text){
    int length = strlen(text);
    if (length < MIN_LENGTH)
        return 0;
    else if (length == MIN_LENGTH)
        return 1;
    else
        return 2;
}

int main() {
    int lengthOfText, selectOption;
    FILE *fptr = NULL;
    char text[MAX_LENGTH];
    fptr = fopen("C:\\Users\\Asus\\Documents\\tugas praktikum ASD\\file.txt", "r");

    if(fptr == NULL){
        printf("Error");
        exit(1);
}

    fgets(text, MAX_LENGTH, fptr);

    fclose(fptr);
    lengthOfText = strlen(text); 
    selectOption = checkLengthRequirement(text);
    
    void (*function[3])(int*) = {lessThanRequired, equalThanRequired, moreThanRequired};
    function[selectOption](&lengthOfText);

    printf("\nThe Length is updated to %d", lengthOfText);
    
    return 0;
}


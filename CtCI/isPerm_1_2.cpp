/*
C1Q2 Check two strings are permutations of each other
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void countLetters(int *inputarr, const char *str){
        for(int i = 0; str[i] != '\0'; i++){
                inputarr[str[i] - 'a']++;
        }
}

bool isPerm(const char *str1, const char *str2){
        int str1letters[26] = {0};
        int str2letters[26] = {0};
        countLetters(str1letters, str1);
        countLetters(str2letters, str2);

        for(int i = 0; i < 26; i++){
                if(str1letters[i] != str2letters[i])
                        return false;
        }
        return true;
}


int main(int argc, char **argv){
        if(isPerm("abbcc", "abcbc")) 
                printf("is permutation\n");

        if(!isPerm("abbcc", "abcdc")) 
                printf("is not permutation\n");

}
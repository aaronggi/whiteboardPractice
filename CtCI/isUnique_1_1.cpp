/*
C1Q1 Check if a string has all unique characters
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//Assumption
bool isUnique(const char *str){
	int letterCounts[26] = {0};
	for(int i=0; str[i] != '\0'; i++){
		if( i > 25 || ++letterCounts[str[i] - 'a'] > 1)
			return false;
	}
	return true;
}

int main(int argc, const char **argv){
		if(isUnique("abcde"))
			printf("passed\n");
		if(!isUnique("abcded"))
			printf("passed\n");
}
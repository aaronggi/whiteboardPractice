/* Q 1.9 Checking whether one string is a rotation of another
*
* Written in C
*
* Runtime: O(N)
* Conditions: can only call the isSubString function once
*
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

inline bool isSubstring(const char *str1, const char *str2){
	if(strcmp(str1, "waterbottle") == 0){
		if(strcmp(str2, "erbottle") == 0)
			return true;
	}
	return false;
}//stub function, at least for now

inline bool onlyOneCharNull(char c1, char c2){
	return ( !c1 || !c2 ) && (c1 || c2); 
}

bool checkRotation(char str1[], char str2[]){
	int sslen = 0;
	int beginindex = -1;
	char temp = '\0';
	bool retval = false;


	for(int i = 0; str1[i] || str2[i]; i++){
		//If one string is NULL-terminated @i, but the other is
		//still ongoing, we know the strings are different
		//length :. return false
		if(onlyOneCharNull(str1[i], str2[i]))
			return false;

		if(str1[0] != str2[i])
			sslen++;
		else {
			beginindex = i;
			temp = str2[i];
			break;
		}
	}

	if(beginindex < 0)
		return false;

	for(int i = sslen, j = 0; str1[i] || str2[i]; i++, j++){
		if(onlyOneCharNull(str1[i], str2[i]) || (str1[j] != str2[i])){

			return false;
		}
	}

	//set the original beginning to a NULL-terminator,
	//so that a string comparison only considers the 
	//chars preceding
	str2[beginindex] = '\0';

	retval = isSubstring(str1, str2);

	//reset the char to it's original value
	str2[beginindex] = temp;

	return retval;
}


void verify(char *str1, char *str2){
	printf("\n %s %s ", str1, str2);

	if(checkRotation(str1, str2))
		printf("the string is rotated");
	else
		printf("the strings are different");
}

int main(int argc, char **argv){
	char str1[] = "waterbottle";
	char str2[] = "erbottlewat";
	char str3[] = "erbottlewot";
	char str4[] = "erbootlewat";
	char str5[] = "erbottlewatt";
	char str6[] = "erbottleewat";

	verify(str1, str2);
	verify(str1, str3);
	verify(str1, str4);
	verify(str1, str5);
	verify(str1, str6);


	return 0;
}
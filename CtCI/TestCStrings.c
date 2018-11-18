#include "CClasses.h"

int main(int argc, char **argv){
	Cstring *mystring = (Cstring*)New(String, 
		"can I get a uhhhhhhhhh cheese borger");
	printf("%s", mystring->text);
}
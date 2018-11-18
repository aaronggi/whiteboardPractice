#include "BST.h"

int main(int argc, char **argv){
	BST<int> bst;	
	try{
		printf("Begin BST Test\n");
		bst.insert(3);
		bst.insert(4);
		bst.insert(1);
		bst.insert(2);
		bst.printInorder();
		printf("\n");
		bst.remove(1);
		bst.printInorder(); 
	}catch(...){
		printf("exceptions occured, don't really care yet");
	}
}
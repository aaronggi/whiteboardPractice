#include "template.h"

template<class T>
struct node{
	T value;
	node<T> *left;
	node<T> *right;
};

template<class T>
class BST{
public:
	BST(): root(NULL){}
	~BST();

	node<T> *insert(T value);
	node<T> *remove(T value);

	void balance();
	void printInorder();

	static node<T> *createNode(T value);
	static node<T> *findMinNode(node<T> *subroot);

	static node<T> *flatten(node<T> *subroot, node<T> *& head);	
	static node<T> *rotateRight(node<T> *subroot);	

	static node<T> *insertHelper(node<T> *subroot, T &value);
	static node<T> *removeHelper(node<T> *subroot, T &value);
	
	static void printTreeInorder(node<T> *subroot);

	static void delTree(node<T> *subroot);

private:
	node<T> *root;
};

/*
* Beginning of Implementation 
*
*/
template<class T>
BST<T>::~BST(){
	try{
		delTree(root);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
}


template<class T>
node<T> *BST<T>::insert(T value){
	if(root == NULL){
		root = createNode(value);
		return root;
	}
	else {
		return insertHelper(root, value);
	}
}


template<class T>
node<T> *BST<T>::remove(T value){
	return removeHelper(root, value);
}


template<class T>
void BST<T>::printInorder(){
	printTreeInorder(root);
}


template<class T>
node<T> * BST<T>::createNode(T value){
	node<T> *rv = new node<T>;
	rv->value = value;
	rv->left = NULL;
	rv->right = NULL;
	return rv;
}


template<class T>
node<T> *BST<T>::flatten(node<T> *subroot, node<T> *& head){
	node<T> newroot = subroot;
	if(subroot == NULL){
		return NULL;
	}
	while(subroot->left){ 
		newroot = rotateRight(subroot);
	}
	newroot->right = flatten(newroot->right, newroot);
	return newroot;
}


template<class T>
node<T> *BST<T>::rotateRight(node<T> *subroot){
	node<T> *pivot = NULL;
	if(subroot->left == NULL)
		return subroot;
	else {
		pivot = subroot->left;
		subroot->left = pivot->right;
		pivot->right = subroot;
		return pivot;
	}
}


template<class T>
node<T> *BST<T>::insertHelper(node<T> *subroot, T &value){
	if(subroot == NULL){
		return createNode(value);
	}

	if(value == subroot->value){
		return subroot;
	}
	else if(value < subroot->value){
		subroot->left = insertHelper(subroot->left, value);
	}
	else if(value > subroot->value){
		subroot->right = insertHelper(subroot->right, value);
	}
	return subroot;
}


template<class T>
node<T> *BST<T>::removeHelper(node<T> *subroot, T &value){
	node<T> *temp = NULL;
	T tempval = subroot->value;

	if(subroot == NULL){
		return subroot;
	}
	if(value < subroot->value){
		subroot->left = removeHelper(subroot->left, value);
	}
	else if (value > subroot->value){
		subroot->right = removeHelper(subroot->right, value);
	}
	else{
		if(subroot->left == NULL){
			temp = subroot->right;
			delete subroot;
			return temp;

		}
		else if(subroot->right = NULL){
			temp = subroot->left;
			delete subroot;
			return temp;
		}
		else {
			temp = findMinNode(subroot->right);
			subroot->value = temp->value;
			temp->value = tempval;
			subroot->right = removeHelper(subroot->right, temp->value);
		}
	}
	return subroot;
}


template<class T>
node<T> * BST<T>::findMinNode(node<T> *subroot){
	if(subroot == NULL)
		return NULL;

	while(subroot->left != NULL){
		subroot = subroot->left;
	}
	return subroot;
}


template<class T>
void BST<T>::printTreeInorder(node<T> * subroot){
	if(subroot == NULL) return;
	//printf("root : %d ", subroot->value);
	printTreeInorder(subroot->left);	

	std::cout << subroot->value << " ";

	printTreeInorder(subroot->right);
}


template<class T>
void BST<T>::delTree(node<T> * subroot){
	if(subroot == NULL) return;
	delTree(subroot->left);
	delTree(subroot->right);

	delete subroot;
}

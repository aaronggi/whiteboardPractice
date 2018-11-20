#include "template.h"
int** cubealloc(int n){
	int **rows = new int* [n];
	for(int i = 0; i < n; i++){
		rows[i] = new int[n];
	}
	return rows;
}

inline void rotateLayer(int **matrix, int N, int layer){
	int min = layer, 
	max = N - 1 - layer;
	for(int i = layer, j = 0; 
		i < max; 
		i++, j++){
		//save top
		int temp = matrix[min][i];

		//set dest to src (order dest from order src)
		//set top to left (setting left-right from top-bottom)
		matrix[min][i] = matrix[max - j][min];

		//set left to bottom (setting bottom-top from right-left)
		matrix[max - j][min] = matrix[max][max - j];

		//set bottom to right (right-left from top-bottom)
		matrix[max][max - j] = matrix[i][max];

		//set right to top (top-bottom from left-right)
		matrix[i][max] = temp;
	}
}

void rotate(int **matrix, int N){
	for(int lyr = 0; lyr < N/2; lyr++){
		rotateLayer(matrix, N, lyr);
	}
}

int main(int argc, char**argv){
	int** arr = cubealloc(3);

	for(int i = 0; i < 3; i++){
		arr[i][0] = 3*i;
		arr[i][1] = 3*i + 1;
		arr[i][2] = 3*i + 2;

		std::cout << arr[i][0] << " ";
		std::cout << arr[i][1] << " ";
		std::cout << arr[i][2] << " \n";
	}

	rotate(arr, 3);

	std::cout << "\n";
	for(int i = 0; i < 3; i++){
		std::cout << arr[i][0] << " ";
		std::cout << arr[i][1] << " ";
		std::cout << arr[i][2] << " \n";
	}

}
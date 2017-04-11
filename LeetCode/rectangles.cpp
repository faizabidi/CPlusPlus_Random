#include <iostream>
#include <vector>
#include <queue>

void print(std::vector<std::vector<int> > matrix){
	for(int i = 0; i < matrix.size(); i++){
		for(int j = 0; j < matrix[i].size(); j++)
			std::cout << matrix[i][j] << " ";
		std::cout << std::endl;
	}
}

void calculate1(std::vector<std::vector<int> > matrix){
	for(int i = 0; i < matrix.size(); i++){
		bool flag = false;
		int width = 0, height = 0;
		for(int j = 0; j < matrix[i].size(); j++){
			if(matrix[i][j] == 0){
				flag = true;
				std::cout << "i = " << i << "\nj = " << j << std::endl;
				// Check width
				for(int k = j; k < matrix[i].size(); k++){
					if(matrix[i][k] == 0)
						width++;
				}
				// Check height
				for(int k = i; k < matrix.size(); k++){
					if(matrix[k][j] == 0)
						height++;
				}
				std::cout << "Width = " << width << "\nHeight = " << height << std::endl;
				break;
			}
		}
		if(flag)
			break;
	}
}

void calculate2_helper(std::vector<std::vector<int> > &matrix, int i, int j){
	// Find the height and the width
	// Change all the zeros to ones
	int width = 0, height = 0;
	for(int k = j; k < matrix[i].size(); k++){
		if(matrix[i][k] != 0)
			break;
		width++;
	}
	for(int k = i; k < matrix.size(); k++){
		if(matrix[k][j] != 0)
			break;
		height++;
	}
	std::cout << "Width = " << width << "\nHeight = " << height << std::endl;
	for(int k = i; k < i + height; k++){
		for(int l = j; l < j + width; l++){
			std::cout << "Erasing " << k << "," << l << std::endl;
			matrix[k][l] = 1;
		}
	}
}

void calculate2(std::vector<std::vector<int> > matrix){
	int ans = 0;
	for(int i = 0; i < matrix.size(); i++){
		for(int j = 0; j < matrix[i].size(); j++){
			if(matrix[i][j] == 0){
				ans++;
				std::cout << "i = " << i << ", j = " << j << std::endl;
				calculate2_helper(matrix, i, j);
				print(matrix);
				std::cout << std::endl;
			}
		}
	}
	std::cout << "Number of rectangles = " << ans << std::endl;
}

int main(){

	std::vector<std::vector<int> > matrix1 = {
	{1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1},
	{1, 1, 0, 0, 0, 0},
	{1, 1, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1}};

	//calculate1(matrix1);

	std::vector<std::vector<int> > matrix2 = {
	{0, 1, 0, 1, 1, 1},
	{1, 1, 1, 1, 1, 1},
	{0, 1, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1},
	{1, 0, 1, 1, 1, 1}};

	calculate2(matrix2);

	return 0;
}
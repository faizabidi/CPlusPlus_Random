#include <iostream>
#include <vector>
#include <queue>

void printMatrix(std::vector<std::vector<char> > matrix){
	for(int i = 0; i < matrix.size(); i++){
		for(int j = 0; j < matrix[i].size(); j++)
			std::cout << matrix[i][j] << " ";
		std::cout << std::endl;
	}
}

void BFS(std::vector<std::vector<char> > &matrix, int i, int j){
	std::queue<std::vector<int> > q;
	matrix[i][j] = '0';
	q.push({i,j});
	while(!q.empty()){
		int x = q.front()[0];
		int y = q.front()[1];
		q.pop();
		//matrix[x][y] = '0';
		// Check on the left in the same row
		if(y > 0 && matrix[x][y - 1] == '1'){
			q.push({x, y - 1});
			matrix[x][y - 1] = '0';
			std::cout << "Changed " << x << ", " << y - 1 << std::endl;
		}
		// Check on the right in the same row
		if(y < matrix[0].size() - 1 && matrix[x][y + 1] == '1'){
			q.push({x, y + 1});
			matrix[x][y + 1] = '0';
			std::cout << "Changed " << x << ", " << y + 1 << std::endl;
		}
		// Check on the above line
		if(x > 0 && matrix[x - 1][y] == '1'){
			q.push({x - 1, y});
			matrix[x - 1][y] = '0';
			std::cout << "Changed " << x - 1 << ", " << y << std::endl;
		}
		// Check on the line below
		if(x < matrix.size() - 1 && matrix[x + 1][y] == '1'){
			q.push({x + 1, y});
			matrix[x + 1][y] = '0';
			std::cout << "Changed " << x + 1 << ", " << y << std::endl;
		}
	}
}

int numIslands(std::vector<std::vector<char> > matrix){
	// 1 is land, 0 is water
	// A land is an island if conneted by
	int ans = 0;
	for(int i = 0; i < matrix.size(); i++){
		for(int j = 0; j < matrix[i].size(); j++){
			if(matrix[i][j] == '1'){
				ans++;
				std::cout << "i = " << i << ", j = " << j << std::endl;
				BFS(matrix, i, j);
			}
		}
	}
	return ans;
}

int main(){
	int rows, cols;
	std::cout << "Enter rows: ";
	std::cin >> rows;
	std::cout << "Enter columns: ";
	std::cin >> cols;

	std::vector<std::vector<char> > matrix;

	std::cout << "Enter the matrix\n";
	for(int i = 0; i < rows; i++){
		std::vector<char> temp(cols);
		for(int j = 0; j < cols; j++)
			std::cin >> temp[j];
		matrix.push_back(temp);
	}

	std::cout << "Matrix is\n";
	printMatrix(matrix);

	std::cout << "Islands = " << numIslands(matrix);
	return 0;
}
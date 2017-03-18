// https://www.hackerrank.com/challenges/diagonal-difference

#include <iostream>
#include <vector>

void printMatrix(std::vector<std::vector<int> > array){
	for(int i = 0; i < array.size(); i++){
		for(int j = 0; j < array[i].size(); j++){
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int calculate(std::vector< std::vector<int> > array){
	int primary_diagonal = 0;
	int secondary_diagonal = 0;
	for(int i = 0; i < array.size(); i++){
		for(int j = 0; j < array[i].size(); j++){
			if(i == j)
				primary_diagonal += array[i][j];
			if(i + j == array.size() - 1)
				secondary_diagonal += array[i][j];
		}
	}

	return std::abs(primary_diagonal - secondary_diagonal);
}

int main(){
    int n;
    std::cin >> n;
    // Create a vector of vectors
    // n rows and variable columns
    std::vector< std::vector<int> > a(n, std::vector<int>(n));

    for(int i = 0; i < n; i++){
       for(int j = 0; j < n; j++){
          std::cin >> a[i][j];
       }
    }

    int ans = calculate(a);

    std::cout << ans << std::endl;
    return 0;
}

#include <iostream>
#include <vector>

void print(std::vector<std::vector<int>> array){
	for(int i = 0; i < array.size(); i++){
		std::vector<int> temp = array[i];
		for(int j = 0; j < temp.size(); j++)
			std::cout << temp[j] << "  ";
		std::cout << std::endl;
	}
}

// REF: http://mathworld.wolfram.com/MagicSquare.html
void magicSqaures(int n){
	std::vector<std::vector<int>> array(3, std::vector<int>(3));

	int i = 0, j = 1, k = 1;

	// Initialize as all -1
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			array[i][j] = -1;
	}

	print(array);
	
	array[i][j] = k;
	while(k != 9){
		k++;
		int temp1 = i, temp2 = j;
		i--;j++;
			
		if(i < 0)
			i = 2;
			
		if(j > 2)
			j = 0;
		
		if(array[i][j] != -1){
			i = temp1; j = temp2;
			i++;
			if(i > 2)
				i = 0;
		}
		array[i][j] = k;
	}

	std::cout << "Magic square of n = 3\n";

	print(array);
}

int main() {
    int n = 3;
    magicSqaures(3);

    return 0;
}

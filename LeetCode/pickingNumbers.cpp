#include <iostream>
#include <vector>

void printVector(std::vector<int> array){
    for(int i = 0; i < array.size(); i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

int calculate(std::vector<int> array){
	int ans = 0;
	
	for(int i = 0; i < array.size(); i++){
		int num = array[i];
		int num_left = num - 1, num_right = num + 1, temp = 1;
		// Count the number of num_left and num_right
		// Which ever is bigger, use that
		int count_left = 0, count_right = 0;
		for(int j = 0; j < array.size() && j != i; j++){
			if(array[j] == num_left)
				count_left++;
			if(array[j] == num_right)
				count_right++;
			if(array[j] == num)
				temp++;
		}
		if(count_left >= count_right)
			temp += count_left;
		else
			temp += count_right;

		if(temp > ans)
			ans = temp;
	}

	return ans;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++)
       std::cin >> a[a_i];
    
    std::cout << calculate(a) << std::endl;

    return 0;
}

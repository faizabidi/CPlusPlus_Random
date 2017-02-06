#include <iostream>
#include <vector>

void ModifedBubbleSort(int n, std::vector<int> array){
	int num_swaps = 0;
	for(int i = 0; i < array.size(); i++){
		for(int j = 0; j < array.size() - 1; j++){
			if(array[j] > array[j+1]){
				std::swap(array[j], array[j+1]);
				num_swaps++;
			}
		}
		if(num_swaps == 0)
			break;
	}
	std::cout << "Array is sorted in " << num_swaps << " swaps.\n";
	std::cout << "First Element: " << array.front() << std::endl;
	std::cout << "Last Element: " << array.back() << std::endl;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++)
       std::cin >> a[i];
    
    ModifedBubbleSort(n, a);

    return 0;
}

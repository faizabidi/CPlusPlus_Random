#include <iostream>
#include <sstream>
#include <vector>

void find_combos(int num_desired, std::vector<int> array){
	bool flag = false;

	for(int i = 0; i < array.size(); i++){
		int num_needed = num_desired - array[i];
		for(int j = i + 1; j <= array.size(); j++){
			if(array[j] == num_needed){
				std::cout << array[i] << "," << array[j] << std::endl;
				flag = true;
			}
		}
	}
	// If num_desired can be formed with the packs available
	if(flag){
		for(int i = 0; i < num_desired; i++)
			std::cout << 1 << ",";
	}
	std::cout << std::endl;
}

int main(){
	int num_desired;
	std::string available_pack_sizes;
	std::vector<int> avail_packs;

	std::cout << "How many sodas do you want? ";
	std::cin >> num_desired;
	std::cin.ignore();

	std::cout << "Enter the available pack sizes:";
	getline(std::cin, available_pack_sizes);

	std::stringstream ss(available_pack_sizes);
	std::string buf;

	// Store the packs as integers in the vector
    while(ss >> buf)
        avail_packs.push_back(std::stoi(buf));

    find_combos(num_desired, avail_packs);

	return 0;
}
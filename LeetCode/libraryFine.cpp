#include <iostream>
#include <vector>

int calculateFine(std::vector<int> &actual, std::vector<int> &expected){
    int fine = 0;
    
    if(actual[2] == expected[2] && actual[1] == expected[1] && actual[0] > expected[1])
        fine = 15 * (actual[0] - expected[0]);
    else if(actual[2] == expected[2] && actual[1] != expected[1] && actual[1] > expected[1])
    	fine = 500 * (actual[1] - expected[1]);
    else if(actual[2] != expected[2] && actual[2] > expected[2])
        fine = 10000;
    else
    	fine = 0;
    return fine;
}

int main() {
    std::vector<int> actual;
    std::vector<int> expected;

    for(int i = 0; i < 3; i++){
    	int value_actual;
    	std::cin >> value_actual;
    	actual.push_back(value_actual);
   	}

   	for(int i = 0; i < 3; i++){
    	int value_expected;
    	std::cin >> value_expected;
    	expected.push_back(value_expected);
   	}

   	std::cout << calculateFine(actual, expected);

    return 0;
}

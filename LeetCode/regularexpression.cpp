#include <iostream>
#include <vector>

int main(){
    int N;
    std::cin >> N;
    std::vector<std::string> names;
    for(int i = 0; i < N; i++){
        std::string firstName;
        std::string emailID;
        std::cin >> firstName >> emailID;
        // If contains @gmail.com
        if (emailID.find("@gmail.com") != std::string::npos)
        	names.push_back(firstName);
    }
    // Sort the vector
    std::sort(names.begin(), names.end());
    for(int i = 0; i < N; i++)
    	std::cout << names[i] << std::endl;
    return 0;
}

#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

int main()
{ 
    std::fstream myfile("data.txt"); // should also test if it's open correctly
    
    std::vector<double> x(std::istream_iterator<double>(myfile), {});
    
    std::sort(x.begin(), x.end());

    for(const auto& elem: x)
        std::cout << elem << " ";
}
// https://www.hackerrank.com/challenges/plus-minus

#include <iostream>
#include <iomanip>

int main(){
    int n;
    int positive_count = 0;
    int negative_count = 0;
    int zero_count = 0;
    int total_count = 0;
    
    std::cin >> n;

    for(int i = 0; i < n; i++){
       int num;
       std::cin >> num;
        if(num > 0)
            positive_count++;
        else if(num < 0)
            negative_count++;
        else
            zero_count++;
        total_count++;
    }

    // std::precision tells the maximum number of digits to use not the minimum
    // Hence, also need to pass std::fixed for cases like 0.5 to show as 0.500000
    std::cout << std::fixed;
    std::cout << std::setprecision(6);

    std::cout << float(positive_count) / float(total_count) << std::endl;
    std::cout << float(negative_count) / float(total_count) << std::endl;
    std::cout << float(zero_count) / float(total_count) << std::endl;
    return 0;
}

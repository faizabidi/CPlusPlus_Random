#include <iostream>
#include <vector>

double bonAppetit(int n, int k, int b, std::vector <int> ar) {
    float cost_real = 0;
    for(int i = 0; i < n; i++){
        if(i != k)
            cost_real += double(ar[i]) / 2;
    }

    return cost_real;
}

int main() {
    int n;
    int k;
    std::cin >> n >> k;
    std::vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++)
       std::cin >> ar[ar_i];
    
    int b;
    std::cin >> b;
    
    double cost_real = bonAppetit(n, k, b, ar);

    //std::cout << cost_real << std::endl;
    if(cost_real == b)
        std::cout << "Bon Appetit\n";
    else
        std::cout << b - cost_real << std::endl;
    return 0;
}

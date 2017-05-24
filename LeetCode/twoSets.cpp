// https://www.hackerrank.com/challenges/between-two-sets

#include <iostream>
#include <vector>

void print_Vector(std::vector<int> array){
    for(int i = 0; i < array.size(); i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

// LCM of a, b = (a * b) / GCD(a, b);
int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

int getTotalX(std::vector <int> a, std::vector <int> b){
    int smallest = *std::min_element(a.begin(), a.end());
    int largest = *std::min_element(b.begin(), b.end());
    int i = smallest;
    
    std::vector<int> temp1, temp2, ans;
    

    // Store all possible values in a temporary vector
    while(i <= largest){
        temp1.push_back(i);
        i++;
    }

    // Check all values against the first vector first
    for(int k = 0; k < temp1.size(); k++){
        bool flag = true;
        for(int l = 0; l < a.size(); l++){
            if(temp1[k] % a[l] != 0)
                flag = false;
        }
        if(flag)
            temp2.push_back(temp1[k]);
    }

    // Check all values against the second vector and refine the results
    for(int k = 0; k < temp2.size(); k++){
        bool flag = true;
        for(int l = 0; l < b.size(); l++){
            if(b[l] % temp2[k] != 0)
                flag = false;
        }
        if(flag)
            ans.push_back(temp2[k]);
    }

    // The size of the ans vector is our answer
    return ans.size();
}

// Better time complexity
int getTotalX2(std::vector <int> a, std::vector <int> b){
    // Find the lcm of a
    int lcm_val = 1;
    for(int i = 0; i < a.size(); i++)
        lcm_val = lcm(lcm_val, a[i]);

    // Find gcd of b
    int gcd_val = 0;
    for(int i = 0; i < b.size(); i++)
        gcd_val = gcd(gcd_val, b[i]);

    // Find out how many multiples of lcm evenly divides gcd
    int i = lcm_val;
    int count = 0;
    while(i <= gcd_val){
        if(gcd_val % i == 0)
            count++;
        i += lcm_val;
    }

    return count;
}

int main(){
    int n;
    int m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++)
       std::cin >> a[a_i];
    
    std::vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++)
       std::cin >> b[b_i];
    
    int total = getTotalX2(a, b);
    std::cout << total << std::endl;
    return 0;
}

// https://www.hackerrank.com/challenges/sherlock-and-array/problem

#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate

int sumLeft(int pos, std::vector<int> array){
    if(pos == 0)
        return 0;
    int sum = 0;
    for(int i = pos - 1; i >= 0; i--)
        sum+=array[i];
    return sum;
}

int sumRight(int pos, std::vector<int> array){
    if( pos == array.size() - 1)
        return 0;
    int sum = 0;
    for(int i = pos + 1; i < array.size(); i++)
        sum+=array[i];
    return sum;
}


// O(nxn)
std::string solve(std::vector <int> a){
    // For Each element, check if there exists any such number
    bool flag = false;
    for(int i = 0; i < a.size(); i++){
        int left = sumLeft(i, a);
        int right = sumRight(i, a);
        if(left == right){
            flag = true;
            break;
        }
    }
    if(flag)
        return "YES";
    return "NO";
}

// O(n)
std::string solve2(std::vector <int> a){
    // Find the total sum of the elements in the array
    int totalSum = std::accumulate(a.begin(), a.end(), 0);

    int rightSum = totalSum - a[0];
    int leftSum = 0;
    for(int i = 0; i < a.size(); i++){
        //std::cout << "Element is " << a[i] << std::endl;
        //std::cout << "Right sum = " << rightSum << std::endl;
        //std::cout << "Left sum = " << leftSum << std::endl;
        if(leftSum == rightSum)
            return "YES";
        else{
            leftSum += a[i];
            rightSum -= a[i + 1];
        }
    }
    return "NO";
}

int main() {
    int T;
    std::cin >> T;
    for(int a0 = 0; a0 < T; a0++){
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for(int a_i = 0; a_i < n; a_i++)
           std::cin >> a[a_i];
        std::string result = solve2(a);
        std::cout << result << std::endl;
    }
    return 0;
}

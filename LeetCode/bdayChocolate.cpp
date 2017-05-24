// https://www.hackerrank.com/challenges/the-birthday-bar
#include <vector>
#include <iostream>

using namespace std;

int solve(int n, vector <int> s, int d, int m){
    int ways = 0;
    for(int i = 0; i < s.size(); i++){
        int j = i;
        int sum = 0;
        //std::cout << "j = " << j << std::endl;
        while(j < m + i && j < s.size()){
            //std::cout << "Hello\n";
            sum += s[j];
            j++;
        }
        //std::cout << "Sum = " << sum << std::endl;
        if(sum == d && j == m + i)
            ways++;
    }
    return ways;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    int d;
    int m;
    cin >> d >> m;
    int result = solve(n, s, d, m);
    cout << result << endl;
    return 0;
}

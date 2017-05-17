// https://www.hackerrank.com/challenges/apple-and-orange

#include <iostream>
#include <vector> 

using namespace std;

void calculate(int s, int t, int a, int b, int m, int n, vector<int> apple, vector<int> orange){
    int apples = 0, oranges = 0;
    for(int i = 0; i < m; i++){
        if(a + apple[i] >= s && a + apple[i] <= t)
            apples++;
    }
    for(int i = 0; i < n; i++){
        if(b + orange[i] >= s && b + orange[i] <= t)
            oranges++;
    }
    std::cout << apples << std::endl << oranges;
}

int main(){
    int s;
    int t;
    cin >> s >> t;
    int a;
    int b;
    cin >> a >> b;
    int m;
    int n;
    cin >> m >> n;
    vector<int> apple(m);
    for(int apple_i = 0;apple_i < m;apple_i++){
       cin >> apple[apple_i];
    }
    vector<int> orange(n);
    for(int orange_i = 0;orange_i < n;orange_i++){
       cin >> orange[orange_i];
    }

    calculate(s, t, a, b, m, n, apple, orange);
    return 0;
}
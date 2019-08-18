#include <iostream>
#include <cmath>

using namespace std;

double root(double x, unsigned int n){
  // Binary search
  double low = 0, high = x, mid;
  while(low <= high){
    mid = (low+high) / 2;
    double temp = pow(mid, n);
    // When the number comes close enough
    if(abs(temp - x) <= 0.001)
      return mid;
    if(temp > x)
      high = mid;
    else
      low = mid;
  }
  return mid;
}

int main(){
  double n;
  int m;
  cin >> n >> m;
  cout << root(n, m) << endl;
  return 0;
}
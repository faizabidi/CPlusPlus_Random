#include <iostream>
#include <climits>

void printAns(int n, int k){
	int ans = INT_MIN;;
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			int bitwiseAnd = (i & j);
			if(bitwiseAnd > ans && bitwiseAnd < k)
				ans = bitwiseAnd;
		}
	}
	std::cout << ans << std::endl;
}

int main(){
    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        int k;
        std::cin >> n >> k;
        printAns(n, k);
    }
    return 0;
}

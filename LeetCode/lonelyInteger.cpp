#include <iostream>
#include <map>
#include <vector>

int lonely_integer(std::vector<int> a){
    std::map<int, int> hash;
    int res;
    // Add values to hashmap, and increment key
    for(int i = 0; i < a.size(); i++)
    	hash[a[i]]++;
    std::map<int, int>::iterator it;
    for(it = hash.begin(); it != hash.end(); it++){
    	if(it->second == 1){
    		res = it->first;
    		break;
    	}
    }
    return res;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++)
       std::cin >> a[i];
    
    std::cout << lonely_integer(a) << std::endl;
    return 0;
}

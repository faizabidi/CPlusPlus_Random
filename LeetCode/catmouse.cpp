#include <iostream>
#include <vector>

void check(int x, int y, int z){
	if(std::abs(z - y) < std::abs(z - x))
		std::cout << "Cat B\n";
	else if(std::abs(z - y) > std::abs(z - x))
		std::cout << "Cat A\n";
	else
		std::cout << "Mouse C\n";
}

int main(){
    int q;
    std::cin >> q;

    for(int a0 = 0; a0 < q; a0++){
        int x;
        int y;
        int z;
        std::cin >> x >> y >> z;
        check(x, y, z);
    }

    return 0;
}

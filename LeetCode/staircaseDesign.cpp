#include <iostream>

/*
######
#####
####
###
##
#
*/
void printDesign1(int n){
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++)
			std::cout << "#";
		std::cout << std::endl;
	}
}

/*
#
##
###
####
#####
######
*/
void printDesign2(int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++)
			std::cout << "#";
		std::cout << std::endl;
	}
}

/*
	 #
    ##
   ###
  ####
 #####
######
*/
void printDesign3(int n){
	for(int i = 0; i < n; i++){
		for(int k = i; k < n - 1; k++)
			std::cout << " ";
		for(int j = 0; j <= i; j++)
			std::cout << "#";
		std::cout << std::endl;
	}
}

int main(){
    int n;
    std::cin >> n;

    printDesign3(n);

    return 0;
}

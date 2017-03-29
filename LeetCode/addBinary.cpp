#include <iostream>

std::string add(std::string binary1, std::string binary2){
	std::string binary1_new, binary2_new, result;
	int size1 = binary1.size();
	int size2 = binary2.size();

	if(size1 > size2){
		int diff = size1 - size2;
		while(diff > 0){
			binary2_new += '0';
			diff--;
		}
		binary2_new += binary2;
		// Save it in the original string
		binary2 = binary2_new;
	}
	else if(size2 > size1){
		int diff = size2 - size1;
		while(diff > 0){
			binary1_new += '0';
			diff--;
		}
		binary1_new += binary1;
		// Save it in the original string
		binary1 = binary1_new;
	}

	char carry;
	
	for(int i = binary1.size() - 1; i >= 0; i--){
		if( (binary1[i] == '0' && binary2[i] == '1') || 
			(binary1[i] == '1' && binary2[i] == '0') ){
			if(carry == '1'){
				result += '0';
				carry = '1';
			}
			else{
				result += '1';
				carry = '0';
			}
		}
		else if(binary1[i] == '0' && binary2[i] == '0'){
			if(carry == '1'){
				result += '1';
				carry = '0';
			}
			else{
				result += '0';
				carry = '0';
			}
		}
		else{
			if(carry == '1'){
				result += '1';
				carry = '1';
			}
			else{
				result += '0';
				carry = '1';
			}
		}
	}
	std::reverse(result.begin(), result.end());
	std::string temp;
	if(carry == '1')
		temp += '1';
	temp += result;
	result = temp;
	return result;
}

int main(){
	std::string binary1, binary2;
	
	std::cout << "Enter the first binary number:";
	std::cin >> binary1;

	std::cout << "Enter the second binary number:";
	std::cin >> binary2;

	std::cout << add(binary1, binary2) << std::endl;

	return 0;
}
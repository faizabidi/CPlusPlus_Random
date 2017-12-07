#include <iostream>

std::string sum(std::string sum1, std::string sum2){
	// Reverse the strings to add the least significant number first
	std::reverse(sum1.begin(), sum1.end());
	std::reverse(sum2.begin(), sum2.end());

	std::string ans = "";
	int size1 = sum1.size();
	int size2 = sum2.size();
	int i = 0, carry = 0;
	while(i < size1 && i < size2){
		std::string temp = std::to_string((sum1[i] - '0') + (sum2[i] - '0') + carry);
		if(temp.size() > 1){
			ans += temp[1];
			carry = temp[0] - '0';
		}
		else{
			ans += temp[0];
			carry = 0;
		}
		i++;
	}
	// Add any remaining digits left
	for(int j = i; j < sum1.size(); j++){
		std::string temp = std::to_string((sum1[j] - '0') + carry);
		if(temp.size() > 1){
			ans += temp[1];
			carry = temp[0] - '0';
		}
		else{
			ans += temp[0];
			carry = 0;
		}
	}
	for(int j = i; j < sum2.size(); j++){
		std::string temp = std::to_string((sum2[j] - '0') + carry);
		if(temp.size() > 1){
			ans += temp[1];
			carry = temp[0] - '0';
		}
		else{
			ans += temp[0];
			carry = 0;
		}
	}
	// If any carry still left, add that too
	if(carry != 0)
		ans += std::to_string(carry);
	std::reverse(ans.begin(), ans.end());
	return ans;
}

int main(){
	std::string sum1, sum2;
	std::cin >> sum1 >> sum2;
	std::cout << sum(sum1, sum2) << std::endl;

	return 0;
}
#include <iostream>
#include <vector>

std::string replace(std::string main_str, std::string sub_str){
	std::string temp;
	for(int i = 0; i < main_str.size(); i++){
		// When not a white space, add to temp
		if(main_str[i] != ' ')
			temp += main_str[i];
			
		// Keep scnanning till you hit a whitespace
		// When you do, compare this with the sub_str
		// If it is not the same, replace it with stars
		else if(main_str[i] == ' '){
			if(temp != sub_str){
				int start_position = i - temp.size();
				int end_position = i - 1;
				
				for(int j = start_position; j <= end_position; j++)
					main_str[j] = '*';
				// Re-initialize temp
				temp = "";
			}
			else if(temp == sub_str)
				temp = "";
		}
		// When you hit the last word
		if(i + 1 == main_str.size()){
			if(temp != sub_str){
				int start_position = i - temp.size() + 1;
				int end_position = i;
				for(int j = start_position; j <= end_position; j++)
					main_str[j] = '*';
			}
		}
	}
	return main_str;
}

int main(){
	std::string main_str;
	std::cout << "Enter main string:";
	getline(std::cin, main_str);

	std::string sub_str;
	std::cout << "Enter the sub-string that you don't want replaced:";
	std::cin >> sub_str;

	std::cout << replace(main_str, sub_str) << std::endl;

	return 0;
}
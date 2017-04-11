#include <sstream> 
#include <iostream>
#include <vector>

void print(std::vector<std::string> array){
    for(int i = 0; i < array.size(); i++)
        std::cout << array[i] << " ";
    std::endl;
}

void reverseWords(std::string s){
    std::string temp;
    std::vector<std::string> ans;
    std::reverse(s.begin(), s.end());
    for(int i = 0; i < s.size(); i++){
        if(s[i] != ' ')
            temp += s[i];
        else if(s[i] == ' '){
            std::reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            temp = "";
            std::cout << temp << std::endl;
            while(s[i] == ' ')
                i++;
            temp += s[i];
        }
        if(i == s.size() - 1)
            ans.push_back(temp);
    }
    print(ans);
}

int main(){
	std::string str;
	getline(std::cin, str);
	reverseWords(str);

	return 0;
}
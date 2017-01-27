// https://www.hackerrank.com/challenges/designer-pdf-viewer

#include <iostream>
#include <vector>

int height(std::vector<int> h, std::string word){
	int max_height = 0;
	for(int i = 0; i < word.size(); i++){
		int num = int(word[i]) - 97;
		int height = h[num];
		if(height > max_height)
			max_height = height;
	}
	return (max_height * word.size());
}

int main(){
    std::vector<int> h(26);
    for(int i = 0; i < 26; i++){
       std::cin >> h[i];
    }
    std::string word;
    std::cin >> word;

    std::cout << height(h, word);
    return 0;
}

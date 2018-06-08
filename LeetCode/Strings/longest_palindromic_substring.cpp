// https://leetcode.com/problems/longest-palindromic-substring/solution/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


/******************************************/
// Helper functions
bool isPalindrome(std::string str){
	std::string str_orig = str;
	std::reverse(str.begin(), str.end());
	if(str == str_orig)
		return true;
	return false;
}

void printMatrix(std::vector<std::vector<int>> matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
}
/******************************************/
// Brute force - O(nxnxn)
std::string longestPalindrome(std::string str){
    std::string ans;
    for(int i = 0; i < str.size(); i++){
    	std::string temp;
    	temp += str[i];
    	if(isPalindrome(temp) && temp.size() > ans.size())
    		ans = temp;
    	for(int j = i + 1; j < str.size(); j++){
    		temp += str[j];
    		if(isPalindrome(temp) && temp.size() > ans.size()){
    			ans = temp;
    			if(ans.size() == str.size() - i)
    				return ans;
    		}
    	}
    }
    return ans;
}
/******************************************/
// Bottoms-up
// https://www.youtube.com/watch?v=Fi5INvcmDos
// https://www.tutorialcup.com/string/longest-palindromic-substring.htm
// I still don't entirely get it I think. Don't know how to come up 
// with solutions like that in the moment
std::string longestPalindrome_dp(std::string str){
    std::vector<std::vector<int>> matrix(str.size(), 
                                        std::vector<int>(str.size(), 9));
    
    if(str.size() < 2)
        return str;

    std::string ans = "";
    int maxLength = 0;
    int start = 0;

    // Length of 1
    for(int i = 0; i < str.size(); i++){
        matrix[i][i] = 1;
        start = i;
        maxLength = 1;
    }
    
    // Length of 2
    for(int i = 1; i < str.size(); i++){
        if(str[i] == str[i-1]){
            matrix[i-1][i] = 1;
            start = i - 1;
            maxLength = 2;
        }
    }

    // Length > 2
    for(int len = 2; len <= str.size(); len++){
        for(int i = 0; i < str.size() - len + 1; i++){
            int j = len + i - 1;
            if(str[i] == str[j]){
                // Check the middle part
                if(matrix[i+1][j-1] == 1){
                    matrix[i][j] = 1;
                    // Store the palindrome
                    if(len > maxLength){
                        maxLength = len;
                        start = i;
                    }
                }
            }
        }
    }
    return str.substr(start, maxLength);
}
/******************************************/
int main(){
	//std::string str = "ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy"; // Ans = fklkf

    //std::string str = "babaddtattarrattatddetartrateedredividerb";
    //std::string str = "abadsdgjf"; // Ans = aba
    
    //std::string str = "abaabc"; // Ans = baab
    //std::string str = "banana"; // Ans = anana
    //std::string str = "abcda"; // Ans = a
    //std::string str = "faiaz"; // Ans = aia
    //std::string str = "ababc"; // Ans = aba
    // std::string str = ""; // Ans = ""
    
    std::string str = "jglknendplocymmvwtoxvebkekzfdhykknufqdkntnqvgfbahsljkobhbxkvyictzkqjqydczuxjkgecdyhixdttxfqmgksrkyvopwprsgoszftuhawflzjyuyrujrxluhzjvbflxgcovilthvuihzttzithnsqbdxtafxrfrblulsakrahulwthhbjcslceewxfxtavljpimaqqlcbrdgtgjryjytgxljxtravwdlnrrauxplempnbfeusgtqzjtzshwieutxdytlrrqvyemlyzolhbkzhyfyttevqnfvmpqjngcnazmaagwihxrhmcibyfkccyrqwnzlzqeuenhwlzhbxqxerfifzncimwqsfatudjihtumrtjtggzleovihifxufvwqeimbxvzlxwcsknksogsbwwdlwulnetdysvsfkonggeedtshxqkgbhoscjgpiel";

	std::cout << longestPalindrome(str) << std::endl;

    std::cout << longestPalindrome_dp(str) << std::endl;


    std::cout << str.size() << std::endl;
	return 0;
}

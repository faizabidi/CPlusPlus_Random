#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
	bool isPalindrome(std::string str){
		std::string str_orig = str;
		std::reverse(str.begin(), str.end());
		if(str == str_orig)
			return true;
		return false;
	}
	// O(nxnxn)
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
    // TO-DO
    // Optimized version - O(nxn)
    std::string longestPalindrome2(std::string str){
    }
};

int main(){
	Solution obj1;
	std::cout << obj1.longestPalindrome("azwdzwmwcqzgcobeeiphemqbjtxzwkhiqpbrprocbppbxrnsxnwgikiaqutwpftbiinlnpyqstkiqzbggcsdzzjbrkfmhgtnbujzszxsycmvipjtktpebaafycngqasbbhxaeawwmkjcziybxowkaibqnndcjbsoehtamhspnidjylyisiaewmypfyiqtwlmejkpzlieolfdjnxntonnzfgcqlcfpoxcwqctalwrgwhvqvtrpwemxhirpgizjffqgntsmvzldpjfijdncexbwtxnmbnoykxshkqbounzrewkpqjxocvaufnhunsmsazgibxedtopnccriwcfzeomsrrangufkjfzipkmwfbmkarnyyrgdsooosgqlkzvorrrsaveuoxjeajvbdpgxlcrtqomliphnlehgrzgwujogxteyulphhuhwyoyvcxqatfkboahfqhjgujcaapoyqtsdqfwnijlkknuralezqmcryvkankszmzpgqutojoyzsnyfwsyeqqzrlhzbc");
	//std::cout << obj1.longestPalindrome("ababababa");
	return 0;
}
#include <iostream>
#include <vector>

class Solution {
private:
	std::vector<char> stack;
	std::vector<char> queue;
	int stack_top;
	int queue_bottom;
public:
    Solution(){
    	stack_top = -1;
    	queue_bottom = 0;
    };

    void pushCharacter(char ch){
    	stack.push_back(ch);
    	stack_top++;	
    }
    void enqueueCharacter(char ch){
    	queue.push_back(ch);
    }
    char popCharacter(){
    	char tmp = stack[stack_top--];
    	stack.erase(stack.end() - 1);
    	return tmp;
    }
    char dequeueCharacter(){
    	char tmp = queue[queue_bottom++];
    	queue.erase(queue.begin());
    	return tmp;
    }
};

int main() {
    // read the string s.
    std::string s;
    getline(std::cin, s);
    
  	// create the Solution class object p.
    Solution obj;
    
    // push/enqueue all the characters of string s to stack.
    for(int i = 0; i < s.length(); i++){
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    
    bool isPalindrome = true;
    
    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for(int i = 0; i < s.length() / 2; i++){
        if(obj.popCharacter() != obj.dequeueCharacter()){
            isPalindrome = false;
            break;
        }
    }
    
    // finally print whether string s is palindrome or not.
    if(isPalindrome)
        std::cout << "The word, " << s << ", is a palindrome.";
    else
        std::cout << "The word, " << s << ", is not a palindrome.";
    
    return 0;
}
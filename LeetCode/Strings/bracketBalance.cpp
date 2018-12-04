// Check if brackets and single quotes are balanced

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// O(n) time and O(n) space
bool check(string str){
  // Base case
  if(str.size() == 0)
    return true;
  stack<char> s;
  int count_quotes = 0;
  for(int i = 0; i < str.size(); i++){
    // Check if an open bracket, push to Stack
    if(str[i] != '\''){
      // Check if a string character
      if(isalpha(str[i])){
        int j = i;
        while(isalpha(str[j]) && j < str.size())
          j++;
        i = j - 1;
      }
      else{
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
          s.push(str[i]);
        else{
          // Check what's at the top of the stack
          if(s.size() > 0){
            char top = s.top();
            // Case 1
            if(str[i] == ')'){
              if(top == '(')
                // Pop from stack
                s.pop();
              else
                return false;
            }
            else if(str[i] == '}'){
              if(top == '{')
                // Pop from stack
                s.pop();
              else
                return false;
            }
            else if(str[i] == ']'){
              if(top == '[')
                // Pop from stack
                s.pop();
              else
                return false;
            }
          }
          else
            return false;
        }
      }
    }
    // If we find a quote
    else{
      // Keep scanning while we don't find a closing quote 
      int j = i+1;
      count_quotes++;
      while(str[j] != '\'' && j < str.size())
        j++;
      if(str[j] == '\'')
        count_quotes++;
      i = j;
    }
  }
  if(s.size() != 0 || count_quotes%2 != 0)
    return false;
  return true;
}

void test(string s, bool expected) {
  bool actual = check(s);
  if ( actual == expected ) {
    cout << "PASS '" << s << "'" << std::endl;
  } else {
    cout << "FAIL '" << s << "' expected " << expected << " got " << actual << std::endl;
  }
}

int main() {
 
  test("hello(){}[])", false);
  test("[(])", false);
  test("(])", false);
  test("[()]", true);
  test("[()", false);
  test("", true);
  test("(){}[]", true);

  test("[')']", true);
  test("[']", false);
  test("print(')')", true);
  test("(')')", true);
  test("[]'[]", false);

return 0;
}

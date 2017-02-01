#include <iostream>
#include <stack>
#include <queue>

bool is_balanced(std::string expression){
    std::stack<char> stack;
    for(int i = 0; i < expression.size(); i++){
        if(expression[i] == '[' || expression[i] == '(' || expression[i] == '{')
            stack.push(expression[i]);
        else if (!stack.empty()){
            char ch = stack.top();
            stack.pop();
            if(ch == '[' && expression[i] != ']')
                return false;
            if(ch == '(' && expression[i] != ')')
                return false;
            if(ch == '{' && expression[i] != '}')
                return false;
        }
        else
            return false;
    }
    if(!stack.empty())
        return false;
    return true;
}

int main(){
    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        std::string expression;
        std::cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            std::cout << "YES\n";
        else 
            std::cout << "NO\n";
    }
    return 0;
}
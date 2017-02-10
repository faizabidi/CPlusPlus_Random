#include <iostream>
#include <stack>

class MyQueue{
    public:
        std::stack<int> in, out;   
        void push_q(int x){
            in.push(x); 
        }

        void pop_q(){
            // If out is empty
            // Push everything on "out" stack
            if(out.empty()){
                while(!in.empty()){
                    out.push(in.top());
                    in.pop();
                }
            }
            out.pop();
        }

        int front_q(){
            // If out is empty
            // Push everything on "out" stack
            // and print the top
            if(out.empty()){
                while(!in.empty()){
                    out.push(in.top());
                    in.pop();
                }
            }
            return out.top();    
        }
};

int main(){
    MyQueue q1;
    int q, type, x;
    std::cin >> q;
    
    for(int i = 0; i < q; i++){
        std::cin >> type;
        if(type == 1){
            std::cin >> x;
            q1.push_q(x);
        }
        else if(type == 2)
            q1.pop_q();
        else 
            std::cout << q1.front_q() << std::endl;
    }
    
    return 0;
}
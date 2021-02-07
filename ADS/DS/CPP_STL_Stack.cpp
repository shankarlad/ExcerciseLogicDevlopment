
#include <stack>
#include <iostream>

using namespace std;

string isBalanced(string s) {  
   stack<char> stack;
    for(int i=0;i< s.length();i++){
        char c = s[i];
        if (c == '{' || c == '[' || c == '(') 
            stack.push(c);
        else{
            if(c == '}'){
                if(stack.empty() ||  stack.top() != '{' )
                    return "NO";
                else stack.pop();
            }
            else if(c == ')'){
                if(stack.empty() ||  stack.top() != '(')
                    return "NO";
                else stack.pop();
            } 
            else if(c == ']'){
                if(stack.empty() ||  stack.top() != '[')
                    return "NO";
                else stack.pop();
            }  
        }

    }
    if(!stack.empty()) return "NO";
    else return "YES";
}


int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        string s;
        cin >> s;
        cout << isBalanced(s) << endl;
    }
    return 0;
}

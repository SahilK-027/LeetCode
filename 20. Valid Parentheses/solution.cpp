/*
Runtime: 0 ms
Memory Usage: 6.4 MB
*/

class Solution {
//Push Down Automata Logic
public:
    bool isValid(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        //  If length of string is 1 its definietly not valid
        if(s.length() == 1)
            return false;
        int n = s.length();
        stack<char> stack;
        for(int i = 0 ; i< n ; i++){
            // for every ( , { , [ we will push it to stack
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stack.push(s[i]);
            }
            
            // for every ) ,},] we will check if top of stack is opening pranthesis or NOT
            else if(s[i] == ')'){
                if(!stack.empty() && stack.top() == '('){
                    stack.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i] == '}'){
                if(!stack.empty() && stack.top() == '{'){
                    stack.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i] == ']'){
                if(!stack.empty() && stack.top() == '['){
                    stack.pop();
                }
                else{
                    return false;
                }
            }
        }
        // After ending string if stack is empty we can say input is valid
        if(stack.empty()){
            return true;
        }
        return false;
    }
};

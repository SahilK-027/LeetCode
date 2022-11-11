class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        for(int i = 0 ; i < s.length(); i++){
            if(s[i] == '#' && !st1.empty()){
                st1.pop();
            }
            else if(s[i] != '#')
            { 
                st1.push(s[i]);
            }
        }
        for(int i = 0 ; i < t.length(); i++){
            if(t[i] == '#' && !st2.empty()){
                st2.pop();
            }
            else if(t[i] != '#')
            {
                st2.push(t[i]);
            }
        }
        while(!st2.empty() && !st1.empty()){
            char a = st1.top();
            char b = st2.top();
            if(a != b){
                return false;
            }
            st1.pop();
            st2.pop();
        } 
        if(!st2.empty()){
            return false;
        }
        if(!st1.empty()){
            return false;
        }
        return true;
    }
};
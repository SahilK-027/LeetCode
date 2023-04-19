/*
Runtime : 13 ms
Memory : 8.3 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : Sahilk-027
 * @brief : Stack
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0 ; i < s.size(); i++){
            char curr = s[i];
            switch(curr){
                case 'a': 
                    st.push('a');
                    break;
                case 'b':
                    st.push('b');
                    break;
                case 'c':
                    char top;
                    if( !st.empty() ){
                        top = st.top();
                    }
                    else{
                        return false;
                    }
                    if(top == 'c' || top == 'a'){
                        return false;
                    }
                    if(top == 'b'){
                        if(!st.empty()) st.pop();
                        char curr_stack_top;
                        if(!st.empty()){
                            curr_stack_top = st.top();
                        }
                        else{
                            return false;
                        }
                        if(curr_stack_top == 'a'){
                            st.pop();
                            break;
                        }
                        else{
                            return false;
                        }

                    }
                    break;
            }
        }
        return st.empty();
    }
};
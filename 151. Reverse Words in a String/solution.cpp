class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp;
        string ans;
        int i = 0 ;
        int e = s.length() -1;
        // Remove the front and rear spaces from string
        while(s[i] == ' '){
            i++;
        }
        while(s[e] == ' '){
            e--;
        }

        // Push all the words in stack
        while( i <= e )
        {
            if(s[i] != ' '){
                temp.push_back(s[i]);
            }
            else if(s[i] == ' '){
                if(temp.length()){
                    st.push(temp);
                    temp.clear();
                } 
            }
            i++;
        }
        // Final word push
        if(temp.length())
        {
            st.push(temp);
            temp.clear();
        } 

        // Pop from stack and store in ans string
        while( ! st.empty() ){
            string top = st.top();
            for(auto i: top){
                ans.push_back(i);
            }
            ans.push_back(' ');
            st.pop();
        }

        // If end of ans string is space then pop it
        int end = ans.length() -1;
        while(ans[end] == ' '){
            ans.pop_back();
            end--;
        }
        return ans;
    }
};
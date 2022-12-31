/*
36 ms
11 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Stack
*/

/*
Approach:
We know that stack is LIFO data structure so we can use it to reverse any word
*/
class Solution {
public:
    string reverseWords(string s) {
        // For fast input - output
        ios_base:: sync_with_stdio(false);
        cin.tie(nullptr);
        
        // Step 1: Creating important dataStructures
        string ans;
        stack<char> st;
        
        // Step 2: Traversing string till we reach its end
        for(int i = 0 ; i < s.length() ;i++){
            // If space is not found continue pushing word in stack
            if(s[i] != ' '){
                st.push(s[i]);
                continue;
            }
            // While stack is not empty pop out each element from stack and push it in ans string
            while(!st.empty()){
                char ch = st.top();
                ans.push_back(ch);
                st.pop();
            }
            // As word is complete push ' ' in answer
            ans.push_back(' ');
        }
        
        //Step 3: For last word repeat the same process of poping and storing from stack
        while(!st.empty()){
                char ch = st.top();
                ans.push_back(ch);
                st.pop();
            }
        return ans;
    }
};
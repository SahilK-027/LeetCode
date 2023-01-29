/*
196 ms
48.5 MB
*/

/**
 * TC: O(N)
 * SC: O(N)
 */

/**
 * @author : SahilK-027
 * @brief :  Bottom-up DP
*/

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // Storing unique words
        unordered_set<string> st;
        for(string i:words){
            st.insert(i);
        }
        
        // Store result
        vector<string>res;
        
        for(string word:words){
            // Get length of word
            int n=word.length();
            // Initialize DP
            vector<int>dp(n+1,0);
            // We have traversed the first character
            dp[0]=1;

            for(int i=0;i<n;i++){
                // If not traversed yetr
                if(dp[i] == 0)
                    continue;
                for(int j=i+1;j<=n;j++){
                    if(j-i<n && st.count(word.substr(i,j-i)))
                    dp[j]=1;
                }
                if(dp[n] != 0)
                {
                    res.push_back(word);
                    break;
                }
            }  
        }
        return res;
    }
};
/*
Runtime : 0 ms
Memory : 6.3 MB

TC: O(max(M, N))
SC: O(1)
*/

/**
 * @author : Sahilk-027
 * @brief : iteration
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i = 0;
        int j = 0;
        while(i < word1.length() && j < word2.length()){
            ans.push_back(word1[i]);
            ans.push_back(word2[j]);
            i++;
            j++;
        }
        while(i < word1.length() ){
            ans.push_back(word1[i]);
            i++;
        }
        while(j < word2.length() ){
            ans.push_back(word2[j]);
            j++;
        }
        return ans;
    }
};
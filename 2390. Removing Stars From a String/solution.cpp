/*
Runtime : 81 ms
Memory : 24.1 MB

TC: O(N)
SC: O(1)
*/

/**
 * @author : Sahilk-027
 * @brief : Iteration 
 */

class Solution {
public:
    string removeStars(string s) {
        int j = 0;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '*') j--;
            else  s[j++] = s[i];
        }           
        return s.substr(0, j);
    }
};
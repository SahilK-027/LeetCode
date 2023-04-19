/*
Runtime : 242 ms
Memory : 44.6 MB

TC: O(N)
SC: O(N)
*/

/**
 * @author : Sahilk-027
 * @brief : Hashing 
 */

class Solution {
public:
    int partitionString(string s) {
        int cnt =0;
        int i = 0;
        unordered_map<char, int>mp;
        while(i < s.size()){
            while(i < s.size() && mp[s[i]] == 0){
                mp[s[i]] = 1;
                i++;
            }
            mp.clear();
            cnt++;
        }
        return cnt;
    }
};
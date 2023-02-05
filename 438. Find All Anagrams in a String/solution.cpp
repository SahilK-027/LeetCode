/*
11 ms
8.8 MB
*/

/**
 * TC: O(26 * N)
 * SC: O(N)
 */

/**
 * @author : SahilK-027
 * @brief :  Hashing 
*/

class Solution {
private:
    bool areEqual(vector<int>&sCount, vector<int>&pCount){
        for(int i = 0; i < 26; i++){
            if(sCount[i] != pCount[i]) return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        if(m > n) return vector<int>();

        // Constructs maps
        vector<int>sCount(26,0);
        vector<int>pCount(26,0);

        // Set up map for p string
        for(int i= 0 ; i < m ; i++){
            pCount[p[i]-'a']++;
        }

        // Check if window matches or not using two pointers
        int i = 0; 
        int j = 0;
        vector<int> ans;
        while(j < n){
            sCount[s[j] - 'a']++;
            // When reaches the window size check if map sizes re equal or not
            if(j - i + 1 == m){
                if(areEqual(sCount, pCount)){
                    ans.push_back(i);
                }
            }
            if(j - i + 1 < m){
                j++;
            }
            else{
                sCount[s[i]-'a']--;
                i++;
                j++;
            }
        }
        return ans;
    }
};
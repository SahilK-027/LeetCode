/*
3 ms
9.7 MB
*/

/**
 * TC: O(N)
 * SC: O(N)
 */

/**
 * @author : SahilK-027
 * @brief :  Hashing
*/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // One word will always be sorted
        if(words.size() == 1) return true;
        //  We'll create a map to store order of character and it's index
        unordered_map<char, int>mp;
        for(int i = 0 ; i < order.length(); i++){
            mp[order[i]] = i;
        }
        // Now we'll traverse the words array
        int i = 0;
        int j = 1;
        while( j < words.size()){
            int n = words[i].length(); 
            int m = words[j].length(); 
            // Starting letters are equal
            if(mp[words[i][0]] == mp[words[j][0]]){
                int x = 0, y = 0;
                // while they are equal increament x and y
                while(x < n && y < m && mp[words[i][x]] == mp[words[j][y]]){
                    x++;
                    y++;
                }
                // Once they are unequal check the order
                if(x < n && y < m && mp[words[i][x]] > mp[words[j][y]]){
                    return false;
                }
                // If x < n && y == m means second word was smaller than first 
                // ex hello and hell order so we will return false
                else if(x < n && y == m){
                    return false;
                }
            }
            // Start letter are unqual check zeroth letter and move on
            else{
                if(mp[words[i][0]] > mp[words[j][0]]){
                    return false;
                }
            }    
            i++;
            j++;
        }
        return true;
    }
};
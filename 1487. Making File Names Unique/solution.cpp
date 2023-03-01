/*
198 ms
58.4 MB
*/

/**
 * TC: O(n)
 * SC: O(n)
*/

/**
 * @author : SahilK-027
 * @brief : Hashing
*/

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        // Fast i/o
        cin.tie(0);
        ios_base::sync_with_stdio(0);
        // Map to store string and its count
        unordered_map<string, int>mp;
        for(int i = 0 ; i < names.size(); i++){
            // If the string is repeated
            if(mp.find(names[i]) != mp.end()){
                // Find out number of times it is repeated
                int x = mp[names[i]];
                // While the current file lies in directory x++;
                while(mp.find(names[i]+"("+to_string(x)+")")!=mp.end()){
                    x++;
                    mp[names[i]]++;
                }
                // Change the file name
                mp[names[i]]++;
                names[i] = (names[i]+ "(" + to_string(x) + ")");
            }
            // Now for names[i] string there will be only one entry in our map
            mp[names[i]] = 1;
        }
        return names;
    }
};
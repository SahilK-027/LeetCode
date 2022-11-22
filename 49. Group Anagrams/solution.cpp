class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        // To return ans
        vector<vector<string> > ans;
        // To store all the strings having same chars
        unordered_map<string, vector<string> > mp;
        
        // Traverse the given string
        for(int i = 0 ; i < s.size(); i++){
            // Store current string
            string curr = s[i];
            // Sort the ith string of array
            // ⚠ WARNING : DON'T SORT CURRENT AS WE NEED IT TO PUSH IN STRING
            sort(s[i].begin(), s[i].end());
            // The string cont same characters after sorting will be equla so they will get stored for same key which is nothing but sorted current string
            mp[s[i]].push_back(curr);
        }

        // Push back all the vector<string> in ans
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
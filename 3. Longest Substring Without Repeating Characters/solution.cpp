class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // This map will store the character and index when we have lastly seen it
        unordered_map<char,int> map;
        
        // Point to left most element
        int l = 0;
        // Point to right most element
        int r = 0;
        int ans = 0;
        // We will only be moving r pointer and based on it we will be moving l
        while(r < s.length()){
            // If element already exists in map means element is repeated
            if(map.find(s[r]) != map.end()){
                // Update left
                l = max(map[s[r]]+1, l);
            }
            
            // Now update where we have seen the current elemnt last time
            map[s[r]] = r;
            // Ans will be max of original ans and r-l+1
            ans = max(ans, r - l +1);
            r++;
        }
        return ans;
    }
};

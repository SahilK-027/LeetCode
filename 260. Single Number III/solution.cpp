/*
11 ms
10.7 MB
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
    vector<int> singleNumber(vector<int>& arr) {
        if(arr.size() == 2) return arr;
        vector<int> ans;
        unordered_map<int, int>mp;
        for(auto i: arr){
            mp[i]++;
        }
        for(auto i: mp){
            if(i.second == 1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
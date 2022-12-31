/*
279 ms
66.8 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Set
*/

//Using set as it stores only unique numbers
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(int i = 0 ;i<nums.size();i++){
            set.emplace(nums[i]);
        }
        return (set.size()!=nums.size());
    }
};
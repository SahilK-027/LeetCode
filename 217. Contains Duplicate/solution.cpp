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
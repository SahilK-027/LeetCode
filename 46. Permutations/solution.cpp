/*
Runtime: 4 ms
Memory Usage: 7.6 MB
*/
//Using c++ stl next_permutation Function
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        do{
            ans.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return ans;
    }
};

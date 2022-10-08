// Runtime: 12 ms
// Memory Usage: 16.8 MB

class Solution {
private:
    void solution(vector<int> nums,vector<vector<int>> &powerset,vector<int> subset, int i){
        //Base case
        if(i>=nums.size()){
            powerset.push_back(subset); //Storing all the subsets to powerset
            return;
        }
        //Exclude
        solution(nums,powerset,subset,i+1);
        
        //Include
        int element = nums[i]; //Store the number in subset
        subset.push_back(element);
        solution(nums,powerset,subset,i+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int start_index = 0;
        vector<vector<int>> powerset;
        vector<int> subset;
        solution(nums,powerset,subset,start_index);
        return powerset;
    }
};

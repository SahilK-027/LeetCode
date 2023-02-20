/*
8 ms
13.5 MB

TC: O(Log N)
SC: O(1)

@author: SahilK-027
@breif: Upperbound lowerbound
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      // To store answer
        vector<int> ans;
        if(binary_search(nums.begin(), nums.end(), target)){
          // If element is present 
          // Return its lower bound index and upperbound index
            ans.push_back(lower_bound(nums.begin(), nums.end(), target) - nums.begin());
          // As upperbound will point to next greater element we have subtracted 1
            ans.push_back(upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1);
        }
        else{
          // element not found
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};

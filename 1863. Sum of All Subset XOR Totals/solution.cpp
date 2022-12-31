/*
158 ms
54.2 MB

TC : O(2^N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution + BT
*/

// APPROACH
/*
1. Find all subsets 
2. Find EX-OR
*/
class Solution {
private:
    void solve(vector<int>& arr, vector<vector<int>>& subsets, vector<int> curr_subset, int i =0){
        if(i == arr.size()){
            subsets.push_back(curr_subset);
            return;
        }
        // Include
        curr_subset.push_back(arr[i]);
        solve(arr, subsets,curr_subset, i+1);
        // Backtrack
        curr_subset.pop_back();
        // Exclude
        solve(arr, subsets,curr_subset, i+1);
    }
public:
    int subsetXORSum(vector<int>& arr) {
        // Step 1:
        vector<vector<int>> subsets;
        vector<int> curr_subset;
        solve(arr,subsets,curr_subset);

        // Step 2:
        int grand_total = 0;
        for(auto i: subsets){
            int curr_total = 0;
            for(auto j: i){
                curr_total =  (curr_total ^ j);
            }
            grand_total += curr_total;
        }
        return grand_total;
    }
};
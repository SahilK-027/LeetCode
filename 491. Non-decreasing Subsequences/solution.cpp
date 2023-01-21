/*
275 ms
116.2 MB
*/

/*
TC: O(2^n)
SC: O(n)
*/

/**
 * @author : SahilK-027
 * @brief :  Recursion
*/

// Optimization in isIncreasing function
// Pick - notpick logic
// Recursion
class Solution {
private:
    void solve(vector<int>& arr, vector<int> temp, set<vector<int>>& temp_ans, int prev, int curr){
        if(curr >= arr.size()){
            if(temp.size() >= 2)
                temp_ans.emplace(temp);
            return;
        }
        // Pick
        if(prev == -1 || arr[curr] >= arr[prev])
        {
            temp.push_back(arr[curr]);
            solve(arr, temp, temp_ans, curr, curr+1);
            temp.pop_back();
        }
        // Not pick
        solve(arr, temp, temp_ans, prev, curr+1);
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& arr) {
        // Fast i/o
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        // We want unique Subsequences array so first use set
        int prev = -1; 
        int curr = 0;
        vector<int> temp;
        set<vector<int>> temp_ans;
        solve(arr, temp, temp_ans, prev, curr);

        // After getting answers use vect<vect>
        vector<vector<int>> ans;
        for(auto i: temp_ans){
            ans.push_back(i);
        }
        return ans;
    }
};
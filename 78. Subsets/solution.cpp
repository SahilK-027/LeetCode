/*
0 ms
7.1 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursion + BACKTRACKING 
*/


// Space wise as well as time wise optimal solution using backtracking
class Solution {
private:
    void solve(vector<int>& arr, vector<vector<int>>& ans, vector<int>& temp, int i = 0){
        if(i == arr.size()){
            ans.push_back(temp);
            return;
        } 
        // Include
        temp.push_back(arr[i]);
        solve(arr, ans, temp, i+1);
        // Back Tracking
        temp.pop_back();


        // Exclude
        solve(arr, ans, temp, i+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(arr, ans, temp);
        return ans;
    }
};

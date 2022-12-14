/**
 * TLE
 */


/**
 * @author : Sahilk-027
 * @brief : Recursion (Inclusion - Exclusion) Logic
*/

/*
⚠️ This solution will require optimization else it will give TLE but its added here to understand how solution looked before optimization.
*/

class Solution {
private:
    int solve(vector<int>& arr, int s, int e){
        // Base case
        if(s > e){
            return 0;
        }
        // Rob current house so that you can rob next to next house
        int include = arr[s] + solve(arr, s+2, e);
        // Leave current house so that you can rob next house
        int exclude = solve(arr, s+1, e);
        // Return max of these two answers
        return max(include, exclude);
    }
public:
    int rob(vector<int>& arr) {
        int s = 0;
        int e = arr.size()-1;
        return solve(arr, s, e);
    }
};
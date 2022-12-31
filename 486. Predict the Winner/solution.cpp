/*
263 ms
7.5 MB

TC : O(2^N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution
*/

class Solution {
private:
    int solve(vector<int>& arr, int i, int j){
        // Array size is exceeded
        if(i > j){
            return 0;
        }
        // Both pointers are standing on a same element
        if(i == j){
            return arr[i];
        }
        // Calculate option 1 for player 1 : When p1 selects arr[i]
        // Calculate option 2 for player 1 : When p1 selects arr[j]
        int op1 = arr[i] + min(solve(arr, i+2, j), solve(arr, i+1, j-1));
        int op2 = arr[j] + min(solve(arr, i+1, j-1), solve(arr, i, j-2));
        return max(op1, op2);
    }
public:
    bool PredictTheWinner(vector<int>& arr) {
        // Finding total score
        int total_score = 0 ;
        for(int i = 0 ; i < arr.size() ; i++){
            total_score += arr[i];
        }
        // Calculate score for p1
        int p1_score = solve(arr,0, arr.size()-1);
        int p2_score = total_score - p1_score;
        // Return
        return p1_score >= p2_score;
    }
};
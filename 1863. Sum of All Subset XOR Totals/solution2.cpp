/*
4 ms
7 MB

TC : O(2^N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution
*/

class Solution {
private:
    void solve(vector<int>& arr, int& grand_total, int xorAns, int i =0){
        if(i == arr.size()){
            grand_total += xorAns;
            return;
        }
        // Include
        solve(arr, grand_total,xorAns ^ arr[i], i+1);
        // Exclude
        solve(arr, grand_total,xorAns, i+1);
    }
public:
    int subsetXORSum(vector<int>& arr) {
        // Step 1:
        int grand_total = 0;
        int xorAns = 0;
        solve(arr,grand_total,xorAns);
        return grand_total;
    }
};

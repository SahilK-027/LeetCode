/*
8 ms
18 mb
*/

/**
 * @author : Sahilk-027
 * @brief : Iteration
*/

// Find sum_1 of n (here n will be size of arr) natural numbers 
// Find sum_2 of all elements in array
// Return sum_1 - sum_2

/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        // Fast i/o
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int n = arr.size();

        // Find sum of first n natural numbers
        int sum_1 = 0 ;
        for(int i = 0 ; i <= n ; i++){
            sum_1 += i;
        }

        // Find sum of all numbers in array
        int sum_2 = 0;
        for(int i = 0 ; i < n ;i++){
            sum_2 += arr[i];
        }
        return sum_1 - sum_2;
    }
};

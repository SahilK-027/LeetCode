/*
15 ms
13.9 MB

TC : O(N LOG N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Prefix_sum
*/

/*
1. Sort the arr as we want to take maximum no. of elements
2. Compute prefix_sum
3. Find upper bound of a particular element in queries from prefix sum
*/
class Solution {
public:
    vector<int> answerQueries(vector<int>& arr, vector<int>& q) {
        // Step 1:
        sort(arr.begin(), arr.end());

        // Step 2:
        vector<int>sum(arr.size(), 0);
        sum[0] = arr[0];
        int total = arr[0];
        for(int i = 1; i < arr.size(); i++){
            total += arr[i];
            sum[i] = total;
        }

        //Step 3:
        vector<int> ans;
        for(auto i: q){
            int num = upper_bound(sum.begin(), sum.end(), i) - sum.begin();
            ans.push_back(num);
        }
        return ans;
    }
};
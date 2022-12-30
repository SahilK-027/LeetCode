/*
19 ms
13 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Dynamic Programming
*/

/*
The array may contain duplicate elements. So our first task will be keep count of each and every element from array and then remove the duplicates. For this purpose we'll Sort array.
*/
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // Edge case
        if(nums.size() == 1) return nums[0];
        // Craeting map to keep count
        unordered_map<int, int> mp;
        for(int i = 0 ; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        // Sorting array to remove duplicated
        sort(nums.begin(), nums.end());
        // Unique elements will be stored in arr
        vector<int> arr;
        int curr = nums[0];
        arr.push_back(curr);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == curr){
                continue;
            }
            else{
                curr = nums[i];
                arr.push_back(curr);
            }
        }
        // Edge case
        if(arr.size() == 1) return arr[0] * mp[arr[0]];
        
        // Initializing DP
        /*
        Explaination
        EX :
        arr = 2, 3, 5, 7
        dp[0] = arr[0] * No of occurences of arr[0]
        dp[1] : if prev element is equal to curr - 1
                dp = max (prev_1, prev_2 + curr)      
                
                else{
                    dp = dp[prev_1] + curr
                }  
        */
        vector<int> dp(arr.size(), -1);
        int one_prev = arr[0];
        int two_prev = -1;
        dp[0] = arr[0] * mp[arr[0]];
        if(one_prev == arr[1] - 1){
            dp[1] = max(dp[0], arr[1] * mp[arr[1]]);
        }
        else{
            dp[1] = dp[0] + arr[1] * mp[arr[1]];
        }
        for(int i = 2; i < arr.size(); i++){
            one_prev = i - 1;
            two_prev = i - 2;
            if(arr[one_prev] == arr[i] - 1){
                dp[i] = max(dp[one_prev], dp[two_prev] + arr[i] * mp[arr[i]]);
            }
            else{
                dp[i] = dp[one_prev] + arr[i] * mp[arr[i]];
            }
        }
        
        // Finding max : Max will be stored at last index of dp
        return dp[dp.size()-1];
    }
};
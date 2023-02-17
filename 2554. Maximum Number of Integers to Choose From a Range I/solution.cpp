/*
549 ms
203.3 MB
*/
/**
 * TC: O(n)
 * SC: O(n)
*/
/**
 * @author : SahilK-027
 * @brief : Hashing
 */

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int, int>mp;
        // Find out which number is banned
        for(auto i: banned){
            mp[i]++;
        }
        int cnt = 0;
        int sum = 0;
        for(int i = 1 ; i <= n; i++){
            // For those numbers which are not banned 
            // Check their sum is less than max sum or not
            // If yes increase the counter
            if(!mp[i]){
                sum += i;
                if(sum <= maxSum){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
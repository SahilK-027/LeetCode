/*
0 ms
6 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Hashmap
*/

class Solution {
public:
    int countDigits(int num) {
        // Map to store digit and its count
        unordered_map<int, int>mp;
        int n = num;
        while(n>0){
            int temp = n%10;
            n /= 10;
            // Store digit in map
            mp[temp]++;
        }
        int ans = 0;
        // Dry dividing num by i.first
        // If able to divide store in ans its count
        for(auto i: mp){
            if(num % i.first == 0){
                ans += i.second;
            }
        }
        return ans;
    }
};
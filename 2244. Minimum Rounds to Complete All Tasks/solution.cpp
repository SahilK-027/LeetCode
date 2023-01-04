/*
231 ms
103.7 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Hash map
*/

class Solution {
private:
public:
    int minimumRounds(vector<int>& tasks) {
        // Fast i/0
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        // To store answer
        int ans = 0;
        // Declare map to store number and its count
        unordered_map<int, int>mp;
        // Store number and its count
        for(auto i: tasks){
            mp[i]++;
        }
        // Traverse map
        for(auto i: mp){
            // If any element appears only ones return -1
            if(i.second < 2){
                return -1;
            }
            // If number is divisible by 3
            // Answer will be number / 3
            // EX. If 1 occurs 6 times then min number of rounds will be 6 /3
            else if(i.second % 3 == 0){
                ans += i.second / 3;
            }
            // If number is not divisible by 3
            // Answer will be number / 3 + 1
            // Ex. If 1 occurs 4 times then min number of rounds will be 4 / 3 + 1
            // Ex2. If 1 occurs 5 times then min number of rounds will again be 4 / 3 + 1
            else{
                ans += i.second / 3 + 1;
            }
        }
        return ans;
    }
};
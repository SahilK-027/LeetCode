/*
8 ms
16.6 MB

TC : O(n)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Two ptr approach
*/

class Solution {
public:
    int jump(vector<int>& arr) {
        cin.tie(0);
        ios_base::sync_with_stdio(0);
        // Two ptr
        int i = 0;
        int j = 0;
        int n = arr.size();
        int cnt = 0;
        // Till we reach the last index
        while(j < n-1){
            int max_reachable_index = INT_MIN;
            for(int k = i; k <= j ; k++){
                // We will just need to check how far can we max jump from one particular point
                max_reachable_index = max(max_reachable_index, k + arr[k]);
            }
            i = j + 1;
            j = max_reachable_index;
            cnt += 1;
        }
        return cnt;
    }
};
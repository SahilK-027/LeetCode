/*
4 ms
10.2MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Iteration
*/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg_count = 0;
        bool zero_present = false;
        for(auto i: nums){
            if(i < 0){
                neg_count++;
            }
            if(i == 0){
                zero_present = true;
                break;
            }
        }
        if(zero_present) return 0;
        if(neg_count & 1) return -1;
        return 1;
    }
};
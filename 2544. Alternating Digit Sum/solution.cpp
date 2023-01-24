/*
0 ms
6 MB
*/

/**
 * TC: O(N)
 * SC: O(1)
 */

/**
 * @author : SahilK-027
 * @brief :  Iterative
*/

class Solution {
public:
    int alternateDigitSum(int n) {
        int temp = n;
        int cnt = 0;
        vector<int> nums;
        while(temp > 0){
            int digit = temp % 10;
            nums.push_back(digit);
            temp /= 10;
            cnt++;
        }
        int round = 1;
        int ans = 0;
        if(cnt % 2 == 0){
            for(auto i: nums){
                if(round % 2 != 0){
                    ans += -1 * i;
                }
                else{
                    ans +=  i;
                }
                round++;
            }
        }
        else{
            for(auto i: nums){
                if(round % 2 == 0){
                    ans += -1 * i;
                }
                else{
                    ans +=  i;
                }
                round++;
            }
        }
        return ans;
    }
};
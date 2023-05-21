/*
83 ms
12.4 MB

TC : O(N * N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : ITERATION
*/

class Solution{
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0, sum, cnt;
        for(auto &num: nums) {
            sum = 0;
            cnt = 0;
            for(int j=1; j*j<=num; j++) {
                if (num%j==0) {
                    if (num/j == j) {
                        sum += j;
                        cnt++;
                    } 
                    else {
                        sum += j + (num/j);
                        cnt += 2;
                    }
                }
            }
            if (cnt == 4) ans += sum;
        }
        return ans;
    }
};
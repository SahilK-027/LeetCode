/*
16 ms
15.7 MB

TC : O(N )
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief :  Iteration
*/

class Solution {
private:
    void calculate(int& ds, int num){
        while(num){
            int digit = num % 10;
            ds += digit;
            num /= 10;
        }
    }
public:
    int differenceOfSum(vector<int>& nums) {
        int num_sum = 0;
        for(auto i: nums){
            num_sum += i;
        }
        int digit_sum =0;
        for(int i =0 ; i< nums.size(); i++){
            calculate(digit_sum, nums[i]);
        }
        
        return abs(num_sum-digit_sum);
    }
};
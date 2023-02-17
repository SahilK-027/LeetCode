/*
7 ms
9.2 MB
*/
/**
 * TC: O(N)
 * SC: O(1)
*/
/**
 * @author : SahilK-027
 * @brief : String to integer
 */

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        long long sum = 0;
        while( i < j){
            // Int to string to concat
            string n1 = to_string(nums[i]);
            string n2 = to_string(nums[j]);
            string ans = n1 + n2;
            // String to int after concat
            int ans_num = stoi(ans);
            sum += ans_num;
            i++;
            j--;
        }
        // Odd sized array
        if(i == j){
            sum += nums[i];
        }
        return sum;
    }
};
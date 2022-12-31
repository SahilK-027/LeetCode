/*
4 ms
8.5 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Similar to add two arrays
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int sum=0;
        int carry = 0;
        int final_sum=0;
        int last_index = digits.size()-1;
        if(digits[last_index]!=9){
            digits[last_index] += 1;
            return digits;
        }
        else{
            for(int i = last_index; i >=0;i--){
                if(i==last_index){
                    sum = digits[last_index]+1;
                    carry = sum/10;
                    final_sum = sum%10;
                    ans.push_back(final_sum);
                }
                else{
                    sum = digits[i]+carry;
                    carry = sum/10;
                    final_sum = sum%10;
                    ans.push_back(final_sum);
                }
            }
            if(carry){
                ans.push_back(carry);
            }
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};

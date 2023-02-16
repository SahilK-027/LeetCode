/*
1620 ms
27.3 MB
*/
/**
 * TC: O(n)
 * SC: O(1)
*/
/**
 * @author : SahilK-027
 * @brief : In place
 */

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& arr, int k) {
        // Addition begins from last index
        reverse(arr.begin(), arr.end());
        int n = arr.size();
        int i = 0;
        int carry = 0;
        // While index is in bound or we have number to add
        while(i < n){
            int total_sum = 0;
            int final_sum = 0;
            total_sum += carry;
            // If there is new element in array to add
            if(i < n){
                total_sum += arr[0];
            }
            // If there is number to add
            if(k){
                int last_digit = k % 10;
                total_sum += last_digit;
                cout<<k<<endl;
                k /= 10;
            }
            final_sum = total_sum % 10;
            carry = total_sum / 10;
            arr.push_back(final_sum);
            arr.erase(arr.begin());
            i++;
        }
        // If we have final carry
        while(carry)
        {
            int last_digit = k % 10;
            int sum = carry + last_digit;
            arr.push_back(sum % 10);
            carry = sum / 10;
            k /= 10;
        }
        // If we have k left
        while(k){
            int last_digit = k % 10;
            arr.push_back(last_digit);
            k /= 10;
        }
        reverse(arr.begin(), arr.end());
        return arr;
    }
};
/*
Runtime : 4 ms
Memory : 6.1 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : Sahilk-027
 * @brief : Iteration
*/

class Solution {
private: 
    int solve(vector<int> arr, int index){
        int maxi = INT_MIN;
        int maxi_i = index;
        for(int i = index; i < arr.size(); i++){
            if(arr[i] >= maxi){
                maxi = arr[i];
                maxi_i = i;
            }
        }
        return maxi_i;
    }
public:
    int maximumSwap(int num) {
        vector<int> arr;
        while(num > 0){
            int l_digit = num % 10;
            num /= 10;
            arr.push_back(l_digit);
        }
        reverse(arr.begin(), arr.end());
        vector<int> arr2 = arr;
        for(int i = 0 ; i < arr.size(); i++){
            int temp = solve(arr, i);
            swap(arr[i], arr[temp]);
            if(arr2 != arr){
                break;
            }
        }

        int sum = 0;
        for(auto i: arr){
            sum = sum * 10 + i;
        }
        return sum;
    }
};
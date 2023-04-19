/*
Runtime : 33 ms
Memory : 25.2 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : Sahilk-027
 * @brief : PrefixSum
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        vector<int>ans(arr.size());
        vector<int> pre(arr.size(), 1);
        vector<int> post(arr.size(), 1);
        for(int i = 1; i < arr.size(); i++){
            pre[i] = arr[i-1] * pre[i-1];
        }
        for(int i = arr.size()-2; i >=0 ; i--){
            post[i] = arr[i+1] * post[i+1];
        }
        for(int i = 0; i < arr.size(); i++){
            ans[i] =  pre[i]  * post[i];
        }
        return ans;
    }
};
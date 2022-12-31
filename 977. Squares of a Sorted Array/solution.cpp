/*
39 ms
25.9 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Two pointers
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        int s = 0;
        int e = arr.size()-1;
        int k = arr.size()-1;
        vector<int> ans(k+1);
        while(s <= e){
            if(abs(arr[s]) > abs(arr[e])){
                ans[k--] = arr[s]*arr[s];
                s++;
            }
            else {
                ans[k--] = arr[e]*arr[e];
                e--;
            }
        }
        return ans;
    }
};
/*
Runtime : 85 ms
Memory : 42 MB

TC : O(N log N)
SC : O(1)
*/

/**
 * @author : Sahilk-027
 * @brief : Sorting
*/

class Solution {
public:
    int numRescueBoats(vector<int>& arr, int key) {
        sort(arr.begin(), arr.end(), greater<int>());
        int i = 0;
        int j = arr.size() - 1;
        int ans = 0;
        while(i <= j){
            if(arr[i] + arr[j] <= key){
                i++;
                j--;
            }
            else{
               i++;
            }
            ans++;
        }
        return ans;
    }
};
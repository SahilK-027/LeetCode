/*
Runtime : 950 ms
Memory : 90.5 MB

TC : O(N log N)
SC : O(N)
*/

/**
 * @author : Sahilk-027
 * @brief : DP with BS
*/

class Solution {
private:
    static bool comparator(vector<int>&a, vector<int>&b){
        // If 0th element are equal then sort on basis of second in descending order
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        // Otherwise sort in ascending order
        return a[0] < b[0];
    }
    int DP_with_BinarySearch(vector<int>& arr){
        if(arr.size() == 0) return 0;
        vector<int> ans;
        ans.push_back(arr[0]);
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] > ans.back()){
                ans.push_back(arr[i]);
            }
            else{
                int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[index] = arr[i];
            }
        }
        return ans.size();
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort
        sort(envelopes.begin(), envelopes.end(), comparator);
        // Apply DP_with_BinarySearch on second element in each row
        vector<int>arr;
        for(auto i: envelopes){
            cout<<i[0]<<" "<<i[1]<<endl;
            arr.push_back(i[1]);
        }
        return DP_with_BinarySearch(arr);
    }
};
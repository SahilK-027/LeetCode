/*
40 ms
19.1 MB
*/
/**
 * TC: O(N log N)
 * SC: O(N)
*/
/**
 * @author : SahilK-027
 * @brief : Sorting
 */


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int curr = 0;
        for(int i = 1; i < intervals.size(); ++i){
            curr = ans.size()-1;
            if(ans[curr][1] >= intervals[i][0]){
                ans[curr][1] = max(ans[curr][1], intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
/*
18 ms
11.2 MB
*/
/**
 * TC: O(n)
 * SC: O(n)
*/
/**
 * @author : SahilK-027
 * @brief : Iterative
 */

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int i = 0 ; 
        int j = 0;
        while(i < nums1.size() && j < nums2.size()){
            // Same ids
            vector<int> temp;
            if(nums1[i][0] == nums2[j][0]){
                temp.push_back(nums1[i][0]);
                temp.push_back(nums1[i][1] + nums2[j][1]);
                ans.push_back(temp);
                i++;
                j++;
            }
            // Different ids
            else if(nums1[i][0] < nums2[j][0]){
                temp.push_back(nums1[i][0]);
                temp.push_back(nums1[i][1]);
                ans.push_back(temp);
                i++;
            }
            else{
                temp.push_back(nums2[j][0]);
                temp.push_back(nums2[j][1]);
                ans.push_back(temp);
                j++;
            }
        }
        
        while(i < nums1.size()){
            vector<int> temp;
            temp.push_back(nums1[i][0]);
            temp.push_back(nums1[i][1]);
            ans.push_back(temp);
            i++;
        }
        while(j < nums2.size()){
            vector<int> temp;
            temp.push_back(nums2[j][0]);
            temp.push_back(nums2[j][1]);
            ans.push_back(temp);
            j++;
        }
        return ans;
    }
};
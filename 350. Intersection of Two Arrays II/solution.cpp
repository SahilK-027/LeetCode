/*
7 ms
10.8 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Map
*/


class Solution {
private:
    void fill_map(unordered_map<int, int>&mp, vector<int>& arr){
        for(auto i: arr){
            mp[i]++;
        }
    }
    vector<int> find_intersection(unordered_map<int, int>&mp1, unordered_map<int, int>&mp2){
        vector<int> ans;
        for(auto i: mp1){
            if(mp2.find(i.first) != mp2.end()){
                int appearance_one = i.second;
                int appearance_two = mp2[i.first];
                int appearance_cnt = min(appearance_one, appearance_two);
                while(appearance_cnt--){
                    ans.push_back(i.first);
                } 
            }
        }
           
        return ans;
    }
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int, int>mp1;
        unordered_map<int, int>mp2;
        fill_map(mp1, nums1);
        fill_map(mp2, nums2);
        return find_intersection(mp1, mp2);
    }
};
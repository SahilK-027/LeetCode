// Runtime: 8 ms
// Memory Usage: 9.2 MB
/*
8 ms
9.2 MB

TC : O((m+n) log(m+n))
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Two pointers
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        while(i<nums1.size() && j< n){
            if(nums1[i]<=nums2[j] && i!=m){
                i++;
            }
            if(nums1[i]> nums2[j] && i!=m)
            {
                for(int x = m-1;x>=i;--x){
                    nums1[x+1] = nums1[x];
                }
                nums1[i]=nums2[j];
                i++;
                j++;
                m++;
            }
            if(i==m){
                while(j<n){
                    nums1[i]=nums2[j];
                    i++;
                    j++;
                }
            }
        }
    }
};

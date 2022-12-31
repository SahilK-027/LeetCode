/*
63 ms
90 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Binary Search
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //1. Merging two sorted arrays in third array
        vector<int> nums3;
        int i,j,k;
        i=j=k=0;
        while(i<nums1.size() && j< nums2.size()){
            if(nums1[i]<=nums2[j]){
                nums3.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i]> nums2[j]){
                nums3.push_back(nums2[j]);
                j++;
            }
            k++;
        }
        if(i<nums1.size()){
            while(i<nums1.size()){
                nums3.push_back(nums1[i]);
                i++;
            }
        }
        if(j< nums2.size()){
            while(j<nums2.size()){
                nums3.push_back(nums2[j]);
                j++;
            }
        }
        
        //2. Finding median;
        double median = 0;
        int s=0;
        int e = nums3.size() - 1;
        int m = s + (e-s)/2;
        if(nums3.size()%2==0){ // Even length array
            median = (nums3[m]+nums3[m+1])/2.0;
        }
        else{ //Odd length array
            median = nums3[m];
        }
        return median;
    }
};

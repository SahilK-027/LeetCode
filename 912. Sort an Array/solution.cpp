/*
413 ms
142.7 MB
*/

/**
 * TC: O(n log n)
 * SC: O(n)
*/

/**
 * @author : SahilK-027
 * @brief : Merge sort
*/

class Solution {
private:
   void merge(vector<int>& arr,int s, int e)
   {
        int m = s + (e-s)/2;
        int first_arr_length = m-s+1;
        int sec_arr_length = e-m;
        //Creating two new arrays
        int *first_arr = new int[first_arr_length];
        int *sec_arr = new int[first_arr_length];
        //Copying values in new arrays
        int k =s;
        for(int i =0 ;i<first_arr_length ;i++)
            first_arr[i] = arr[k++];
        k = m+1;
        for(int i =0 ;i<sec_arr_length ;i++)
            sec_arr[i] = arr[k++];
    
        //Merge two sorted arrays
        int i = 0;
        int j = 0;
        k = s;
        while(i<first_arr_length && j<sec_arr_length){
            if(first_arr[i] <= sec_arr[j])
                arr[k++]=first_arr[i++];
            else if(first_arr[i] > sec_arr[j])
                arr[k++]=sec_arr[j++];
        }
        if(i<first_arr_length){
            while(i<first_arr_length){
                arr[k++]=first_arr[i++];
            }
        }
        if(j<sec_arr_length){
            while(j<sec_arr_length){
                arr[k++]=sec_arr[j++];
            }
        }

    }
    void mergeSort(vector<int>& arr, int s, int e){
        //BC
        if(s>=e){
            return;
        }
        int m= s + (e-s)/2;
        //RC
        mergeSort(arr,s,m);
        mergeSort(arr,m+1,e);

        //P
        merge(arr,s,e);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        mergeSort(nums, s, e);
        return nums;
    }
};
class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        // EDGE CASES
        int n =  arr.size()-1; // Last index
        if(arr.size() == 1) return 0; // single element
        if(arr[0] > arr[1]) return 0;
        if(arr[n] > arr[n-1]) return n;


        // Start binary search
        int s = 1 ;
        int e = arr.size() - 2;
        int m = s + (e-s)/2;
        while(s <= e){
            // If we found peak element break out of loop
            if(arr[m] > arr[m -1] && arr[m] > arr[m+1]){
                break;
            }

            // If mth element is less than its prev then possible answer might exist in left
            else if ( arr[m] < arr[m -1] ){
                e = m -1;
            }

            // If mth element is less than its next then possible answer might exist in right
            else if (arr[m] < arr[m +1]){
                s = m + 1;
            }
            m = s + (e-s)/2;
        }

        // Rerturning ans
        return m;
    }
};
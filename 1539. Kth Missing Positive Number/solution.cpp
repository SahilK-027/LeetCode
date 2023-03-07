/*
6 ms
9.7 MB
*/

/**
 * TC: O(log n)
 * SC: O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Binary search
*/

class Solution {
private: 
    int solve(int a, int b){
        return a - b;
    }
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int s = 0;
        int e = arr.size() - 1;
        int m = s + (e-s)/2;
        int missing_nos = solve(arr[n-1], n);
        while(s <= e){
            missing_nos = solve(arr[m], m+1);
            if(missing_nos >= k){
                e = m - 1;
            }
            else{
                s = m + 1;
            }
            m = s + (e-s)/2;
        }
        if(e == -1){
            return k;
        }
        return arr[e] + k - solve(arr[e], e+1);
    }
};
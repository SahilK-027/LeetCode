/*
78 ms
25 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Math
*/

/*
LOGIC:
1. REVERSE FIRST N-K
2. REVERSE LATS K
3. REVERSE WHOLE ARRAY
*/

class Solution {
private:
    void reverse(vector<int>& arr, int s, int e){
        while(s<e){
            swap(arr[s],arr[e]);
            s++;
            e--;
        }
    }
public:
    void rotate(vector<int>& arr, int k) { 
        int n = arr.size();
        if(k == n){
            return;
        }
        k = k % n;
        //Step 1
        reverse(arr,0,n-k-1);
        //Step 2
        reverse(arr,n-k,n-1);
        //Step 3
        reverse(arr,0,n-1);
    }
};
/*
6 ms
10.8 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Looping
*/

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int i = 0;
        int j = 0;
        int cnt = 0;
        while( j < arr.size()){
            while(j < arr.size() && arr[i] == arr[j]){
                cnt++;
                if(cnt > 2){
                    arr[j] = INT_MIN;
                }
                j++;
            }
            if( j < arr.size() && arr[i] != arr[j]){
                i = j;
                cnt = 0;
            }
        }
        cnt = 0;
        for(auto i: arr){
            if(i != INT_MIN){
                cnt++;
            }
        }
        int ptr1 = 0;
        int ptr2 = 0;

        for(int i = 0 ;i<arr.size() ; i++){
            if(arr[i] == INT_MIN){
                ptr1 = i;
                ptr2 = i+1;
                break;
            }
        }
        
        while(ptr2 < arr.size()){
            if(arr[ptr2] != INT_MIN){
                arr[ptr1] = arr[ptr2];
                ptr1++;
                ptr2++;
            }
            else{
                ptr2++;
            }
        }

        return cnt;
    }
};
/*
65 ms
48.5 MB

TC : O(n)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Greedy
*/

class Solution {
public:
    bool canJump(vector<int>& arr) {

        // Size of aray is 1 so we are already at last index 
        if(arr.size()==1) return true;
        // If first element of array is 0 so we canot make any jump
        if(arr[0] == 0) return false;

        int n = arr.size()-1;
        int i = n;
        for(i ; i > 0; i--){
            if(arr[i-1] == 0){
                continue;
            }
            if(i - 1 + arr[i-1] >= n){
                // If we are able to jump from curr index to last index means now we dont need to check for last index all we need to check is for current index
                n = i-1;
            }
        }
        // If finally from index 0 we are able to jump to the nth index answer will be true
        cout<<arr[i]<<"->"<<n<<endl;
        if( arr[i] >= n){
            return true;
        }
        return false;
    }
};

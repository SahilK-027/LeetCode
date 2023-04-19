/*
Runtime : 141 ms
Memory : 74.5 MB

TC: O(N)
SC: O(1)
*/

/**
 * @author : Sahilk-027
 * @brief : Math
*/

#define ll long long
class Solution {
public:
    int chalkReplacer(vector<int>& arr, int k) {
        ll sum = 0;
        for(auto i: arr){
            sum += i;
        }
        cout<<sum<<endl;
        ll rem = k % sum;
        cout<<rem;
        for(int i = 0; i < arr.size() ; i++){
            rem -= arr[i];
            if(rem < 0){
                return i;
            }
        }
        return -1;
    }
};
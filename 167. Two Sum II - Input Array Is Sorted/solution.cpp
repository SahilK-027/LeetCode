/*
38 ms
15.6 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Two pointer
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int t) {
        vector<int> ans;
        int s = 0;
        int e = arr.size()-1;
        while(s<e){
            if(arr[s] + arr[e] == t){
                // As for question indexing starts from 1
                ans.push_back(s+1);
                ans.push_back(e+1);
                break;
            }
            else if(arr[s] + arr[e] < t){
                s++;
            }
            else{
                e--;
            }
        }
        return ans;
    }
};
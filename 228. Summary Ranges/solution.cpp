/*
4 ms
6.8 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Iteration
*/


class Solution {
public:
    vector<string> summaryRanges(vector<int>& arr) {
        int n = arr.size(); 
        vector<string> ans;
        string temp = "";
        for(int i = 0; i < n; i++) 
        {
            int j = i; 
            while(j + 1 < n && arr[j + 1] == arr[j] + 1)
                j++;
            if(j > i){
                temp += to_string(arr[i]);
                temp += "->"; 
                temp += to_string(arr[j]);
            }
            else
                temp += to_string(arr[i]); 
            ans.push_back(temp); 
            temp = "";
            i = j;
        }
        return ans;
    }
};
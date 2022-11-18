// O(n2) solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> res;
        // We are sorting so that all same elements will come in one sequence
        sort(arr.begin(), arr.end());
        for(int i = 0 ; i < arr.size(); i++)
        {
            int curr = arr[i];
            // We don't want repeated elements 
            if(i>0 && curr == arr[i-1]){
                continue;
            }
            // If element is unique perform two sum for remaining aray
            else{
                int left = i+1;
                int right =  arr.size()-1;
                while(left < right){
                    int threeSum = curr + arr[left] + arr[right];
                    // If resulting sum is greater than 0 we need to decrease it so right-- as array is sorted
                    if(threeSum > 0){
                        right--;
                    }
                    // If resulting sum is lesser than 0 we need to increase it so left++ as array is sorted
                    else if(threeSum < 0){
                        left++;
                    }
                    // Ifr sum is 0 then push it to answer and check for next possible ans
                    else{
                        vector<int> ans;
                        ans.push_back(curr);
                        ans.push_back(arr[left]);
                        ans.push_back(arr[right]);
                        res.push_back(ans);
                        left++;
                        while(arr[left] == arr[left -1] && left < right){
                            left++;
                        }
                    }
                }
            }
        }
        return res;
    }
};
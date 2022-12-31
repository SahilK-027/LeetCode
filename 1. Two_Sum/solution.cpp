/*
8 ms
11 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : HashMap
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        //to store the ans   
        vector<int> ans;
        
        // Creating hash map
        unordered_map<int,int> map; 
        for(int i=0;i<nums.size();i++)
        {
            int key = target - nums[i];     //Key is to be find 
            
 // If key is not find, find() will return the address of last index we dont want that, we want to execute this statements only when key is find.
            if(map.find(key) != map.end()) 
            {
                //Updating ans
                ans.push_back(map[key]);  
                ans.push_back(i);                 
                
                // No need to check further because Only 1 valid answer exists.
                break;
            }
            
            
// If break is not excuted means elemnt not found so store the ans in map
            map.emplace(nums[i],i); 
        }
        return ans;
    }
};

/*
Runtime: 11 ms
Memory Usage: 18.5 MB
*/

/*
Approach :
Step 1: Take two ptr one for unique element and other for duplicates
Step 2: If at ptr2 you get same element as at ptr1 Make that element as INT_MIN
Step 3: Find out count of unique elements
Step 4: Find the first INT_MIN element  
Step 5: Replace all INT_MIN with unique elements
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Fast io
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        // Case for only one element in array
        if(nums.size() == 1){
            return 1;
        }
        
        //Step 1:
        int cnt = 0;
        int ptr1 = 0;
        int ptr2 = 1;
        
        //Step 2:
        while(ptr2<nums.size()){
            if(nums[ptr1] == nums[ptr2]){
                nums[ptr2] = INT_MIN;
               
            }
            else{
                ptr1 = ptr2;
            }
            ptr2++;
        }
        
        // Step 3:
        for(int i = 0 ; i< nums.size(); i++){
            if(nums[i] != INT_MIN){
                cnt++;
            }
        }
        
        // Step 4:
        for(int i = 0 ;i<nums.size() ; i++){
            if(nums[i] == INT_MIN){
                ptr1 = i;
                ptr2 = i+1;
                break;
            }
        }
        
        //Step 5:
        while(ptr2 < nums.size()){
            if(nums[ptr2] != INT_MIN){
                nums[ptr1] = nums[ptr2];
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

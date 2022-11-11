class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        //declaring array for storing -1 at a particular index
        int arr[nums.size()+1];
        
        //initializing array with 0
        for(int i=0;i<nums.size();i++){
            arr[i]=0;
        }
        
        //Delaring temp vcector for storing repeated numbers
        vector<int> temp;
        for(int i=0;i<nums.size();i++)
        {
            if(arr[nums.at(i)]==-1) //if arr[num]==-1 : number already exists so it is duplicate
            {
                temp.push_back(nums[i]);
            }
            else    //if number does not exists then number is appearing for first time.
            {
                arr[nums.at(i)]=-1;
            }
        }
       return temp;
    }
};
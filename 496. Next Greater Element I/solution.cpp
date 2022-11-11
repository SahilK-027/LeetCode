class Solution {
private:
    int findGreater(stack<int> &s, int num, int &ans){
        // Base case
        if(s.top() == num){
            return -1;
        }
        
        // Store and remove top of stack
        int ele = s.top();
        s.pop();
        if(ele > num){
            ans = ele;
        }
        // Goining in stack using recursive call
        findGreater(s, num, ans);

        // While coming back find ans and restore the top
        s.push(ele);
        return ans;
    }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        // Step 1: Store all the nums2 element in stack
        stack<int> s;
        for(int i = 0; i<nums2.size() ;i++){
            s.push(nums2[i]);
        }
        
        // Step 2: For each element in nums1 find greater number above it in stack
        for(int i = 0; i<nums1.size(); i++){
            int ansNum = -1;
            int gNum = findGreater(s,nums1[i],ansNum);
            ans.push_back(gNum);
        }
        
        //Return ans
        return ans;
    }
};
class Solution {
public:
    bool solve(vector<int>& qty,map<int,int>& mp, int i ) {
        //base case
        if(i >= qty.size()) {
            // if we have traversed quantity comp,etely means all customers are statisfied
            return true;
        }
        
        for(auto it: mp) {
            if(mp[it.first] >= qty[i]) {
                
                mp[it.first] -= qty[i];
                
                bool recAns = solve(qty, mp, i+1);
                if(recAns == true){
                    return true;
                }
                else{
                    // Back track
                    mp[it.first] += qty[i];
                }    
            }
        }
      return false;  
    }
    
    bool canDistribute(vector<int>& arr, vector<int>& qty) {
        // Step 1: To store numand its count
        map<int,int> mp;
        for(int i=0; i<arr.size(); i++) {
            mp[arr[i]]++;
        }
        //step2: sort quantity desc
        sort(qty.begin(), qty.end(), greater<int>());
        
        return solve(qty, mp, 0);
    }
};

/*
Runtime : 72 ms
Memory : 21.6 MB

TC: O(N * N)
SC: O(N * N)
*/

/**
 * @author : Sahilk-027
 * @brief : Dynamic Programming
*/

class Solution {
private:
    bool isValid(vector<int> a,vector<int> b){
        // Condition : You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj.
        if(b[0] <= a[0] 
            &&
           b[1] <= a[1] 
            &&
           b[2] <= a[2] 
        ){
            return true;
        }
        else{
            return false;
        }
    }
    int solve(vector<vector<int>>& nums){
        int n = nums.size();
        vector<int> current(n+1, 0);
        vector<int> next(n+1, 0);

        for(int curr = n-1 ; curr >= 0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){
                // Include 
                int include = 0;
                if(prev == -1 || isValid( nums[curr] , nums[prev])){
                    include = nums[curr][2] + next[curr+1];
                }
                // Exclude
                int exclude = 0 + next[prev+1];

                //  Prev can be -1 as well so make prev + 1 
                current[prev+1] =  max(include, exclude);
            }
            next = current;
        }
        return next[0];
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        // Fast I/O
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        // Sorting all the dimentions so that height will be at last index
        for(int i = 0 ; i < cuboids.size();i++){
            sort(cuboids[i].begin(), cuboids[i].end());
        }
        // Sorting all the cuboids
        sort(cuboids.begin(), cuboids.end());
        return solve(cuboids);
    }
};
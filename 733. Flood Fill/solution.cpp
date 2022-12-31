/*
7 ms
14.1 MB

TC : O(M * N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution
*/

class Solution {
private:
    void solve(vector<vector<int>>& image, int sr, int sc,int old_color, int new_color, int& rows, int& cols){
        // Checking for out of bound values
        if(sr < 0 || sr >= rows || sc < 0 || sc >=cols){
            return;
        }
        // If color is already updated then return 
        if(image[sr][sc] != old_color ){
            return;
        }
        // Change the old color to new color
        image[sr][sc] = new_color;
        // Call recursion to solve 4 -connected cells
        
        // TOP
        solve(image, sr-1, sc, old_color, new_color, rows, cols);
        // RIGHT
        solve(image, sr, sc+1, old_color, new_color, rows, cols);
        // BOTTOM
        solve(image, sr+1, sc, old_color, new_color, rows, cols);
        // LEFT
        solve(image, sr, sc-1, old_color, new_color, rows, cols);  
        
        return;
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int new_color) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        // Step 1: Finding old color
        int old_color = image[sr][sc];
        
        // Step 2: If new and old colors are same no need to update
        if(new_color == old_color){
            return image;
        }
        
        int rows = image.size();
        int cols = image[0].size();
        // Step 3: Call solve function to solve given matrix recursively 
        solve(image, sr,sc, old_color, new_color, rows, cols);
        
        return image;
    }
};
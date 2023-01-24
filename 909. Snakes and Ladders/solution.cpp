/*
44 ms
12.5 MB
*/

/**
 * TC: O(N* N)
 * SC: O(N)
 */

/**
 * @author : SahilK-027
 * @brief :  BFS
*/

class Solution {
    void getCoordinate(int n,int s, int &row, int &col){
        row = n-1-(s-1)/n;
        col = (s-1)%n;
        if((n%2==1 && row%2==1)||(n%2==0 && row%2==0)) col = n-1-col;
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        //  build visited array
        vector<bool> visited(n*n+1,false);
        // We are already standing at position 1 
		visited[1] = true;
        // BFS
        queue<pair<int,int>> q;
		q.push({1,0});
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int row,col;
            int src = p.first, dist = p.second;
            // Reached the destination
            if(src == n*n)
                return dist;
            // Else try out all moves from source
            for(int i=1; src+i <=n*n && i<=6;i++){                
                getCoordinate(n,src+i,row,col);
                // check for snake or ladder and update source accordingly
                int src_final = 0;
                // If no snake or latter
                if(board[row][col]==-1){
                    src_final = src+i;
                }
                // If snake or ladder
                else{
                    src_final = board[row][col];
                }
                if(!visited[src_final]){
                    visited[src_final] = true;
                    q.push({src_final,dist+1});
                }                
            }
        }
        return -1;
    }
};
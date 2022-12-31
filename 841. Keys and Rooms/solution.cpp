/*
7 ms
10.4 MB

TC : O(N+E)
SC : O(N) 
*/

/**
 * @author : SahilK-027
 * @brief : Breadth First Search
*/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        // Initially we can visit room 0
        visited[0] = true;
        queue<int> q;
        q.push(0);
        // BFS
        while(!q.empty()){
            int top = q.front();
            q.pop();

            for(auto i: rooms[top]){
               if(visited[i] == 0){
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
        
        // Checking if we are able to traverse all the rooms or not
        for(auto i: visited){
            if(i == false){
                return false;
            }
        }
        return true;
    }
};
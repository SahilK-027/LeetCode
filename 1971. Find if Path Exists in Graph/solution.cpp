/*
535 ms
150.9 MB

TC: O(N^2)
SC: O(N^2)
*/

/**
 * @author : SahilK-027
 * @brief : Breadth First Search
*/

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        vector<vector<int>> graph(n);
        // Build the graph
        for(int i=0; i<edges.size(); i++) {
            int index1 = edges[i][0];
            int index2 = edges[i][1];
            graph[index1].push_back(index2);
            graph[index2].push_back(index1);
        }
        
        // Breadth first search
        queue<int> q;
        vector<int> visited(n, 0);
        q.push(s);
        // Visited array
        visited[s] = 1;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            if(top == d) return true;
            for(int i=0; i<graph[top].size(); i++){
                if(visited[graph[top][i]] == 0){
                    q.push(graph[top][i]);
                    visited[graph[top][i]] = 1;
                }
            }
        }
        return false;
    }
};
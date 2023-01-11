/*
337 ms
81.2 mb

TC : O(N + m)
SC : O(N + m)
*/

/**
 * @author : SahilK-027
 * @brief :  Recursive DFS
*/

class Solution {
private:
    int  DFS(unordered_map<int, vector<int>>& adj_list, unordered_map<int, bool>& visited, vector<bool>& hasApple, int node){
        // Ifitially the count will be zero
        int cnt = 0;
        // DOING DFS
        visited[node] = true;
        for(auto i: adj_list[node]){
            if(!visited[i]){
                visited[i] = true;
                int childCnt = DFS(adj_list, visited, hasApple, i);
                // If current node has apple or childern has apple then total cnt will get add by 2 + childcount
                if(hasApple[i] || childCnt != 0){
                    cnt += 2 + childCnt;
                }
            }
        }
        return cnt;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // Constructing adj_list
        unordered_map<int, vector<int>>adj_list;
        for(auto i: edges){
            adj_list[i[0]].push_back(i[1]);
            adj_list[i[1]].push_back(i[0]);
        }
        // DFS
        unordered_map<int, bool>visited;
        return DFS(adj_list, visited, hasApple, 0);
    }
};
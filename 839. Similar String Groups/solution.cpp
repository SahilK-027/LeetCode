/*
369 ms
107 MB

TC : O(V + E)
SC : O(V + E)
*/

/**
 * @author : SahilK-027
 * @brief : DFS
*/

class Solution{
private:
    // is Similar means number of misplaced chars will be either 0 or 2
    bool is_similar(string a, string b){
        int count = 0;
        for (int i = 0; i < a.length(); i++){
            if (a[i] != b[i]) count++;
        }
        return (count == 2 || count == 0);
    }
    void dfs(int i, vector<string> &strs, vector<bool> &visited){
        // Perform BFS
        visited[i] = true;
        for (int j = 0; j < strs.size(); j++){
            if (visited[j])
                continue;
            // if strings are similar then perform DFS for the similar atring
            if (is_similar(strs[i], strs[j])){
                dfs(j, strs, visited);
            }
        }
    }
public:
    int numSimilarGroups(vector<string> &strs){
        // Initially the number of groups will be 0
        int groups = 0;
        int n = strs.size();
        // For dfs we'll create a visited aray
        vector<bool> visited(n, false);
        for (int i = 0; i < strs.size(); i++){
            // // If node is not visited, new group will be formed
            if (!visited[i]){
                groups++;
                dfs(i, strs, visited);
            }
        }
        return groups;
    }
};
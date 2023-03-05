/*
500 ms
159.2 MB
*/

/**
 * TC: O(n * n)
 * SC: O(n)
*/

/**
 * @author : SahilK-027
 * @brief : Breadth First Search
*/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        // Fast i/o
        cin.tie(0);
        ios_base::sync_with_stdio(0);
        // Map to store element and its index
        unordered_map<int, list<int>>mp;
        for(int i= 0 ; i < arr.size(); i++){
            mp[arr[i]].push_back(i);
        }
        // Queue for BFS
        queue<int>q;
        vector<bool>visited(arr.size(), false);
        // Starting at zeroth index
        q.push(0);
        visited[0] = true;
        int ans = 0;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                int vertex = q.front();
                q.pop();
                //  If we are standing at last position return ans
                if(vertex == arr.size()-1){
                    return ans;
                }
                // In one step you can jump from index i to index:

                // i + 1 where: i + 1 < arr.length.
                // i - 1 where: i - 1 >= 0.
                // j where: arr[i] == arr[j] and i != j.
                list<int> adj_list = mp[arr[vertex]];
                adj_list.push_back(vertex - 1);
                adj_list.push_back(vertex + 1);
                for(auto j: adj_list){
                    if(j >= 0 && j < arr.size() && !visited[j]){
                        q.push(j);
                        visited[j] = true;
                    }
                }
                // To stop performing repeated calculations for input like
                // [11,22,7,7,7,7,7,7,7,22,13]
                mp[arr[vertex]].clear();
            }
            ans++;
        }
        return ans;
    }
};
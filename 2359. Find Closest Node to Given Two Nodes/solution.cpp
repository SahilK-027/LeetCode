/*
1457 ms
301.2 MB
*/

/**
 * TC: O(N)
 * SC: O(N)
 */

/**
 * @author : SahilK-027
 * @brief :  DFS
*/

// Map the distance of all reachable nodes from node1 and node1 ... 
// Find common nodes which are reachable from both node1 and node2
// Finding max distace from common node
// Find min of all this max distance

class Solution {
private:
    void DFS(int node, unordered_map<int, list<int>>& adj_list, vector<bool>&visited, unordered_map<int, int>& dist, int curr_dist){
        // Save the distance of current node 
        dist[node] = curr_dist;
        // Mark it visited
        visited[node] = true;
        for(auto i: adj_list[node]){
            // If node is not -1 and is not already visited then visit it and increase the current distance
            if(i != -1 && !visited[i]){
                DFS(i, adj_list, visited, dist, curr_dist+1);
            }
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        // Building adjcency list
        unordered_map<int, list<int>> adj_list;
        for(int i = 0 ; i < edges.size(); i++){
            adj_list[i].push_back(edges[i]);
        }
        // DFS Taversal for node 1 and node 2;
        vector<bool>visited1(edges.size(), false);
        vector<bool>visited2(edges.size(), false);
        // This map will store distances of all nodes reachable from node1
        unordered_map<int, int> dist1;
        DFS(node1, adj_list, visited1, dist1, 0);
         // This map will store distances of all nodes reachable from node2
        unordered_map<int, int> dist2;
        DFS(node2, adj_list, visited2, dist2, 0);

        // Init variables
        int min_distance = INT_MAX;
        int possible_ans = INT_MAX;
        for(auto i: dist1){
            // If current element is there in dist2
            if(dist2.find(i.first) != dist2.end()){
                // Find max distance as max of dist1->val and dist2->val
                int distance = max(dist1[i.first], dist2[i.first]);
                // If current max is minimum update minimum and store answer as current node
                if(distance < min_distance){
                    min_distance = distance;
                    possible_ans = i.first;
                    
                }
                // If there are multiple answers, return the node with the smallest index
                else if(distance == min_distance){
                    if(i.first < possible_ans){
                        possible_ans = i.first;
                    }
                }
            }
        }
        // If no possible answer exists, return -1.
        return possible_ans == INT_MAX ? -1 : possible_ans;
    }
};
/*
24 ms
15.1 MB

TC : O(N+E)
SC : O(N+E)
*/

/**
 * @author : SahilK-027
 * @brief : Kahn's algorithm (Topological sort)
*/

/*
# Approach
Algorithm: 
- Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the graph.
- Step-2: Pick all the vertices with in-degree as 0 and add them into a queue.
- Step-3: Remove a vertex from the queue (Dequeue operation) and then. 
    - Increment the count of visited nodes by 1.
    - Decrease in-degree by 1 for all its neighbouring nodes.
    - If the in-degree of neighbouring nodes is reduced to zero, then add it to the queue.

- Step 4: Repeat Step 3 until the queue is empty.
- Step 5: If the count of visited nodes is not equal to the number of nodes in the graph then the topological sort is not possible for the given graph so there is cycle present in graph.
*/


// The logic is there should be no cycle in given directed graph 
// numCouses     -> No. of vertices
// prerequisites -> Edges
// Cycle detection in directed graph using Kahn's algorithm 

class Solution {
private:
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        // Fast i/o
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        // Edge case
        if(edges.size() == 0) return true;
        // Create Adj_list for directed graph
        unordered_map<int, vector<int>>adj_list;
        for(auto i: edges){
            adj_list[i[0]].push_back(i[1]);
        }
        // Step 1: Find indegree of all nodes
        vector<int>indegree(n);
        for(auto i: adj_list){
            for(auto j: i.second){
                indegree[j]++;
            }
        }
        // Step 2: Push element with 0 ingree in queue
        queue<int>q;
        for(int i = 0; i < indegree.size() ;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        // Step 3: Do BFS
        int cnt =0;
        while(!q.empty()){
            // Remove and store front
            int front = q.front();
            q.pop();
            cnt++;
            // Find all neightbours of front
            for(auto neighbour: adj_list[front]){
                // As front have been removed update their indegree
                indegree[neighbour] -= 1;
                // Push the neighbours with indegree 0 in queue
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        // if(cnt == n) => cycle not present
        // else cycle present
        return cnt == n;
    }
};
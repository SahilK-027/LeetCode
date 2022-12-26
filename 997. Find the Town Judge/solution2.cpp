/*
229 ms
70.4 MB

TC : O(n)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Degree count
*/

/*
APPROACH:
		- A node has outdegree == 0 => means that node doesnot trust anyone.
		- A node has indegree == n-1 => means all other nodes trusts this node except himself.
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Edge case
        if(trust.size() == 0 && n == 1) return 1;

        // Map to store indegree and outdegree of a node
		unordered_map<int,int> out_deg;
		unordered_map<int,int> in_deg;

		//loop counts indegree and outdegree of a node
		for(auto i : trust){
            out_deg[i[0]]++;
            in_deg[i[1]]++;
        }

		// Checking if judge
		for(int i=0;i<=n;i++){
            if(out_deg[i] == 0 && in_deg[i] == n-1) return i;
        }
        
		// Otherwise no judge
        return -1;
    }
};
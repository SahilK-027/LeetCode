/*
474 ms
122.8 MB

TC : O(V + E)
SC : O(V + E)
*/

/**
 * @author : SahilK-027
 * @brief : Topological sort + DFS
*/

class Solution {
private:
    void dfs(int i,vector<int>&v,vector<int>ad[]){
        v[i]=1;
        for(auto x:ad[i]){
            if(!v[x])
            dfs(x,v,ad);
        }
    }
    void topoSort(int i,stack<int>&s,vector<int>&vis,vector<int>ad[]){
        vis[i]=1;
        for(auto x:ad[i]){
            if(!vis[x])
            topoSort(x,s,vis,ad);
        }
        s.push(i);
    }
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        stack<int>s;
        vector<int>ad[n];
        for(auto i:edges){
            ad[i[0]].push_back(i[1]);
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i])topoSort(i,s,vis,ad);
        }
        vector<int>a;
        vector<int>v(n,0);
        while(s.size()){
            int x=s.top();
            s.pop();
            if(!v[x]){
                a.push_back(x);
                dfs(x,v,ad);
            }
        }
        return a;
    }
};
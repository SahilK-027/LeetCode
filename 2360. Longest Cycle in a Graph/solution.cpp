/*
Runtime : 281 ms
Memory : 131.8 MB

TC: O(V + E)
SC: O(V + E)
*/

/**
 * @author : Sahilk-027
 * @brief : DFS 
 */

class Solution {
private:
    
    void getcycle(vector<int> &edges,int si,vector<bool>& visit,vector<int>& store, int& maxLength){
        if(si == -1)return ;
        if(visit[si]){
            int count = -1;
            for(int i =0;i<store.size();i++){
                if(store[i]==si){
                    count = i;
                    break;
                } }
            
            if(count==-1)return;
            int size = (store.size()-count);
            maxLength = max(maxLength,size);
            return ;
        }
        visit[si] = true;
        store.push_back(si);
        getcycle(edges,edges[si],visit,store, maxLength);
        return ;
    }
public:
    int longestCycle(vector<int>& edges) {
        vector<bool> visit(edges.size(),0);
        int maxLength = -1;
        for(int i =0;i<edges.size();i++){
            if(visit[i])continue;
            vector<int> store;
            getcycle(edges,i,visit,store, maxLength);
        }
        return maxLength;
    }
};
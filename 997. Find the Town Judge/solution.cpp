/*
243 ms
75.3 MB

TC : O(n^2)
SC : O(n)
*/

/**
 * @author : SahilK-027
 * @brief : Simple directed graph
*/

// Trusts is nothing but the edges of directed graph
class Solution {
private:
    bool isPossible(int i, unordered_map<int, vector<int>> & adj){
        for(auto x: adj){
            if(x.first != i)
            {
                bool flag = false;
                for(auto j: x.second){
                    if(j == i){
                        flag = true;
                    }
                }
                if(!flag){
                    return false;
                }
            }
        }
        return true;
    }
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> possible_ans;
        // Store edges in adj list
        unordered_map<int, vector<int>> adj_list;
        // Create directed mapping in between nodes 
        for(auto i: trust){
            adj_list[i[0]].push_back(i[1]);
        }
        // If for a particular node the corresponding list has size 0 means there is no mapping implying this can be Town Judge 
        for(int i = 1; i <= n ; i++){
            if(adj_list[i].size() == 0){
                possible_ans.push_back(i);
            }
        }
        for(auto i: possible_ans){
            // Check if everyone trusts him or not
            if(isPossible(i, adj_list)){
                return i;
            }
        }
        // Else no town judge 
        return -1;
    }
};

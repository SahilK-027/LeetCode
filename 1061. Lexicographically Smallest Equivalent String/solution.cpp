/*
8 ms
8.1 MB

TC : O(N + m)
SC : O(N + m)
*/

/**
 * @author : SahilK-027
 * @brief :  Recursive DFS
*/

/*
1. Model equalities as edges of a graph.
2. Group each connected component of the graph and assign each node of this component to the node with the lowest lexicographically character.
3. Finally convert the string with the precalculated information.
*/
class Solution {
public:
      char dfs(unordered_map<char, vector<char>>& adj_list, char input, unordered_set<char>& visited) {
        if (visited.count(input) > 0) {
            return input;
        }
        visited.insert(input);
        char ch = input;
        for (const auto i : adj_list[input]) {
            ch = min(ch, dfs(adj_list, i, visited));
        }
        return ch;
    }
public:
    string smallestEquivalentString(string A, string B, string S) {
        // Creatimg Adj list
        unordered_map<char, vector<char>> adj_list;
        for (int i = 0; i < A.size(); ++i) {
            adj_list[A[i]].push_back(B[i]);
            adj_list[B[i]].push_back(A[i]);
        }
        string res;
        unordered_map<char, char> mp;
        for (const auto s : S) {
            if (mp.count(s) > 0) {
                res += mp[s];
                continue;
            }
            // DFS CALL
            unordered_set<char> visited;
            const auto min_char = dfs(adj_list, s, visited);
            for (const auto ch : visited) {
                mp[ch] = min_char;
            }
            // Append the lexological first char
            res += min_char;
        }
        return res;
    }
};
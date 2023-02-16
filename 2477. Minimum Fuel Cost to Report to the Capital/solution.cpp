/*
536 ms
191.4 MB
*/
/**
 * TC: O(V + E)
 * SC: O(V + E)
*/
/**
 * @author : SahilK-027
 * @brief : DFS
 */


class Solution {
 private:
  int dfs(const vector<vector<int>>& adj_list, int u, int prev, int seats,
          long long& ans) {
    int people = 1;
    for (const int v : adj_list[u]) {
      if (v == prev)
        continue;
      people += dfs(adj_list, v, u, seats, ans);
    }
    if (u > 0)
      ans += (people + seats - 1) / seats;
    return people;
  }
 public:
  long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    long long ans = 0;
    vector<vector<int>> adj_list(roads.size() + 1);

    for (const vector<int>& road : roads) {
      const int u = road[0];
      const int v = road[1];
      adj_list[u].push_back(v);
      adj_list[v].push_back(u);
    }
    dfs(adj_list, 0, -1, seats, ans);
    return ans;
  }
};
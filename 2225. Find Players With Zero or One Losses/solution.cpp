/*
Runtime : 771 ms
Memory : 192.6 MB

TC: O(N log N)
SC: O(N)
*/

/**
 * @author : Sahilk-027
 * @brief : Hashing + Sorting
*/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        unordered_map<int, int> winners, loosers;

        for(auto i: matches){
            winners[i[0]]++;
            loosers[i[1]]++;
        }

        vector<int> ans_not_lost, ans_one_lost;

        for(auto i: winners) if(loosers[i.first] == 0) ans_not_lost.push_back(i.first);
        for(auto i: loosers) if(i.second == 1) ans_one_lost.push_back(i.first);


        sort(ans_not_lost.begin(), ans_not_lost.end());
        sort(ans_one_lost.begin(), ans_one_lost.end());

        ans.push_back(ans_not_lost);
        ans.push_back(ans_one_lost);
        return ans;
    }
};
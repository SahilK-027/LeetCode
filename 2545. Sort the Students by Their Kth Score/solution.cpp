/*
101ms
37.9
*/

/*
TC: O(N^2)
SC: O(N)
*/

/**
 * @author : SahilK-027
 * @brief :  Iterative sort
*/

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        unordered_map<int, vector<int>>mp;
        for(int row = 0; row < score.size(); row++){
            for( int col = 0 ; col < score[row].size(); col++){
                mp[row].push_back(score[row][col]);
            }
        }
        map<int, int> temp;
        for(int row = 0; row < score.size(); row++){
            temp[score[row][k]] = row;
        }
        vector<vector<int>> ans;
        vector<vector<int>> res;
        for(auto i: temp){
            ans.push_back(mp[i.second]);
        }
        cout<<ans.size();
        for(int i = ans.size()-1; i >= 0; i--){
            vector<int>temp;
            for(int j = 0 ; j < ans[i].size(); j++){
                temp.push_back(ans[i][j]);
            }
            res.push_back(temp);
        }
        return res;
    }
    
};
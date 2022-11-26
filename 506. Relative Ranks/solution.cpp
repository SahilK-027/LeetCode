class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& arr) {
        vector<string> ans(arr.size(), "");
        vector<int> s;
        unordered_map<int, int>mp;
        for(auto i: arr){
            s.push_back(i);
        }
        sort(s.begin(), s.end());
        for(int i = 0 ; i < arr.size(); i++){
            mp[arr[i]] = i;
        }
        int cnt = 1;
        for(int i = s.size() - 1; i >= 0 ; i--){
            if(cnt == 1)
            {
                ans[mp[s[i]]] = "Gold Medal";
                cnt++;
            }
                
            else if(cnt == 2){
                ans[mp[s[i]]] = "Silver Medal";
                cnt++;
            }

            else if(cnt == 3){
                ans[mp[s[i]]] = "Bronze Medal";
                cnt++;
            }

            else{
                ans[mp[s[i]]] = to_string(cnt);
                cnt++;
            }
        }
        return ans;
    }
};
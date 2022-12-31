/*
39 ms
8.6 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Hashing
*/


class Solution {
public:
    string frequencySort(string s) {
        string ans;
        // To store number and its occurance
        unordered_map<char, int>mp;
        for(int i= 0 ; i < s.length(); i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = 1;
            }
            else{
                mp[s[i]]++;
            }
        }
        vector<pair<int,char>> v;
        for(auto i: mp){
            v.push_back(make_pair(i.second,i.first));
        }
        sort(v.begin(), v.end());
        for (int i= v.size()-1; i >= 0; i--)
        {
            while(v[i].first--){
                ans.push_back(v[i].second);
            }
        }
        return ans;
    }
};
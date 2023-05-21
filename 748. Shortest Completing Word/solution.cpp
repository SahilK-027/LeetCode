/*
49 ms
20.7 MB

TC : O(N * N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Hashing
*/

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        unordered_map<char, int>mp1;
        string ans = "";
        int curr_len = INT_MAX;
        for(auto i: licensePlate){
            mp1[tolower(i)]++;
        }
        for(auto i: words){
            unordered_map<char, int>mp2;
            for(int e = 0 ; e < i.size(); e++){
                mp2[i[e]]++;
            }
            bool flag = false;
            for(auto x: mp2){
                if(mp1.find(x.first) != mp1.end() &&  mp1[x.first] > x.second){
                    flag = true;
                }
            }
            for(auto w: mp1){
                if(int(w.first) >= 97 && int(w.first) <= 122){
                    if(mp2.find(w.first) == mp2.end()){
                        flag = true;
                    }
                }
            }
            if(!flag){
                if(i.size() < curr_len){
                    curr_len = i.length();
                    ans = i;
                }
            }
        }
        return ans;
    }
};
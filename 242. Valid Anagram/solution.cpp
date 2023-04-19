/*
Runtime : 13 ms
Memory : 7.2 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : Sahilk-027
 * @brief : Hashing
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mp1;
        map<char, int> mp2;
        for(auto i: s){
            mp1[i]++;
        }
        for(auto i: t){
            mp2[i]++;
        }
        if(mp1.size() != mp2.size()){
            return false;
        }
        for(auto i: mp1){
            if(mp2[i.first] != i.second){
                return false;
            }
        }
        return true;
    }
};
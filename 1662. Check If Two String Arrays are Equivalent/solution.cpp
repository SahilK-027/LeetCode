/*
Runtime : 3 ms
Memory : 11.6 MB

TC: O(N)
SC: O(1)
*/

/**
 * @author : Sahilk-027
 * @brief : Iterative
*/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "";
        string s2 = "";

        for(auto i: word1) s1 += i;
        for(auto i: word2) s2 += i;

        return s1 == s2;
    }
};
/*
269 ms
20.7 MB

TC : O(N log M)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Hashing + Mapping
*/

/// Intution : For answer to be true 
/*
1. Two strings must have same length
2. The number of occurences of each character must be unique and same in both strings
*/
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false;
        unordered_map<char, int>mp1;
        unordered_map<char, int>mp2;
        // For each character in strings store their count
        for(auto i: word1)
            mp1[i]++;
        for(auto i: word2)
            mp2[i]++;
        if(mp1.size() != mp2.size()) return false;
        for(auto i: mp1){
            if(mp2.find(i.first) == mp2.end()) return false;
        }
        // Extract count from both map and check if they are unique
        vector<int>arr1;
        vector<int>arr2;
        for(auto i: mp1){
            arr1.push_back(i.second);
        }
        for(auto i: mp2){
            arr2.push_back(i.second);
        }
        if(arr1.size() != arr2.size()) return false;
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int i = 0;
        int j = 0;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i++] != arr2[j++]) return false;
        }
        return true;
    }
};
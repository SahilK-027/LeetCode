/*
53 ms
23.1 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : SWAP TWO POINTERS
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start=0;
        int end=s.size()-1;
        while(start<=end){
            swap(s[start++],s[end--]);
        }
    }
};
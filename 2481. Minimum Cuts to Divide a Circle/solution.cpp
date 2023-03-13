/*
0 ms
6 MB
*/

/**
 * TC: O(1)
 * SC: O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Math
*/

class Solution {
public:
    int numberOfCuts(int n) {
        if(n==1) return 0;
        if(n & 1) return n;
        else return n/2;
    }
};
/*
0 ms
5.8 MB
*/

/**
 * TC: O(sqrt(n))
 * SC: O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Two pointers
*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i = 0;
        long long j = sqrt(c);
        while(i <= j){
            // If sum is equal to c return true
            if(i * i + j * j == c){
                return true;
            }
            // If value is greater then decrement j
            if(i * i + j * j > c){
                j--;
            }
            // Less value so increment i
            else {
                i++;
            }
        } 
        // Unable to find output
        return false;
    }
};
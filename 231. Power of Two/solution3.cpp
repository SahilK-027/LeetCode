/*
Runtime - 0ms
Memory - 6MB
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) {
            return false;
        }
        // since the numbers who are powers of 2 have atleast 1 true bit
        // we perform logical 'and' operation with the number and its previous one
        return ((n&(n-1)) == 0); 
    }
};

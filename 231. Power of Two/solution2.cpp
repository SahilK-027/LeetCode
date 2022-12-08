/*
Runtime - 4ms
Memory - 6MB
*/
class Solution {
public:
   bool isPowerOfTwo(int n) {
        return n>0 and !(n&(n-1));
    }
};

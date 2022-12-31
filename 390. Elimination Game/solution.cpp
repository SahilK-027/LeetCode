/*
15 ms ms
5.8 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution
*/

class Solution {
private:

public:
    int lastRemaining(int n) {
        // Base case
        if(n == 1){
            return 1;
        }
        // The whole logic goes behind making this recurrence relation
        return 2 * (1 + n /2 - lastRemaining(n / 2));
    }
};
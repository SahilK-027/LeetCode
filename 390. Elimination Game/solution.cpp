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
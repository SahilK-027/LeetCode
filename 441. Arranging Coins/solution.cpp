/*
4 ms
5.9 MB

TC : O(log N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Binary search
*/

class Solution {
public:
    int arrangeCoins(int n) {
        int s = 1;
        int e = n;
        double  m = s + (e - s)/2;
        while(s <= e){
            long long coins_used = m / 2 * (m + 1);
            if(coins_used == n){
                return (int)m;
            }
            else if( n < coins_used){
                e = m - 1;
            }
            else{
                s = m + 1;
            }
            m = s + (e - s)/2;
        }
        return e;
    }
};
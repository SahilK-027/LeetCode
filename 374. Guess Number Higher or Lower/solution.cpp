/*
2 ms
6.1 MB

TC : O(log N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Binary search
*/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

// Search space problem
class Solution {
public:
    int guessNumber(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int s = 0;
        int e = n;
        int m = 0;
        while(s<=e){
            m = s + (e - s) / 2;
            if(guess(m) == 0){
                break;
            }
            else if(guess(m) == -1){
                e = m - 1;
            }
            else if(guess(m) == 1){
                s = m + 1;
            }
        }
        return m;
    }
};
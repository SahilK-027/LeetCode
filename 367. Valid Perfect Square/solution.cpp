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
    bool isPerfectSquare(int num) {
        int s = 0;
        int e = num;
        long int m = s + (e-s)/2;
        while(s<=e){
            if(m * m == num){
                return true;
            }
            else if ( m * m > num){
                e = m -1;
            }
            else{
                s = m + 1;
            }
            m = s + (e-s)/2;
        }
        return false;
    }
};
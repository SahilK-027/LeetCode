/*
0 ms
5.8 MB

TC : O(log N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Binary search
*/
class Solution {
public:
    int binary_search(int x){
    int s = 0;
    int e = x;
    long int m = s + (e-s)/2;    //the value may exceed range of int
    int ans;
    while(s<=e){
        long long square = m*m;
        if((square)==x){        //the value may exceed range of int
            ans=m;
            break;
        }
        else if((square)>x){
            e=m-1;
        }
        else{
            ans=m;
            s=m+1;
        }
        m=s+(e-s)/2;
    }
    return ans;
}
    int mySqrt(int x) {
        return binary_search(x);
    }
};

/*
0 ms
5.9 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Bit manipulation
*/

class Solution {
public:
    int bitwiseComplement(int n) {
        int count=0;            //to maintain the count of bits in given number
        int copy =n;            //we are going to make changes in n
        int filter=0;
        if (copy==0){
           return 1;
        }
        while(copy!=0)
        {
          copy = copy>>1;//right shift it once until it does not become equal                           to 0
          count++;
        }
        for(int i=0;i<count;i++){
            filter = filter<< 1 | 1; //left shift filter and then OR it with 1                                       to add 1 to its right
        }
        int ans = (~n) & filter;
        return ans;
    }
};
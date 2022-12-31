/*
0 ms
5.9 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Math
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int set_bit_count=0;
        while(n!=0){
            int bit = n % 2;  //Convert the number to binary
            if(bit)
                set_bit_count++; //If bit == 1 count++
            n=n/2; //This can be done alternately using right shift operator x>>y = x/2y
        }
        return set_bit_count;
    }
};

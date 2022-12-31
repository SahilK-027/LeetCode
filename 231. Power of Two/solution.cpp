/*
3 ms
6 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Math
*/

/*
logic of counting number of set bits  
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0){
            return false;
        }
        int set_bit_count=0;
        while(n!=0){
            int bit = n % 2;  //Convert the number to binary
            if(bit)
                set_bit_count++; //If bit == 1 count++
            n=n/2;
        }
        if(set_bit_count == 1)
           return true;
        return false;
    }
};
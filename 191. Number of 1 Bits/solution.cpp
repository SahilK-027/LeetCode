class Solution {
public:
    int hammingWeight(uint32_t n) {
        int set_bit_count=0;
        while(n!=0){
            int bit = n % 2;  //Convert the number to binary
            if(bit)
                set_bit_count++; //If bit == 1 count++
            n=n/2;
        }
        return set_bit_count;
    }
};
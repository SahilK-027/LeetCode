/*
Runtime - 0ms
Memory - 6MB
*/
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {

        int count = 0;

        while (n != 0)
        {
            // Checking the last bit by using n&1 ie. it will give true(1) only when last bit is 1
            if (n & 1)
            {
                count++;
            }

            n = n >> 1; // This is right shift one digit !!!
        }

        return count;
    }
};

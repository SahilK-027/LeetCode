/*
16 ms
5.9 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Using the logic of reverse an integer
*/

class Solution {
public:
    bool isPalindrome(int x) {
        long long reverse_num = 0;
        int temp=x;
        if(x<0)
           return false;
        while(temp!=0)
        {
            reverse_num = reverse_num*10+temp % 10;
            temp=temp/10;
        }
        return (reverse_num == x);
    }
};

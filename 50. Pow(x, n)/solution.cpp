/*
3 ms
6.2 MB

TC : O(x^n/2)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Fast exponential 
*/

class Solution {
public:
    double myPow(double x, int n) {
    long long num = n;
    double partial_ans;  //Using recurtion
        
    if (x == 0)     // In pow(x,n) if x=0 ,ans=0
        return 0;
    if (num == 0)
        return 1;  // If power is zero ans is 1
    
    //Fast exponential method
    //If power is negative calculate for positive power ans and then return 1/ans
    if (num < 0)
    {
        long long b = -1 * num;
        if (b % 2 == 0) // Even
            partial_ans = pow(x, b / 2) * pow(x, b / 2);
        else
            partial_ans = x * pow(x, b / 2) * pow(x, b / 2);
        return 1/(partial_ans);
    }
    
    //Else power is positive or 0
    else
    {
        int b = num;
        if (b % 2 == 0) // Even
            partial_ans = pow(x, b / 2) * pow(x, b / 2);
        else
            partial_ans = x * pow(x, b / 2) * pow(x, b / 2);
    }
    return partial_ans;
    }
};

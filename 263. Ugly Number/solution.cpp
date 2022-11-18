class Solution {
private:
    bool checkPrimeFact(int &n){
        while (n % 2 == 0)
        {
            n = n/2;
        }
        // n must be odd at this point. So we can skip one element (Note i = i +2)
        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            // While i divides n, print i and divide n
            while (n % i == 0)
            {
                if(i > 5){
                    return false;
                }
                n = n/i;
            }
        }
 
        // This condition is to handle the case when n is a prime number greater than 2
        if (n > 2){
            if(n > 5){
                return false;
            }
        }
        return true;
    }
public:
    bool isUgly(int n) {
        if(n <= 0){
            return false;
        }
        return checkPrimeFact(n);
    }
};
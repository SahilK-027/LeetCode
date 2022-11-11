// Optimized Sieve of eractothenes

class Solution {
public:
    int countPrimes(int n) {
        int count = 0 ;
        if(n==0){
            return 0;
        }
        //Creating sieve
        vector<bool> sieve(n,true);
        sieve[0]=sieve[1]=false;
        for(int i = 2; i*i<n ; i++)
        {
            if(sieve[i] == true)
            {
                for(int j = i*i; j<n ; j+=i)
                {
                    sieve[j] = false;
                }
            }
        }
        
        //Counting if prime
        for(int i=2;i<n;i++){
            if(sieve[i] == true){
                count++;
            }
        }
        return count;
    }
};
/*
127 ms
17 MB

TC : O(sqrt(N))
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Segmented Sieve
*/

class Solution {
private:
    
    void createSieve(int N, vector<bool>& sieve){
        // Building Sieve of Eratosthenes 
        for(int i = 2; i * i <= N; i++){
            if(sieve[i] == true){
                for(int j = i * i; j <= N; j += i){
                    sieve[j] = false;
                }
            }
        }
    }
    
    // If sieve[i] == true means number is prime
    void generatePrimes(int num, vector<bool>& sieve, vector<int>& primes){
        for(int i = 2; i <= num; i++){
            if(sieve[i] == true){
                primes.push_back(i);
            }
        }
    }
public:
    vector<int> closestPrimes(int left, int right) {
        // Edge cases
        vector<int> ans;
        if(left == 1 && right == 1){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }  
        if(left == 1) left +=1;
        if(left == right){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }  

        // As given 1 <= left <= right <= 10^6 we will need to loop till sqrt(r) 
        // So at max the size of sieve will be required to be sqrt(10^6) = 10^3
        int N = 1000;
        vector<bool> sieve(N+1, true);
        sieve[0] = 0; // 0 is not prime
        sieve[1] = 0; // 1 is either prime nor composite

        // Step 1: Generate sieve for 0 to 1000
        createSieve(N, sieve);

        // Step 2: Generate all the primes till sqrt(right) and store it in vector 
        vector<int> primes;       
        generatePrimes(sqrt(right), sieve, primes);
        
        // Step 3: Creat an array of size right - left + 1 and initialize it with true
        vector<bool> arr(right - left + 1, true);
        
        // For all the prime numbers in primes array make its multiple false in array
        for(auto i : primes){
            int fm = (left / i) * i;
            if(fm < left) fm += i;
            for(int j = max(fm, i*i); j <= right; j += i){
                arr[j - left] = false;
            }
        }
        
        // Now you will get primes in range of left and right store it
        vector<int> prime_in_Range;
        for(int i = left; i <= right; i++){
            if(arr[i - left] == true){
                prime_in_Range.push_back(i);
            }
        }
        
        // If there exists only one prime in range return [-1,-1]
        if(prime_in_Range.size()==1){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        // Else iterate over prime_in_Range and store that pair which has the least difference 
        int i = 0;
        int j = 1;
        int diff = INT_MAX;
        while(j < prime_in_Range.size()){
            if(prime_in_Range[j] - prime_in_Range[i] < diff){
                ans.clear();
                ans.push_back(prime_in_Range[i]);
                ans.push_back(prime_in_Range[j]);
                diff = prime_in_Range[j] - prime_in_Range[i];
            }
            i++;
            j++;
        }

        // Return answer
        return ans;
    }
};
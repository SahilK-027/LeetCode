/*
86 ms
28.7 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Using set to store distinct prime factors
*/


// As the 2 <= nums[i] <= 1000 the product is going to be very large so insted of finding prime factors of poduct find prime factors of each number in i 
class Solution {
private:
    void primeFact(vector<int>& arr, unordered_set<int>& set){
        // Find prime factor of each element separately
        for (auto i: arr) 
        {
            int sq = sqrt(i);
            int j = 2;
            while(j <= sq)
            {
                if (i % j == 0) 
                {
                    // Found prime factor so store in nums
                    set.emplace(j);
                    while (i % j == 0) 
                    {
                        i/= j;
                    }
                }
                j++;
            }
            // As i > 1 there exists a lst prime factor
            if (i > 1)  set.emplace(i);
        }
    }
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int>set;
        primeFact(nums, set);
        return set.size();
    }
};
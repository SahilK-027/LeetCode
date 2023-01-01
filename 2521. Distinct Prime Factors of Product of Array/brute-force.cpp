/*
RUNTIME ERROR: signed integer overflow: 6273379750279824000 * 547 cannot be represented in type 'long long' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:27:15
*/

/**
 * @author : SahilK-027
 * @brief : Brute-force
*/


class Solution {
private:
    // Find prime factors and store in set as set contains only unique elements
    void primeFact(long long p, set<int>& set){
        int i = 2;
        while(p > 1)
        {
            if(p % i == 0){
                set.emplace(i);
                p/=i;
            }
            else i++;
        }
    }
public:
    int distinctPrimeFactors(vector<int>& nums) {
        // Calculate the product of all numbers in nums
        long long p = 1;
        for(auto i: nums){
            p *= i;
        }
        set<int>set;
        primeFact(p, set);
        // Number of distinct prime factors will be size of set
        return set.size();
    }
};
/*
0 ms
6 MB

TC : O(N log N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Sorting
*/

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;
        for(int i = 1 ; i * i <= n; i++){
            if(n % i == 0){
                factors.push_back(i);
                if(n / i != i){
                    factors.push_back(n / i);
                }
            }
        }
        sort(factors.begin(), factors.end());
        return factors.size() >= k ? *(factors.begin() + (k - 1)) : -1;
    }
};